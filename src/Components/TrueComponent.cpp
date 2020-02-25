/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** TrueComponent
*/

#include <iostream>
#include "Components/TrueComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::TrueComponent::TrueComponent(const std::string &name)
    : AComponent("TrueComponent", name, 1)
{
    this->pins[0]->type = PinType::OUT;
    this->pins[0]->compute = std::bind(&TrueComponent::computeComponent, this);
}

nts::Tristate nts::Components::TrueComponent::computeComponent() const
{
    return Tristate::TRUE;
}
