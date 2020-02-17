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
    : Component(1)
{
    this->pins[0].value = Tristate::TRUE;
    this->pins[0].type = PinType::OUT;
}

nts::Components::TrueComponent::~TrueComponent()
{
}

nts::Tristate nts::Components::TrueComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Given pin is out of range", "TrueComponent");
    return this->pins[pin - 1].value;
}
