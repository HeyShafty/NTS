/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** XorComponent
*/

#include "Components/XorComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::XorComponent::XorComponent()
    : Component("XorComponent", 3)
{
    this->pins[2]->type = PinType::OUT;
}

nts::Tristate nts::Components::XorComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Pin is out of range.", "XorComponent");
    if (pin == 1 || pin == 2) {
        this->pins[pin - 1]->compute();
    } else
        this->pins[2]->value = this->compute(1) ^ this->compute(2);
    return this->pins[pin - 1]->value;
}
