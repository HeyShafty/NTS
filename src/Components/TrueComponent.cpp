/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** TrueComponent
*/

#include <iostream>
#include "Components/TrueComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::TrueComponent::TrueComponent()
    : AComponent("TrueComponent", 1)
{
    this->pins[0]->type = PinType::OUT;
    this->pins[0]->compute = std::bind(&TrueComponent::computeComponent, this);
}

nts::Tristate nts::Components::TrueComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Pin is out of range.", "TrueComponent");
    return this->pins[pin - 1]->compute();
}

nts::Tristate nts::Components::TrueComponent::computeComponent() const
{
    return Tristate::TRUE;
}
