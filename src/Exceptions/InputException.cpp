/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** InputException
*/

#include "InputException.hpp"

nts::exception::InputException::InputException(std::string const &message, std::string const &component)
    : nts::exception::NtsException(message, component)
{}