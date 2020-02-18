/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_N4081Component
*/

#include <criterion/criterion.h>
#include <memory>
#include "Components/FalseComponent.hpp"
#include "Components/TrueComponent.hpp"
#include "Components/N4081Component.hpp"
#include "Exceptions/WrongPinException.hpp"

Test(N4081Component, false_false)
{
    std::unique_ptr<nts::IComponent> c4081(new nts::Components::N4081Component);
    std::unique_ptr<nts::IComponent> cFalse1(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> cFalse2(new nts::Components::FalseComponent);

    c4081->setLink(1, *cFalse1, 1);
    c4081->setLink(2, *cFalse2, 1);
    cr_assert_eq(c4081->compute(3), nts::Tristate::FALSE);
}

Test(N4081Component, false_true)
{
    std::unique_ptr<nts::IComponent> c4081(new nts::Components::N4081Component);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);

    c4081->setLink(1, *cFalse, 1);
    c4081->setLink(2, *cTrue, 1);
    cr_assert_eq(c4081->compute(3), nts::Tristate::FALSE);
}

Test(N4081Component, true_false)
{
    std::unique_ptr<nts::IComponent> c4081(new nts::Components::N4081Component);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    c4081->setLink(1, *cTrue, 1);
    c4081->setLink(2, *cFalse, 1);
    cr_assert_eq(c4081->compute(3), nts::Tristate::FALSE);
}

Test(N4081Component, true_true)
{
    std::unique_ptr<nts::IComponent> c4081(new nts::Components::N4081Component);
    std::unique_ptr<nts::IComponent> cTrue1(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cTrue2(new nts::Components::TrueComponent);

    c4081->setLink(1, *cTrue1, 1);
    c4081->setLink(2, *cTrue2, 1);
    cr_assert_eq(c4081->compute(3), nts::Tristate::TRUE);
}
