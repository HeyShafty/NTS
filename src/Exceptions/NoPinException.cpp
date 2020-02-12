/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NoPinException
*/

#include "NoPinException.hpp"

nts::exception::NoPinException::NoPinException(std::string const &message, std::string const &component)
    : nts::exception::NtsException(message, component)
{}