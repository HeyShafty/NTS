/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Tristate
*/

#ifndef TRISTATE_H_
#define TRISTATE_H_

namespace nts
{
    enum Tristate
    {
        UNDEFINED = (-true),
        FALSE = false,
        TRUE = true
    };
}
nts::Tristate operator&&(const nts::Tristate &left, const nts::Tristate &right);
nts::Tristate operator||(const nts::Tristate &left, const nts::Tristate &right);
nts::Tristate operator^(const nts::Tristate &left, const nts::Tristate &right);

#endif /* !TRISTATE_H_ */
