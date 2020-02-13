/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Factory
*/

#include "IComponent.hpp"
#include "Factory.hpp"
#include "TrueComponent.hpp"
#include "UnknownComponentException.hpp"

const std::map<const std::string, std::function<std::unique_ptr<nts::IComponent>(const std::string &value)>> nts::Factory::componentMap = {
    {"true", [](const std::string &) {return nts::Factory().createTrue();}}
};

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type, const std::string &value)
{
    try {
        return componentMap.at(type)(value);
    } catch (std::exception &e) {
        throw nts::Exception::UnknownComponentException("Given component couldn't be instanciated because it just doesn't exists.", "Factory");
    }
}

std::unique_ptr<nts::IComponent> nts::Factory::createTrue(void) const noexcept
{
    return std::make_unique<nts::Components::TrueComponent>();
}