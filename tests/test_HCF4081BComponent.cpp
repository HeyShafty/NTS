/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_HCF4081BComponent
*/

#include <criterion/criterion.h>
#include <memory>
#include "Components/FalseComponent.hpp"
#include "Components/TrueComponent.hpp"
#include "Components/HCF4081BComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

Test(HCF4081BComponent, false_false)
{
    std::unique_ptr<nts::IComponent> c4081(new nts::Components::HCF4081BComponent(""));
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent(""));

    c4081->setLink(1, *cFalse, 1);
    c4081->setLink(2, *cFalse, 1);
    cr_assert_eq(c4081->compute(3), nts::Tristate::FALSE);
}

Test(HCF4081BComponent, false_true)
{
    std::unique_ptr<nts::IComponent> c4081(new nts::Components::HCF4081BComponent(""));
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent(""));
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent(""));

    c4081->setLink(1, *cFalse, 1);
    c4081->setLink(2, *cTrue, 1);
    cr_assert_eq(c4081->compute(3), nts::Tristate::FALSE);
}

Test(HCF4081BComponent, true_false)
{
    std::unique_ptr<nts::IComponent> c4081(new nts::Components::HCF4081BComponent(""));
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent(""));
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent(""));

    c4081->setLink(1, *cTrue, 1);
    c4081->setLink(2, *cFalse, 1);
    cr_assert_eq(c4081->compute(3), nts::Tristate::FALSE);
}

Test(HCF4081BComponent, true_true)
{
    std::unique_ptr<nts::IComponent> c4081(new nts::Components::HCF4081BComponent(""));
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent(""));

    c4081->setLink(1, *cTrue, 1);
    c4081->setLink(2, *cTrue, 1);
    cr_assert_eq(c4081->compute(3), nts::Tristate::TRUE);
}
