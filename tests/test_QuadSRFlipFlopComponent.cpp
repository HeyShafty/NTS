/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_QuadSRFlipFlopComponent
*/

#include <criterion/criterion.h>
#include <memory>
#include "Components/FalseComponent.hpp"
#include "Components/TrueComponent.hpp"
#include "Components/QuadSRFlipFlopComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

Test(QuadSRFlipFlopComponent, illegal_case)
{
    std::unique_ptr<nts::IComponent> quadSRFlipFlop(new nts::Components::QuadSRFlipFlopComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);

    quadSRFlipFlop->setLink(1, *cTrue, 1);
    quadSRFlipFlop->setLink(2, *cTrue, 1);
    cr_assert_eq(quadSRFlipFlop->compute(3), nts::Tristate::FALSE);
    cr_assert_eq(quadSRFlipFlop->compute(4), nts::Tristate::FALSE);
}

Test(QuadSRFlipFlopComponent, false_false_first_compute)
{
    std::unique_ptr<nts::IComponent> quadSRFlipFlop(new nts::Components::QuadSRFlipFlopComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    quadSRFlipFlop->setLink(1, *cFalse, 1);
    quadSRFlipFlop->setLink(2, *cFalse, 1);
    cr_assert_eq(quadSRFlipFlop->compute(3), nts::Tristate::UNDEFINED);
    cr_assert_eq(quadSRFlipFlop->compute(4), nts::Tristate::UNDEFINED);
}

Test(QuadSRFlipFlopComponent, true_false)
{
    std::unique_ptr<nts::IComponent> quadSRFlipFlop(new nts::Components::QuadSRFlipFlopComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    quadSRFlipFlop->setLink(1, *cTrue, 1);
    quadSRFlipFlop->setLink(2, *cFalse, 1);
    cr_assert_eq(quadSRFlipFlop->compute(3), nts::Tristate::TRUE);
    cr_assert_eq(quadSRFlipFlop->compute(4), nts::Tristate::FALSE);
}

Test(QuadSRFlipFlopComponent, true_false_then_false_false)
{
    std::unique_ptr<nts::IComponent> quadSRFlipFlop(new nts::Components::QuadSRFlipFlopComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    quadSRFlipFlop->setLink(1, *cTrue, 1);
    quadSRFlipFlop->setLink(2, *cFalse, 1);
    cr_assert_eq(quadSRFlipFlop->compute(3), nts::Tristate::TRUE);
    cr_assert_eq(quadSRFlipFlop->compute(4), nts::Tristate::FALSE);
    quadSRFlipFlop->setLink(1, *cFalse, 1);
    cr_assert_eq(quadSRFlipFlop->compute(3), nts::Tristate::TRUE);
    cr_assert_eq(quadSRFlipFlop->compute(4), nts::Tristate::FALSE);
}

Test(QuadSRFlipFlopComponent, true_false_then_false_false_then_true_false)
{
    std::unique_ptr<nts::IComponent> quadSRFlipFlop(new nts::Components::QuadSRFlipFlopComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    quadSRFlipFlop->setLink(1, *cTrue, 1);
    quadSRFlipFlop->setLink(2, *cFalse, 1);
    cr_assert_eq(quadSRFlipFlop->compute(3), nts::Tristate::TRUE);
    cr_assert_eq(quadSRFlipFlop->compute(4), nts::Tristate::FALSE);
    quadSRFlipFlop->setLink(1, *cFalse, 1);
    cr_assert_eq(quadSRFlipFlop->compute(3), nts::Tristate::TRUE);
    cr_assert_eq(quadSRFlipFlop->compute(4), nts::Tristate::FALSE);
    quadSRFlipFlop->setLink(1, *cTrue, 1);
    cr_assert_eq(quadSRFlipFlop->compute(3), nts::Tristate::TRUE);
    cr_assert_eq(quadSRFlipFlop->compute(4), nts::Tristate::FALSE);
}

Test(QuadSRFlipFlopComponent, true_false_then_false_false_then_false_true)
{
    std::unique_ptr<nts::IComponent> quadSRFlipFlop(new nts::Components::QuadSRFlipFlopComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    quadSRFlipFlop->setLink(1, *cTrue, 1);
    quadSRFlipFlop->setLink(2, *cFalse, 1);
    cr_assert_eq(quadSRFlipFlop->compute(3), nts::Tristate::TRUE);
    cr_assert_eq(quadSRFlipFlop->compute(4), nts::Tristate::FALSE);
    quadSRFlipFlop->setLink(1, *cFalse, 1);
    cr_assert_eq(quadSRFlipFlop->compute(3), nts::Tristate::TRUE);
    cr_assert_eq(quadSRFlipFlop->compute(4), nts::Tristate::FALSE);
    quadSRFlipFlop->setLink(2, *cTrue, 1);
    cr_assert_eq(quadSRFlipFlop->compute(3), nts::Tristate::FALSE);
    cr_assert_eq(quadSRFlipFlop->compute(4), nts::Tristate::TRUE);
}

Test(QuadSRFlipFlopComponent, true_false_then_false_false_then_false_true_then_false_false)
{
    std::unique_ptr<nts::IComponent> quadSRFlipFlop(new nts::Components::QuadSRFlipFlopComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    quadSRFlipFlop->setLink(1, *cTrue, 1);
    quadSRFlipFlop->setLink(2, *cFalse, 1);
    cr_assert_eq(quadSRFlipFlop->compute(3), nts::Tristate::TRUE);
    cr_assert_eq(quadSRFlipFlop->compute(4), nts::Tristate::FALSE);
    quadSRFlipFlop->setLink(1, *cFalse, 1);
    cr_assert_eq(quadSRFlipFlop->compute(3), nts::Tristate::TRUE);
    cr_assert_eq(quadSRFlipFlop->compute(4), nts::Tristate::FALSE);
    quadSRFlipFlop->setLink(2, *cTrue, 1);
    cr_assert_eq(quadSRFlipFlop->compute(3), nts::Tristate::FALSE);
    cr_assert_eq(quadSRFlipFlop->compute(4), nts::Tristate::TRUE);
    quadSRFlipFlop->setLink(2, *cFalse, 1);
    cr_assert_eq(quadSRFlipFlop->compute(3), nts::Tristate::FALSE);
    cr_assert_eq(quadSRFlipFlop->compute(4), nts::Tristate::TRUE);
}
