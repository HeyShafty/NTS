/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Factory
*/

#include <iostream>
#include "IComponent.hpp"
#include "Factory.hpp"
#include "Components/AndComponent.hpp"
#include "Components/CD4008BMSComponent.hpp"
#include "Components/CD4011BComponent.hpp"
#include "Components/CD4013BCComponent.hpp"
#include "Components/CD4030CComponent.hpp"
#include "Components/CD4514BCComponent.hpp"
#include "Components/ClockComponent.hpp"
#include "Components/DFlipFlopComponent.hpp"
#include "Components/FalseComponent.hpp"
#include "Components/HCF4081BComponent.hpp"
#include "Components/HEF4001BComponent.hpp"
#include "Components/HEF4071BComponent.hpp"
#include "Components/InputComponent.hpp"
#include "Components/J74HC4017Component.hpp"
#include "Components/MC14040BComponent.hpp"
#include "Components/NandComponent.hpp"
#include "Components/NorComponent.hpp"
#include "Components/NotComponent.hpp"
#include "Components/OrComponent.hpp"
#include "Components/OutputComponent.hpp"
#include "Components/CD4069UBCComponent.hpp"
#include "Components/QuadSRFlipFlopComponent.hpp"
#include "Components/QuadTripleNandComponent.hpp"
#include "Components/SRFlipFlopComponent.hpp"
#include "Components/SumComponent.hpp"
#include "Components/TerminalComponent.hpp"
#include "Components/TripleNandComponent.hpp"
#include "Components/TrueComponent.hpp"
#include "Components/XorComponent.hpp"
#include "Components/MM2716EComponent.hpp"
#include "Exceptions/UnknownComponentException.hpp"

const std::map<const std::string, std::function<std::shared_ptr<nts::IComponent>(const std::string &name, const std::string &value)>> nts::Factory::componentMap = {
    {"2716", [](const std::string &name, const std::string &value) {return nts::Factory::createBasicComponent<nts::Components::MM2716EComponent>(name, value);}},
    {"and", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::AndComponent>(name);}},
    {"4008", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::CD4008BMSComponent>(name);}},
    {"4011", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::CD4011BComponent>(name);}},
    {"4013", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::CD4013BCComponent>(name);}},
    {"4030", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::CD4030CComponent>(name);}},
    {"4514", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::CD4514BCComponent>(name);}},
    {"clock", [](const std::string &name, const std::string &value) {return nts::Factory::createBasicComponent<nts::Components::ClockComponent>(name, (nts::Tristate)std::stoi(value));}},
    {"dFlipFlop", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::DFlipFlopComponent>(name);}},
    {"false", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::FalseComponent>(name);}},
    {"4081", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::HCF4081BComponent>(name);}},
    {"4001", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::HEF4001BComponent>(name);}},
    {"4071", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::HEF4071BComponent>(name);}},
    {"input", [](const std::string &name, const std::string &value) {return nts::Factory::createBasicComponent<nts::Components::InputComponent>(name, (nts::Tristate)std::stoi(value));}},
    {"4017", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::J74HC4017Component>(name);}},
    {"4040", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::MC14040BComponent>(name);}},
    {"nand", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::NandComponent>(name);}},
    {"nor", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::NorComponent>(name);}},
    {"not", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::NotComponent>(name);}},
    {"or", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::OrComponent>(name);}},
    {"output", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::OutputComponent>(name);}},
    {"4069", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::CD4069UBCComponent>(name);}},
    {"quadSRFlipFlop", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::QuadSRFlipFlopComponent>(name);}},
    {"quadTripleNand", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::QuadTripleNandComponent>(name);}},
    {"SRFlipFlop", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::SRFlipFlopComponent>(name);}},
    {"sum", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::SumComponent>(name);}},
    {"terminal", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::TerminalComponent>(name);}},
    {"tripleNand", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::TripleNandComponent>(name);}},
    {"true", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::TrueComponent>(name);}},
    {"xor", [](const std::string &name, const std::string &) {return nts::Factory::createBasicComponent<nts::Components::XorComponent>(name);}}
};

std::shared_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type, const std::string &name, const std::string &value)
{
    try {
        return componentMap.at(type)(name, value);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        throw nts::Exception::UnknownComponentException("Given component couldn't be instanciated because it just doesn't exists.", "Factory");
    }
}
