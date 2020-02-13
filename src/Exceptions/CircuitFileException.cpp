/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CircuitFileException
*/

#include "CircuitFileException.hpp"

nts::Exception::CircuitFileException::CircuitFileException(std::string const &message, std::string const &component)
    : nts::Exception::NtsException(message, component)
{}