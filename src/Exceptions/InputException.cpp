/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** InputException
*/

#include "Exceptions/InputException.hpp"

nts::Exception::InputException::InputException(std::string const &message, std::string const &component)
    : nts::Exception::NtsException(message, component)
{}