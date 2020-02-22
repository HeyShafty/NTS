/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_Tristate
*/

#include <criterion/criterion.h>
#include "Tristate.h"

Test(Tristate, and)
{
    cr_assert_eq(nts::Tristate::UNDEFINED && nts::Tristate::UNDEFINED, nts::Tristate::UNDEFINED);
    cr_assert_eq(nts::Tristate::UNDEFINED && nts::Tristate::FALSE, nts::Tristate::FALSE);
    cr_assert_eq(nts::Tristate::UNDEFINED && nts::Tristate::TRUE, nts::Tristate::UNDEFINED);
    cr_assert_eq(nts::Tristate::FALSE && nts::Tristate::UNDEFINED, nts::Tristate::FALSE);
    cr_assert_eq(nts::Tristate::TRUE && nts::Tristate::UNDEFINED, nts::Tristate::UNDEFINED);

    cr_assert_eq(nts::Tristate::FALSE && nts::Tristate::FALSE, nts::Tristate::FALSE);
    cr_assert_eq(nts::Tristate::FALSE && nts::Tristate::TRUE, nts::Tristate::FALSE);
    cr_assert_eq(nts::Tristate::TRUE && nts::Tristate::FALSE, nts::Tristate::FALSE);
    cr_assert_eq(nts::Tristate::TRUE && nts::Tristate::TRUE, nts::Tristate::TRUE);
}

Test(Tristate, or)
{
    cr_assert_eq(nts::Tristate::UNDEFINED || nts::Tristate::UNDEFINED, nts::Tristate::UNDEFINED);
    cr_assert_eq(nts::Tristate::UNDEFINED || nts::Tristate::FALSE, nts::Tristate::UNDEFINED);
    cr_assert_eq(nts::Tristate::UNDEFINED || nts::Tristate::TRUE, nts::Tristate::TRUE);
    cr_assert_eq(nts::Tristate::FALSE || nts::Tristate::UNDEFINED, nts::Tristate::UNDEFINED);
    cr_assert_eq(nts::Tristate::TRUE || nts::Tristate::UNDEFINED, nts::Tristate::TRUE);

    cr_assert_eq(nts::Tristate::FALSE || nts::Tristate::FALSE, nts::Tristate::FALSE);
    cr_assert_eq(nts::Tristate::FALSE || nts::Tristate::TRUE, nts::Tristate::TRUE);
    cr_assert_eq(nts::Tristate::TRUE || nts::Tristate::FALSE, nts::Tristate::TRUE);
    cr_assert_eq(nts::Tristate::TRUE || nts::Tristate::TRUE, nts::Tristate::TRUE);
}

Test(Tristate, xor)
{
    cr_assert_eq(nts::Tristate::UNDEFINED ^ nts::Tristate::UNDEFINED, nts::Tristate::UNDEFINED);
    cr_assert_eq(nts::Tristate::UNDEFINED ^ nts::Tristate::FALSE, nts::Tristate::UNDEFINED);
    cr_assert_eq(nts::Tristate::UNDEFINED ^ nts::Tristate::TRUE, nts::Tristate::UNDEFINED);
    cr_assert_eq(nts::Tristate::FALSE ^ nts::Tristate::UNDEFINED, nts::Tristate::UNDEFINED);
    cr_assert_eq(nts::Tristate::TRUE ^ nts::Tristate::UNDEFINED, nts::Tristate::UNDEFINED);

    cr_assert_eq(nts::Tristate::FALSE ^ nts::Tristate::FALSE, nts::Tristate::FALSE);
    cr_assert_eq(nts::Tristate::FALSE ^ nts::Tristate::TRUE, nts::Tristate::TRUE);
    cr_assert_eq(nts::Tristate::TRUE ^ nts::Tristate::FALSE, nts::Tristate::TRUE);
    cr_assert_eq(nts::Tristate::TRUE ^ nts::Tristate::TRUE, nts::Tristate::FALSE);
}

Test(Tristate, not)
{
    cr_assert_eq(!nts::Tristate::UNDEFINED, nts::Tristate::UNDEFINED);
    cr_assert_eq(!nts::Tristate::FALSE, nts::Tristate::TRUE);
    cr_assert_eq(!nts::Tristate::TRUE, nts::Tristate::FALSE);
}
