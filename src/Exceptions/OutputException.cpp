/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** OutputException
*/

#include "OutputException.hpp"

nts::Exception::OutputException::OutputException(std::string const &message, std::string const &component)
    : nts::Exception::NtsException(message, component)
{}
