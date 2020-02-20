/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_SRFlipFlopComponent
*/

#include <criterion/criterion.h>
#include <memory>
#include "Components/FalseComponent.hpp"
#include "Components/TrueComponent.hpp"
#include "Components/SRFlipFlopComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

Test(SRFlipFlopComponent, false_false_first_compute)
{
    std::unique_ptr<nts::IComponent> srFlipFlop(new nts::Components::SRFlipFlopComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    srFlipFlop->setLink(1, *cFalse, 1);
    srFlipFlop->setLink(2, *cFalse, 1);
    cr_assert_eq(srFlipFlop->compute(3), nts::Tristate::UNDEFINED);
    cr_assert_eq(srFlipFlop->compute(4), nts::Tristate::UNDEFINED);
}

Test(SRFlipFlopComponent, true_false)
{
    std::unique_ptr<nts::IComponent> srFlipFlop(new nts::Components::SRFlipFlopComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    srFlipFlop->setLink(1, *cTrue, 1);
    srFlipFlop->setLink(2, *cFalse, 1);
    cr_assert_eq(srFlipFlop->compute(3), nts::Tristate::FALSE);
    cr_assert_eq(srFlipFlop->compute(4), nts::Tristate::TRUE);
}

Test(SRFlipFlopComponent, true_false_then_false_false)
{
    std::unique_ptr<nts::IComponent> srFlipFlop(new nts::Components::SRFlipFlopComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    srFlipFlop->setLink(1, *cTrue, 1);
    srFlipFlop->setLink(2, *cFalse, 1);
    cr_assert_eq(srFlipFlop->compute(3), nts::Tristate::FALSE);
    cr_assert_eq(srFlipFlop->compute(4), nts::Tristate::TRUE);
    srFlipFlop->setLink(1, *cFalse, 1);
    cr_assert_eq(srFlipFlop->compute(3), nts::Tristate::FALSE);
    cr_assert_eq(srFlipFlop->compute(4), nts::Tristate::TRUE);
}
