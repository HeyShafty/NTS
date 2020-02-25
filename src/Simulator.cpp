/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Simulator
*/

#include <iostream>
#include <signal.h>
#include "Exceptions/CircuitFileException.hpp"
#include "Exceptions/OutputException.hpp"
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
    auto found = this->components.find(toFind);

    return found->second.get();
}

void nts::Simulator::initChipsets(nts::Parser::ChipsetsMap &chipsetsMap, nts::Parser &parser, const std::vector<std::string> args)
{
    chipsetsMap = parser.parseChipsets(args);
    for (auto it = chipsetsMap.begin(); it != chipsetsMap.end(); ++it) {
        auto newComponent = nts::Factory::createComponent(it->second.at(0), it->first, it->second.at(1));
        this->components.insert({it->first, newComponent});
        if (it->second.at(0).compare("input") == 0) {
            this->inputComponents.insert({it->first, newComponent});
        } else if (it->second.at(0).compare("output") == 0) {
            this->outputComponents.insert({it->first, newComponent});
        }
        if (it->second.at(0) == "output" || it->second.at(0) == "clock"
        || it->second.at(0) == "terminal" || it->second.at(0) == "4801") {
            this->simulableComponents.push_back(std::dynamic_pointer_cast<ISimulable>(newComponent));
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
        throw nts::Exception::CircuitFileException("No link is specified.", "Simulator");
    }
}

void nts::Simulator::initSimulation(int ac, char **av)
{
    std::vector<std::string> args(av + 1, av + ac);
    nts::Parser parser(av[1]);
    nts::Parser::ChipsetsMap chipsetMap;

    this->initChipsets(chipsetMap, parser, args);
    this->initLinks(chipsetMap, parser);
    for (auto it = this->outputComponents.begin(); it != this->outputComponents.end(); ++it) {
        if (it->second->getPin(1)->link == nullptr) {
            throw nts::Exception::OutputException("One output component isn't linked.", "Simulator");
        }
    }
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
    for (auto it = this->simulableComponents.begin(); it != this->simulableComponents.end(); ++it) {
        (*it)->simulate();
    }
    return 0;
}

void nts::Simulator::signalHandler(int)
{
    nts::Simulator::isLooping = false;
}

int nts::Simulator::loop(void) const
{
    struct sigaction sa;

    sa.sa_flags = 0;
    sa.sa_handler = &nts::Simulator::signalHandler;
    sa.sa_mask = {0};
    sigaction(SIGINT, &sa, NULL);
    while (this->isLooping == true) {
        this->simulate();
    }
    this->isLooping = true;
    return 0;
}

int nts::Simulator::dump(void) const
{
    for (auto it = this->components.begin(); it != this->components.end(); ++it) {
        it->second->dump();
        if (std::distance(it, this->components.end()) > 1) {
            std::cout << std::endl;
        }
    }
    return 0;
}

