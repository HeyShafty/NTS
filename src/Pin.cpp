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
    : value(Tristate::UNDEFINED), type(PinType::IN), link(nullptr), link_n(0)
{
}
