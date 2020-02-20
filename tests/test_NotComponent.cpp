/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_NotComponent
*/

#include <criterion/criterion.h>
#include <memory>
#include "Components/FalseComponent.hpp"
#include "Components/TrueComponent.hpp"
#include "Components/NotComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

Test(NotComponent, false_to_true)
{
    std::unique_ptr<nts::IComponent> cNot(new nts::Components::NotComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    cNot->setLink(1, *cFalse, 1);
    cr_assert_eq(cNot->compute(2), nts::Tristate::TRUE);
}

Test(NotComponent, true_to_false)
{
    std::unique_ptr<nts::IComponent> cNot(new nts::Components::NotComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);

    cNot->setLink(1, *cTrue, 1);
    cr_assert_eq(cNot->compute(2), nts::Tristate::FALSE);
}

Test(NotComponent, undefined)
{
    std::unique_ptr<nts::IComponent> cNot(new nts::Components::NotComponent);

    cr_assert_eq(cNot->compute(2), nts::Tristate::UNDEFINED);
}
