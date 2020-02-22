/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Factory
*/

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
#include "Exceptions/UnknownComponentException.hpp"

const std::map<const std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>> nts::Factory::componentMap = {
    {"and", [](const std::string &) {return std::make_unique<nts::Components::AndComponent>();}},
    {"4008", [](const std::string &) {return std::make_unique<nts::Components::CD4008BMSComponent>();}},
    {"4011", [](const std::string &) {return std::make_unique<nts::Components::CD4011BComponent>();}},
    {"4013", [](const std::string &) {return std::make_unique<nts::Components::CD4013BCComponent>();}},
    {"4030", [](const std::string &) {return std::make_unique<nts::Components::CD4030CComponent>();}},
    {"4514", [](const std::string &) {return std::make_unique<nts::Components::CD4514BCComponent>();}},
    {"clock", [](const std::string &value) {return std::make_unique<nts::Components::ClockComponent>((nts::Tristate)std::stoi(value));}},
    {"dFlipFlop", [](const std::string &) {return std::make_unique<nts::Components::DFlipFlopComponent>();}},
    {"false", [](const std::string &) {return std::make_unique<nts::Components::FalseComponent>();}},
    {"4081", [](const std::string &) {return std::make_unique<nts::Components::HCF4081BComponent>();}},
    {"4001", [](const std::string &) {return std::make_unique<nts::Components::HEF4001BComponent>();}},
    {"4071", [](const std::string &) {return std::make_unique<nts::Components::HEF4071BComponent>();}},
    {"input", [](const std::string &value) {return std::make_unique<nts::Components::InputComponent>((nts::Tristate)std::stoi(value));}},
    {"nand", [](const std::string &) {return std::make_unique<nts::Components::NandComponent>();}},
    {"nor", [](const std::string &) {return std::make_unique<nts::Components::NorComponent>();}},
    {"not", [](const std::string &) {return std::make_unique<nts::Components::NotComponent>();}},
    {"or", [](const std::string &) {return std::make_unique<nts::Components::OrComponent>();}},
    {"output", [](const std::string &) {return std::make_unique<nts::Components::OutputComponent>();}},
    {"4069", [](const std::string &) {return std::make_unique<nts::Components::CD4069UBCComponent>();}},
    {"quadSRFlipFlop", [](const std::string &) {return std::make_unique<nts::Components::QuadSRFlipFlopComponent>();}},
    {"quadTripleNand", [](const std::string &) {return std::make_unique<nts::Components::QuadTripleNandComponent>();}},
    {"sRFlipFlop", [](const std::string &) {return std::make_unique<nts::Components::SRFlipFlopComponent>();}},
    {"sum", [](const std::string &) {return std::make_unique<nts::Components::SumComponent>();}},
    {"terminal", [](const std::string &) {return std::make_unique<nts::Components::TerminalComponent>();}},
    {"tripleNand", [](const std::string &) {return std::make_unique<nts::Components::TripleNandComponent>();}},
    {"true", [](const std::string &) {return std::make_unique<nts::Components::TrueComponent>();}},
    {"xor", [](const std::string &) {return std::make_unique<nts::Components::XorComponent>();}}
};

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type, const std::string &value)
{
    try {
        return componentMap.at(type)(value);
    } catch (std::exception &e) {
        throw nts::Exception::UnknownComponentException("Given component couldn't be instanciated because it just doesn't exists.", "Factory");
    }
}
