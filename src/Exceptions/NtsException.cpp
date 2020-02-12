/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NtsExpection
*/

#include "NtsException.hpp"

nts::exception::NtsException::NtsException(std::string const &message, std::string const &component)
    : _message(message), _component(component)
{}

std::string const &nts::exception::NtsException::getComponent() const
{
    return this->_component;
}

const char *nts::exception::NtsException::what() const
{
    return this->_message.c_str();
}