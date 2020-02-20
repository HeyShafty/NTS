/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** OutputComponent
*/

#include "Components/OutputComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::OutputComponent::OutputComponent()
    : Component("output", 1)
{
    this->pins[0]->type = nts::PinType::IN;
    this->pins[0]->compute = std::bind(&nts::Components::OutputComponent::computeInPin, this, 0);
}

nts::Tristate nts::Components::OutputComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Pin is out of range.", "NAndComponent");
    return this->pins[pin - 1]->compute();
}