/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** UnknownComponentException
*/

#include "UnknownComponentException.hpp"

nts::exception::UnknownComponentException::UnknownComponentException(std::string const &message, std::string const &component)
    : nts::exception::NtsException(message, component)
{}