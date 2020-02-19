/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_DFlipFlopComponent
*/

#include <criterion/criterion.h>
#include "Components/DFlipFlopComponent.hpp"
#include "Components/TrueComponent.hpp"
#include "Components/FalseComponent.hpp"

Test(DFlipFlopComponent, q_row1)
{
    std::unique_ptr<nts::IComponent> clockFalse(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> clockTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> reset(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> data(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> set(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::DFlipFlopComponent);

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

Test(DFlipFlopComponent, q_row2)
{
    std::unique_ptr<nts::IComponent> clockFalse(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> clockTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> reset(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> data(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> set(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::DFlipFlopComponent);

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

Test(DFlipFlopComponent, q_row3)
{
    std::unique_ptr<nts::IComponent> clockFalse(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> clockTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> reset(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> data(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> set(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::DFlipFlopComponent);

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

Test(DFlipFlopComponent, q_row4)
{
    std::unique_ptr<nts::IComponent> reset(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> set(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::DFlipFlopComponent);

    dFlipFlop->setLink(4, *reset, 1);
    dFlipFlop->setLink(6, *set, 1);
    cr_assert_eq(dFlipFlop->compute(1), nts::Tristate::FALSE);
    cr_assert_eq(dFlipFlop->getPin(2)->value, nts::Tristate::TRUE);
}

Test(DFlipFlopComponent, q_row5)
{
    std::unique_ptr<nts::IComponent> reset(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> set(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::DFlipFlopComponent);

    dFlipFlop->setLink(4, *reset, 1);
    dFlipFlop->setLink(6, *set, 1);
    cr_assert_eq(dFlipFlop->compute(1), nts::Tristate::TRUE);
    cr_assert_eq(dFlipFlop->getPin(2)->value, nts::Tristate::FALSE);
}

Test(DFlipFlopComponent, q_row6)
{
    std::unique_ptr<nts::IComponent> reset(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> set(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::DFlipFlopComponent);

    dFlipFlop->setLink(4, *reset, 1);
    dFlipFlop->setLink(6, *set, 1);
    cr_assert_eq(dFlipFlop->compute(1), nts::Tristate::TRUE);
    cr_assert_eq(dFlipFlop->getPin(2)->value, nts::Tristate::TRUE);
}

Test(DFlipFlopComponent, q_undefined1)
{
    std::unique_ptr<nts::IComponent> reset(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::DFlipFlopComponent);

    dFlipFlop->setLink(4, *reset, 1);
    cr_assert_eq(dFlipFlop->compute(1), nts::Tristate::UNDEFINED);
    cr_assert_eq(dFlipFlop->getPin(2)->value, nts::Tristate::UNDEFINED);
}

Test(DFlipFlopComponent, q_undefined2)
{
    std::unique_ptr<nts::IComponent> set(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::DFlipFlopComponent);

    dFlipFlop->setLink(6, *set, 1);
    cr_assert_eq(dFlipFlop->compute(1), nts::Tristate::UNDEFINED);
    cr_assert_eq(dFlipFlop->getPin(2)->value, nts::Tristate::UNDEFINED);
}
