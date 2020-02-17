/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** OrComponent
*/

#include "Components/OrComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::OrComponent::OrComponent()
    : Component(3)
{
    this->pins[2].type = PinType::OUT;
}

nts::Components::OrComponent::~OrComponent()
{
}

nts::Tristate nts::Components::OrComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Pin cannot be computed", "OrComponent");
    if (pin == 1 || pin == 2) {
        this->pins[pin - 1].value = this->pins[pin - 1].link->compute(this->pins[pin - 1].link_n);
    } else
        this->pins[2].value = this->compute(1) || this->compute(2);
    return this->pins[pin - 1].value;
}
