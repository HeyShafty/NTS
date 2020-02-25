/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_HEF4001BComponent
*/

#include <criterion/criterion.h>
#include <memory>
#include "Components/FalseComponent.hpp"
#include "Components/TrueComponent.hpp"
#include "Components/HEF4001BComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

Test(HEF4001BComponent, false_false)
{
    std::unique_ptr<nts::IComponent> HEF4001B(new nts::Components::HEF4001BComponent(""));
    std::unique_ptr<nts::IComponent> cFalse1(new nts::Components::FalseComponent(""));
    std::unique_ptr<nts::IComponent> cFalse2(new nts::Components::FalseComponent(""));

    HEF4001B->setLink(1, *cFalse1, 1);
    HEF4001B->setLink(2, *cFalse2, 1);
    cr_assert_eq(HEF4001B->compute(3), nts::Tristate::TRUE);
}

Test(HEF4001BComponent, false_true)
{
    std::unique_ptr<nts::IComponent> HEF4001B(new nts::Components::HEF4001BComponent(""));
    std::unique_ptr<nts::IComponent> cFalse1(new nts::Components::FalseComponent(""));
    std::unique_ptr<nts::IComponent> cFalse2(new nts::Components::TrueComponent(""));

    HEF4001B->setLink(1, *cFalse1, 1);
    HEF4001B->setLink(2, *cFalse2, 1);
    cr_assert_eq(HEF4001B->compute(3), nts::Tristate::FALSE);
}

Test(HEF4001BComponent, true_false)
{
    std::unique_ptr<nts::IComponent> HEF4001B(new nts::Components::HEF4001BComponent(""));
    std::unique_ptr<nts::IComponent> cFalse1(new nts::Components::TrueComponent(""));
    std::unique_ptr<nts::IComponent> cFalse2(new nts::Components::FalseComponent(""));

    HEF4001B->setLink(1, *cFalse1, 1);
    HEF4001B->setLink(2, *cFalse2, 1);
    cr_assert_eq(HEF4001B->compute(3), nts::Tristate::FALSE);
}

Test(HEF4001BComponent, true_true)
{
    std::unique_ptr<nts::IComponent> HEF4001B(new nts::Components::HEF4001BComponent(""));
    std::unique_ptr<nts::IComponent> cFalse1(new nts::Components::TrueComponent(""));
    std::unique_ptr<nts::IComponent> cFalse2(new nts::Components::TrueComponent(""));

    HEF4001B->setLink(1, *cFalse1, 1);
    HEF4001B->setLink(2, *cFalse2, 1);
    cr_assert_eq(HEF4001B->compute(3), nts::Tristate::FALSE);
}
