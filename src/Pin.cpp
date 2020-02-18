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
    : type(PinType::IN), link(NULL), link_n(0)
{
}
