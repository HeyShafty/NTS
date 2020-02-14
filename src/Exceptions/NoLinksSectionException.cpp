/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NoLinksSectionException
*/

#include "Exceptions/NoLinksSectionException.hpp"

nts::Exception::NoLinksSectionException::NoLinksSectionException(std::string const &message, std::string const &component)
    : nts::Exception::NtsException(message, component)
{}
