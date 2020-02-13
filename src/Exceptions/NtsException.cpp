/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NtsExpection
*/

#include "NtsException.hpp"

nts::Exception::NtsException::NtsException(std::string const &message, std::string const &component)
    : _message(message), _component(component)
{}

std::string const &nts::Exception::NtsException::getComponent() const
{
    return this->_component;
}

const char *nts::Exception::NtsException::what() const noexcept
{
    return this->_message.c_str();
}