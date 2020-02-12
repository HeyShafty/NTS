/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** OutputException
*/

#include "OutputException.hpp"

nts::exception::OutputException::OutputException(std::string const &message, std::string const &component)
    : nts::exception::NtsException(message, component)
{}
