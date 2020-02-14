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
    : pin_nb(1)
{
    this->pins = std::make_unique<Pin[]>(this->pin_nb);
    for (size_t i = 0; i < this->pin_nb; i++) {
        this->pins[i].value = Tristate::FALSE;
        this->pins[i].type = PinType::OUT;
        this->pins[i].link = NULL;
        this->pins[i].link_n = 0;
    }
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

void nts::Components::FalseComponent::setLink(size_t pin, const IComponent &other, size_t otherPin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Given pin is out of range", "FalseComponent");
    if (this->pins[pin - 1].type != PinType::IN)
        throw nts::Exception::WrongPinException("Given pin cannot be linked: it is not an 'IN' pin", "FalseComponent");
    this->pins[pin - 1].link = &other;
    this->pins[pin - 1].link_n = otherPin;
}

void nts::Components::FalseComponent::dump() const
{
}
