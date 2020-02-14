/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NoChipsetSectionException
*/

#include "Exceptions/NoChipsetSectionException.hpp"

nts::Exception::NoChipsetSectionException::NoChipsetSectionException(std::string const &message, std::string const &component)
    : nts::Exception::NtsException(message, component)
{}
