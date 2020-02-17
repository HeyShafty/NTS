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
    this->pins[2].type = PinType::OUT;
}

nts::Components::XorComponent::~XorComponent()
{
}

nts::Tristate nts::Components::XorComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Pin cannot be computed", "XorComponent");
    if (this->pins[pin - 1].type == PinType::ELECTRICAL)
        throw nts::Exception::WrongPinException("Pin cannot be computed (electrical)", "XorComponent");
    if (pin == 1 || pin == 2) {
        this->pins[pin - 1].value = this->pins[pin - 1].link->compute(this->pins[pin - 1].link_n);
    } else
        this->pins[2].value = this->compute(1) ^ this->compute(2);
    return this->pins[pin - 1].value;
}
