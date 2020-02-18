/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** MyFileException
*/

#include "Exceptions/BadFileException.hpp"

nts::Exception::BadFileException::BadFileException(std::string const &message, std::string const &component)
    : nts::Exception::NtsException(message, component)
{
}
