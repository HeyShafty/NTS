/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** InputComponent
*/

#include "Components/InputComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::InputComponent::InputComponent(const std::string &name, nts::Tristate pinValue)
    : AComponent("InputComponent", name, 1)
{
    this->pins[0]->value = pinValue;
    this->pins[0]->type = nts::PinType::OUT;
    this->pins[0]->compute = std::bind(&nts::Components::InputComponent::computeComponent, this);
}

nts::Tristate nts::Components::InputComponent::computeComponent(void) const
{
    return this->pins[0]->value;
}
