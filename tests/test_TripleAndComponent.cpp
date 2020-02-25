/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_TripleAndComponent
*/

#include <criterion/criterion.h>
#include <memory>
#include "Components/FalseComponent.hpp"
#include "Components/TrueComponent.hpp"
#include "Components/TripleNandComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

Test(TripleNandComponent, false_false_false)
{
    std::unique_ptr<nts::IComponent> cAnd(new nts::Components::TripleNandComponent(""));
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent(""));

    cAnd->setLink(1, *cFalse, 1);
    cAnd->setLink(2, *cFalse, 1);
    cAnd->setLink(3, *cFalse, 1);
    cr_assert_eq(cAnd->compute(4), nts::Tristate::TRUE);
}

Test(TripleNandComponent, false_false_true)
{
    std::unique_ptr<nts::IComponent> cAnd(new nts::Components::TripleNandComponent(""));
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent(""));
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent(""));

    cAnd->setLink(1, *cFalse, 1);
    cAnd->setLink(2, *cFalse, 1);
    cAnd->setLink(3, *cTrue, 1);
    cr_assert_eq(cAnd->compute(4), nts::Tristate::TRUE);
}

Test(TripleNandComponent, false_true_false)
{
    std::unique_ptr<nts::IComponent> cAnd(new nts::Components::TripleNandComponent(""));
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent(""));
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent(""));

    cAnd->setLink(1, *cFalse, 1);
    cAnd->setLink(2, *cTrue, 1);
    cAnd->setLink(3, *cFalse, 1);
    cr_assert_eq(cAnd->compute(4), nts::Tristate::TRUE);
}

Test(TripleNandComponent, false_true_true)
{
    std::unique_ptr<nts::IComponent> cAnd(new nts::Components::TripleNandComponent(""));
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent(""));
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent(""));

    cAnd->setLink(1, *cFalse, 1);
    cAnd->setLink(2, *cTrue, 1);
    cAnd->setLink(3, *cTrue, 1);
    cr_assert_eq(cAnd->compute(4), nts::Tristate::TRUE);
}

Test(TripleNandComponent, true_false_false)
{
    std::unique_ptr<nts::IComponent> cAnd(new nts::Components::TripleNandComponent(""));
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent(""));
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent(""));

    cAnd->setLink(1, *cTrue, 1);
    cAnd->setLink(2, *cFalse, 1);
    cAnd->setLink(3, *cFalse, 1);
    cr_assert_eq(cAnd->compute(4), nts::Tristate::TRUE);
}

Test(TripleNandComponent, true_false_true)
{
    std::unique_ptr<nts::IComponent> cAnd(new nts::Components::TripleNandComponent(""));
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent(""));
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent(""));

    cAnd->setLink(1, *cTrue, 1);
    cAnd->setLink(2, *cFalse, 1);
    cAnd->setLink(3, *cTrue, 1);
    cr_assert_eq(cAnd->compute(4), nts::Tristate::TRUE);
}

Test(TripleNandComponent, true_true_false)
{
    std::unique_ptr<nts::IComponent> cAnd(new nts::Components::TripleNandComponent(""));
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent(""));
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent(""));

    cAnd->setLink(1, *cTrue, 1);
    cAnd->setLink(2, *cTrue, 1);
    cAnd->setLink(3, *cFalse, 1);
    cr_assert_eq(cAnd->compute(4), nts::Tristate::TRUE);
}

Test(TripleNandComponent, true_true_true)
{
    std::unique_ptr<nts::IComponent> cAnd(new nts::Components::TripleNandComponent(""));
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent(""));

    cAnd->setLink(1, *cTrue, 1);
    cAnd->setLink(2, *cTrue, 1);
    cAnd->setLink(3, *cTrue, 1);
    cr_assert_eq(cAnd->compute(4), nts::Tristate::FALSE);
}
