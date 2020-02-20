/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Tristate
*/

#include "Tristate.h"

nts::Tristate operator&&(const nts::Tristate &left, const nts::Tristate &right)
{
    if (left == nts::Tristate::UNDEFINED || right == nts::Tristate::UNDEFINED)
        return nts::Tristate::UNDEFINED;
    return (nts::Tristate)((bool)left && (bool)right);
}

nts::Tristate operator||(const nts::Tristate &left, const nts::Tristate &right)
{
    if (left == nts::Tristate::UNDEFINED && right == nts::Tristate::UNDEFINED)
        return nts::Tristate::UNDEFINED;
    if (left == nts::Tristate::UNDEFINED)
        return right == nts::Tristate::TRUE ? nts::Tristate::TRUE : nts::Tristate::UNDEFINED;
    if (right == nts::Tristate::UNDEFINED)
        return left == nts::Tristate::TRUE ? nts::Tristate::TRUE : nts::Tristate::UNDEFINED;
    return (nts::Tristate)((bool)left || (bool)right);
}

nts::Tristate operator^(const nts::Tristate &left, const nts::Tristate &right)
{
    if (left == nts::Tristate::UNDEFINED || right == nts::Tristate::UNDEFINED)
        return nts::Tristate::UNDEFINED;
    return (nts::Tristate)((bool)left ^ (bool)right);
}

nts::Tristate operator!(const nts::Tristate &state)
{
    if (state == nts::Tristate::UNDEFINED)
        return nts::Tristate::UNDEFINED;
    return (nts::Tristate)!(bool)state;
}
