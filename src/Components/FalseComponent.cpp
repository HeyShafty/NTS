/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** FalseComponent
*/

#include <iostream>
#include "Components/FalseComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::FalseComponent::FalseComponent()
    : Component(1)
{
    this->pins[0].value = Tristate::FALSE;
    this->pins[0].type = PinType::OUT;
}

nts::Components::FalseComponent::~FalseComponent()
{
}

nts::Tristate nts::Components::FalseComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Given pin is out of range", "FalseComponent");
    return this->pins[pin - 1].value;
}
