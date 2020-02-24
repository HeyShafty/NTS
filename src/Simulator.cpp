/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Simulator
*/

#include <iostream>
#include <signal.h>
#include "Exceptions/CircuitFileException.hpp"
#include "IComponent.hpp"
#include "Simulator.hpp"
#include "Factory.hpp"

const std::map<std::string, int (nts::Simulator::*)(void) const> nts::Simulator::functionnalitiesMap = {
    {"display", &nts::Simulator::displayOutputs},
    {"exit", &nts::Simulator::exitSimulation},
    {"simulate", &nts::Simulator::simulate},
    {"loop", &nts::Simulator::loop},
    {"dump", &nts::Simulator::dump}
};

bool nts::Simulator::isLooping = true;

nts::Simulator::Simulator()
{}

nts::IComponent *nts::Simulator::findComponent(std::string toFind) const
{
    auto found = this->outputComponents.find(toFind);

    if (found != this->outputComponents.end())
        return found->second.get();
    found = this->inputComponents.find(toFind);
    if (found != this->inputComponents.end())
        return found->second.get();
    found = this->clockComponents.find(toFind);
    if (found != this->clockComponents.end())
        return found->second.get();
    found = this->otherComponents.find(toFind);
    return found->second.get();
}

void nts::Simulator::initChipsets(nts::Parser::ChipsetsMap &chipsetsMap, nts::Parser &parser, const std::vector<std::string> args)
{
    chipsetsMap = parser.parseChipsets(args);
    for (auto it = chipsetsMap.begin(); it != chipsetsMap.end(); ++it) {
        if (it->second.at(0).compare("output") == 0) {
            this->outputComponents.insert({it->first, nts::Factory::createComponent(it->second.at(0), it->second.at(1))});
        } else if (it->second.at(0).compare("input") == 0) {
            this->inputComponents.insert({it->first, nts::Factory::createComponent(it->second.at(0), it->second.at(1))});
        } else if (it->second.at(0).compare("clock") == 0) {
            this->clockComponents.insert({it->first, nts::Factory::createComponent(it->second.at(0), it->second.at(1))});
        } else {
            this->otherComponents.insert({it->first, nts::Factory::createComponent(it->second.at(0), it->second.at(1))});
        }
    }
    if (chipsetsMap.size() == 0) {
        throw nts::Exception::CircuitFileException("There is no component to link.", "Simulator");
    }
}

void nts::Simulator::initLinks(nts::Parser::ChipsetsMap &chipsetsMap, nts::Parser &parser) const
{
    nts::Parser::LinksVector linksVector = parser.parseLinks(chipsetsMap);
    for (auto it = linksVector.begin(); it != linksVector.end(); ++it) {
        IComponent *toBeLink = this->findComponent(std::get<0>(*it).componentName);
        IComponent *toLink = this->findComponent(std::get<1>(*it).componentName);
        if (toBeLink->getPin(std::get<0>(*it).pinNumber)->type == nts::PinType::IN) {
            toBeLink->setLink(std::get<0>(*it).pinNumber, *toLink, std::get<1>(*it).pinNumber);
        } else {
            toLink->setLink(std::get<1>(*it).pinNumber, *toBeLink, std::get<0>(*it).pinNumber);
        }
    }
    if (linksVector.size() == 0) {
        throw nts::Exception::CircuitFileException("No link is specify.", "Simulator");
    }
}

void nts::Simulator::initSimulation(int ac, char **av)
{
    std::vector<std::string> args(av + 1, av + ac);
    nts::Parser parser(av[1]);
    nts::Parser::ChipsetsMap chipsetMap;

    this->initChipsets(chipsetMap, parser, args);
    this->initLinks(chipsetMap, parser);
}

void nts::Simulator::runSimulation(void) const
{
    std::string input;

    this->simulate();
    this->displayOutputs();
    while (42) {
        std::cout << "> ";
        std::flush(std::cout);
        if (!std::getline(std::cin, input)) {
            std::cout << "exit" << std::endl;
            break;
        }
        if (input.size() == 0)
            continue;
        auto found = this->functionnalitiesMap.find(input);
        if (found != this->functionnalitiesMap.end()) {
            if ((this->*(found->second))() == 1)
                break;
        } else if (std::regex_match(input, nts::Parser::commandLineRegex) == true) {
            auto cInput = this->inputComponents.find(input.substr(0, input.find("=")));
            if (cInput != this->inputComponents.end()) {
                cInput->second->getPin(1)->value = (nts::Tristate)std::stoi(input.substr(input.find("=") + 1));
            } else {
                std::cout << "Unknown input component" << std::endl;
            }
        } else {
            std::cout << "Wrong command" << std::endl;
        }
    }
}

int nts::Simulator::displayOutputs(void) const
{
    nts::Tristate result;

    for (auto it = this->outputComponents.begin(); it != this->outputComponents.end(); ++it) {
        result = it->second->getPin(1)->value;
        if (result == nts::Tristate::UNDEFINED) {
            std::cout << it->first << "=U" << std::endl;
        } else {
            std::cout << it->first << "=" << result << std::endl;
        }
    }
    return 0;
}

int nts::Simulator::exitSimulation(void) const
{
    return 1;
}

int nts::Simulator::simulate(void) const
{
    for (auto it = this->outputComponents.begin(); it != this->outputComponents.end(); ++it) {
        it->second->compute(1);
    }
    for (auto it = this->clockComponents.begin(); it != this->clockComponents.end(); ++it) {
        it->second->getPin(1)->value = !it->second->getPin(1)->value;
    }
    return 0;
}

void nts::Simulator::signalHandler(int)
{
    isLooping = false;
}

int nts::Simulator::loop(void) const
{
    struct sigaction sa;

    sa.sa_flags = 0;
    sa.sa_handler = &nts::Simulator::signalHandler;
    sa.sa_mask = {0};
    sigaction(SIGINT, &sa, NULL);
    while (isLooping == true) {
        this->simulate();
    }
    isLooping = true;
    return 0;
}

int nts::Simulator::dump(void) const
{
    for (auto it = this->outputComponents.begin(); it != this->outputComponents.end(); ++it) {
        it->second->dump();
    }
    for (auto it = this->inputComponents.begin(); it != this->inputComponents.end(); ++it) {
        it->second->dump();
    }
    for (auto it = this->clockComponents.begin(); it != this->clockComponents.end(); ++it) {
        it->second->dump();
    }
    for (auto it = this->otherComponents.begin(); it != this->otherComponents.end(); ++it) {
        it->second->dump();
    }
    return 0;
}

