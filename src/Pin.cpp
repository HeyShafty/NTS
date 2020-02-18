/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Pin
*/

#include "Exceptions/WrongPinException.hpp"
#include "Pin.hpp"
#include "IComponent.hpp"

nts::Pin::Pin()
    : value(Tristate::UNDEFINED), type(PinType::IN), link(NULL), link_n(0)
{
}

nts::Tristate nts::Pin::compute()
{
    if (this->link == NULL)
        throw nts::Exception::WrongPinException("Cannot compute pin: not linked.", "Pin");
    this->value = this->link->compute(this->link_n);
    return this->value;
}
