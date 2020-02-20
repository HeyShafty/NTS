/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Factory
*/

#include "IComponent.hpp"
#include "Factory.hpp"
#include "Components/TrueComponent.hpp"
#include "Components/InputComponent.hpp"
#include "Components/OutputComponent.hpp"
#include "Components/HEF4071BComponent.hpp"
#include "Exceptions/UnknownComponentException.hpp"

const std::map<const std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>> nts::Factory::componentMap = {
    {"true", [](const std::string &) {return nts::Factory::createTrue();}},
    {"input", [](const std::string &value) {return nts::Factory::createInput(value);}},
    {"output", [](const std::string &) {return nts::Factory::createOutput();}},
    {"4071", [](const std::string &) {return nts::Factory::create4071();}}
};

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type, const std::string &value)
{
    try {
        return componentMap.at(type)(value);
    } catch (std::exception &e) {
        throw nts::Exception::UnknownComponentException("Given component couldn't be instanciated because it just doesn't exists.", "Factory");
    }
}

std::unique_ptr<nts::IComponent> nts::Factory::createTrue(void) noexcept
{
    return std::make_unique<nts::Components::TrueComponent>();
}

std::unique_ptr<nts::IComponent> nts::Factory::createInput(const std::string &value) noexcept
{
    return std::make_unique<nts::Components::InputComponent>((nts::Tristate)std::stoi(value));
}

std::unique_ptr<nts::IComponent> nts::Factory::createOutput(void) noexcept
{
    return std::make_unique<nts::Components::OutputComponent>();
}

std::unique_ptr<nts::IComponent> nts::Factory::create4071(void) noexcept
{
    return std::make_unique<nts::Components::HEF4071BComponent>();
}
