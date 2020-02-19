/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_CD4013BCComponent
*/

#include <criterion/criterion.h>
#include "Components/CD4013BCComponent.hpp"
#include "Components/TrueComponent.hpp"
#include "Components/FalseComponent.hpp"

Test(CD4013BCComponent, q_row1)
{
    std::unique_ptr<nts::IComponent> clockFalse(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> clockTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> reset(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> data(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> set(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::CD4013BCComponent);

    dFlipFlop->setLink(3, *clockFalse, 1);
    dFlipFlop->setLink(4, *reset, 1);
    dFlipFlop->setLink(5, *data, 1);
    dFlipFlop->setLink(6, *set, 1);
    cr_assert_eq(dFlipFlop->compute(1), nts::Tristate::UNDEFINED);
    cr_assert_eq(dFlipFlop->getPin(2)->value, nts::Tristate::UNDEFINED);
    dFlipFlop->setLink(3, *clockTrue, 1);
    cr_assert_eq(dFlipFlop->compute(1), nts::Tristate::FALSE);
    cr_assert_eq(dFlipFlop->getPin(2)->value, nts::Tristate::TRUE);
    cr_assert_eq(dFlipFlop->compute(1), nts::Tristate::UNDEFINED);
    cr_assert_eq(dFlipFlop->getPin(2)->value, nts::Tristate::UNDEFINED);
}

Test(CD4013BCComponent, q_row2)
{
    std::unique_ptr<nts::IComponent> clockFalse(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> clockTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> reset(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> data(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> set(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::CD4013BCComponent);

    dFlipFlop->setLink(3, *clockFalse, 1);
    dFlipFlop->setLink(4, *reset, 1);
    dFlipFlop->setLink(5, *data, 1);
    dFlipFlop->setLink(6, *set, 1);
    cr_assert_eq(dFlipFlop->compute(1), nts::Tristate::UNDEFINED);
    cr_assert_eq(dFlipFlop->getPin(2)->value, nts::Tristate::UNDEFINED);
    dFlipFlop->setLink(3, *clockTrue, 1);
    cr_assert_eq(dFlipFlop->compute(1), nts::Tristate::TRUE);
    cr_assert_eq(dFlipFlop->getPin(2)->value, nts::Tristate::FALSE);
    cr_assert_eq(dFlipFlop->compute(1), nts::Tristate::UNDEFINED);
    cr_assert_eq(dFlipFlop->getPin(2)->value, nts::Tristate::UNDEFINED);
}

Test(CD4013BCComponent, q_row3)
{
    std::unique_ptr<nts::IComponent> clockFalse(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> clockTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> reset(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> data(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> set(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::CD4013BCComponent);

    dFlipFlop->setLink(3, *clockFalse, 1);
    dFlipFlop->setLink(4, *reset, 1);
    dFlipFlop->setLink(5, *data, 1);
    dFlipFlop->setLink(6, *set, 1);
    cr_assert_eq(dFlipFlop->compute(1), nts::Tristate::UNDEFINED);
    cr_assert_eq(dFlipFlop->getPin(2)->value, nts::Tristate::UNDEFINED);
    dFlipFlop->setLink(3, *clockTrue, 1);
    cr_assert_eq(dFlipFlop->compute(1), nts::Tristate::TRUE);
    cr_assert_eq(dFlipFlop->getPin(2)->value, nts::Tristate::FALSE);
    dFlipFlop->setLink(3, *clockFalse, 1);
    cr_assert_eq(dFlipFlop->compute(1), nts::Tristate::TRUE);
    cr_assert_eq(dFlipFlop->getPin(2)->value, nts::Tristate::FALSE);
    cr_assert_eq(dFlipFlop->compute(1), nts::Tristate::UNDEFINED);
    cr_assert_eq(dFlipFlop->getPin(2)->value, nts::Tristate::UNDEFINED);
}

Test(CD4013BCComponent, q_row40)
{
    std::unique_ptr<nts::IComponent> reset(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> set(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::CD4013BCComponent);

    dFlipFlop->setLink(4, *reset, 1);
    dFlipFlop->setLink(6, *set, 1);
    cr_assert_eq(dFlipFlop->compute(1), nts::Tristate::FALSE);
    cr_assert_eq(dFlipFlop->getPin(2)->value, nts::Tristate::TRUE);
}

Test(CD4013BCComponent, q_row41)
{
    std::unique_ptr<nts::IComponent> reset(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> set(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::CD4013BCComponent);

    dFlipFlop->setLink(10, *reset, 1);
    dFlipFlop->setLink(8, *set, 1);
    cr_assert_eq(dFlipFlop->compute(13), nts::Tristate::FALSE);
    cr_assert_eq(dFlipFlop->getPin(12)->value, nts::Tristate::TRUE);
}

Test(CD4013BCComponent, q_row50)
{
    std::unique_ptr<nts::IComponent> reset(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> set(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::CD4013BCComponent);

    dFlipFlop->setLink(4, *reset, 1);
    dFlipFlop->setLink(6, *set, 1);
    cr_assert_eq(dFlipFlop->compute(1), nts::Tristate::TRUE);
    cr_assert_eq(dFlipFlop->getPin(2)->value, nts::Tristate::FALSE);
}

Test(CD4013BCComponent, q_row51)
{
    std::unique_ptr<nts::IComponent> reset(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> set(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::CD4013BCComponent);

    dFlipFlop->setLink(10, *reset, 1);
    dFlipFlop->setLink(8, *set, 1);
    cr_assert_eq(dFlipFlop->compute(13), nts::Tristate::TRUE);
    cr_assert_eq(dFlipFlop->getPin(12)->value, nts::Tristate::FALSE);
}

Test(CD4013BCComponent, q_row60)
{
    std::unique_ptr<nts::IComponent> reset(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> set(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::CD4013BCComponent);

    dFlipFlop->setLink(4, *reset, 1);
    dFlipFlop->setLink(6, *set, 1);
    cr_assert_eq(dFlipFlop->compute(1), nts::Tristate::TRUE);
    cr_assert_eq(dFlipFlop->getPin(2)->value, nts::Tristate::TRUE);
}

Test(CD4013BCComponent, q_row61)
{
    std::unique_ptr<nts::IComponent> reset(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> set(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::CD4013BCComponent);

    dFlipFlop->setLink(10, *reset, 1);
    dFlipFlop->setLink(8, *set, 1);
    cr_assert_eq(dFlipFlop->compute(13), nts::Tristate::TRUE);
    cr_assert_eq(dFlipFlop->getPin(12)->value, nts::Tristate::TRUE);
}

Test(CD4013BCComponent, q_undefined1)
{
    std::unique_ptr<nts::IComponent> reset(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::CD4013BCComponent);

    dFlipFlop->setLink(4, *reset, 1);
    cr_assert_eq(dFlipFlop->compute(1), nts::Tristate::UNDEFINED);
    cr_assert_eq(dFlipFlop->getPin(2)->value, nts::Tristate::UNDEFINED);
}

Test(CD4013BCComponent, q_undefined2)
{
    std::unique_ptr<nts::IComponent> set(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::CD4013BCComponent);

    dFlipFlop->setLink(6, *set, 1);
    cr_assert_eq(dFlipFlop->compute(1), nts::Tristate::UNDEFINED);
    cr_assert_eq(dFlipFlop->getPin(2)->value, nts::Tristate::UNDEFINED);
}
