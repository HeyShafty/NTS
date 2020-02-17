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
    this->pins[2].type = PinType::OUT;
}

nts::Components::AndComponent::~AndComponent()
{
}

nts::Tristate nts::Components::AndComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Pin cannot be computed", "AndComponent");
    if (this->pins[pin - 1].type == PinType::ELECTRICAL)
        throw nts::Exception::WrongPinException("Pin cannot be computed (electrical)", "AndComponent");
    if (pin == 1 || pin == 2) {
        this->pins[pin - 1].value = this->pins[pin - 1].link->compute(this->pins[pin - 1].link_n);
    } else
        this->pins[2].value = this->compute(1) && this->compute(2);
    return this->pins[pin - 1].value;
}
