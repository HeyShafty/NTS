/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Component
*/

#include "Component.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Component::Component(size_t pin_nb)
    : pin_nb(pin_nb), pins(std::make_unique<Pin[]>(this->pin_nb))
{
    for (size_t i = 0; i < this->pin_nb; i++) {
        this->pins[i].value = Tristate::UNDEFINED;
        this->pins[i].type = PinType::IN;
        this->pins[i].link = NULL;
        this->pins[i].link_n = 0;
    }
}

nts::Component::~Component()
{
}

void nts::Component::setLink(size_t pin, const IComponent &other, size_t otherPin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Given pin is out of range", "Component");
    if (this->pins[pin - 1].type != PinType::IN)
        throw nts::Exception::WrongPinException("Cannot link pin: not an input pin", "Component");
    this->pins[pin - 1].link = &other;
    this->pins[pin - 1].link_n = otherPin;
}

void nts::Component::dump() const
{
}
