/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** OutputComponent
*/

#include "Components/OutputComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::OutputComponent::OutputComponent(const std::string &name)
    : AComponent("OutputComponent", name, 1)
{
    BIND_IN_PIN(0, OutputComponent);
}

void nts::Components::OutputComponent::simulate() const
{
    this->pins[0]->value = this->pins[0]->compute();
}
