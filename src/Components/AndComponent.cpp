/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AndComponent
*/

#include "Components/AndComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::AndComponent::AndComponent()
    : Component("AndComponent", 3)
{
    this->pins[2]->type = PinType::OUT;
}

#include <functional>
nts::Tristate nts::Components::AndComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Pin is out of range.", "AndComponent");
    return this->pins[pin - 1]->compute();
    if (pin == 1 || pin == 2) {
        this->pins[pin - 1]->compute();
    } else
        this->pins[2]->value = this->compute(1) && this->compute(2);
    std::function<Tristate ()> func = [this](){ return this->compute(1) && this->compute(2); };
    return this->pins[pin - 1]->value;
}
