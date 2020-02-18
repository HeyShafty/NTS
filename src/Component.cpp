/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Component
*/

#include "Component.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Component::Component(const std::string &name, size_t pin_nb)
    : name(name), pin_nb(pin_nb)
{
    for (size_t i = 0; i < this->pin_nb; i++) {
        this->pins.push_back(std::make_shared<Pin>());
    }
}

const std::shared_ptr<nts::Pin> &nts::Component::getPin(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Given pin is out of range", "Component");
    return this->pins[pin - 1];
}

void nts::Component::setLink(size_t pin, const IComponent &other, size_t otherPin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Given pin is out of range", "Component");
    if (this->pins[pin - 1]->type != PinType::IN)
        throw nts::Exception::WrongPinException("Cannot link pin: not an input pin", "Component");
    this->pins[pin - 1]->link = &other;
    this->pins[pin - 1]->link_n = otherPin;
}

void nts::Component::dump() const
{
}

nts::Tristate nts::Component::computeInPin(size_t pin_index) const
{
    if (this->pins[pin_index]->link == nullptr)
        return Tristate::UNDEFINED;
    return this->pins[pin_index]->link->compute(this->pins[pin_index]->link_n);
}
