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
    : pin_nb(1)
{
    this->pins = std::make_unique<Pin[]>(this->pin_nb);
    for (size_t i = 0; i < this->pin_nb; i++) {
        this->pins[i].value = Tristate::TRUE;
        this->pins[i].type = PinType::OUT;
        this->pins[i].link = NULL;
        this->pins[i].link_n = 0;
    }
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

void nts::Components::TrueComponent::setLink(size_t pin, const IComponent &other, size_t otherPin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Given pin is out of range", "TrueComponent");
    if (this->pins[pin - 1].type != PinType::IN)
        throw nts::Exception::WrongPinException("Given pin cannot be linked: it is not an 'IN' pin", "TrueComponent");
    this->pins[pin - 1].link = &other;
    this->pins[pin - 1].link_n = otherPin;
}

void nts::Components::TrueComponent::dump() const
{
}
