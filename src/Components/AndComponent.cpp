/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AndComponent
*/

#include <iostream>
#include "Components/AndComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::AndComponent::AndComponent()
    : pin_nb(3)
{
    this->pins = std::make_unique<Pin[]>(this->pin_nb);
    for (size_t i = 0; i < this->pin_nb; i++) {
        this->pins[i].value = Tristate::UNDEFINED;
        this->pins[i].type = PinType::IN;
        this->pins[i].link = NULL;
        this->pins[i].link_n = 0;
    }
    this->pins[2].type = PinType::OUT;
}

nts::Components::AndComponent::~AndComponent()
{
}

nts::Tristate nts::Components::AndComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Pin cannot be computed", "AndComponent");
    if (pin == 1 || pin == 2) {
        this->pins[pin - 1].value = this->pins[pin - 1].link->compute(this->pins[pin - 1].link_n);
    } else
        this->pins[2].value = this->compute(1) && this->compute(2);
    return this->pins[pin - 1].value;
}

void nts::Components::AndComponent::setLink(size_t pin, const IComponent &other, size_t otherPin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Given pin is out of range", "AndComponent");
    if (this->pins[pin - 1].type != PinType::IN)
        throw nts::Exception::WrongPinException("Given pin cannot be linked: it is not an 'IN' pin", "AndComponent");
    this->pins[pin - 1].link = &other;
    this->pins[pin - 1].link_n = otherPin;
}

void nts::Components::AndComponent::dump() const
{
}
