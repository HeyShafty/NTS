/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** TrueComponent
*/

#include <iostream>
#include "TrueComponent.hpp"

nts::Components::TrueComponent::TrueComponent()
    : pin_nb(1)
{
    this->pins = new Pin[this->pin_nb];
    for (size_t i = 0; i < this->pin_nb; i++) {
        this->pins[i].n = i + 1;
        this->pins[i].value = Tristate::TRUE;
        this->pins[i].type = PinType::OUT;
        this->pins[i].link = NULL;
        this->pins[i].link_n = 0;
    }
}

nts::Components::TrueComponent::~TrueComponent()
{
    delete [] this->pins;
}

nts::Tristate nts::Components::TrueComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw; // out of range pin
    return this->pins[pin].value;
}

void nts::Components::TrueComponent::setLink(size_t pin, const IComponent &other, size_t otherPin) const
{
    if (this->pins[pin].type != PinType::IN)
        throw; // bad pin type
    this->pins[pin].link = &other;
    this->pins[pin].link_n = otherPin;
}

void nts::Components::TrueComponent::dump() const
{
}
