/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** WrongPinException
*/

#include "WrongPinException.hpp"

nts::Exception::WrongPinException::WrongPinException(std::string const &message, std::string const &component)
    : nts::Exception::NtsException(message, component)
{}