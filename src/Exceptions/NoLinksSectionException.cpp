/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NoLinksSectionException
*/

#include "NoLinksSectionException.hpp"

nts::exception::NoLinksSectionException::NoLinksSectionException(std::string const &message, std::string const &component)
    : nts::exception::NtsException(message, component)
{}
