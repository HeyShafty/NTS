/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_NorComponent
*/

#include <criterion/criterion.h>
#include <memory>
#include "Components/FalseComponent.hpp"
#include "Components/TrueComponent.hpp"
#include "Components/NorComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

Test(NorComponent, false_false)
{
    std::unique_ptr<nts::IComponent> cNor(new nts::Components::NorComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    cNor->setLink(1, *cFalse, 1);
    cNor->setLink(2, *cFalse, 1);
    cr_assert_eq(cNor->compute(3), nts::Tristate::TRUE);
}

Test(NorComponent, false_true)
{
    std::unique_ptr<nts::IComponent> cNor(new nts::Components::NorComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);

    cNor->setLink(1, *cFalse, 1);
    cNor->setLink(2, *cTrue, 1);
    cr_assert_eq(cNor->compute(3), nts::Tristate::FALSE);
}

Test(NorComponent, true_false)
{
    std::unique_ptr<nts::IComponent> cNor(new nts::Components::NorComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    cNor->setLink(1, *cTrue, 1);
    cNor->setLink(2, *cFalse, 1);
    cr_assert_eq(cNor->compute(3), nts::Tristate::FALSE);
}

Test(NorComponent, true_true)
{
    std::unique_ptr<nts::IComponent> cNor(new nts::Components::NorComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);

    cNor->setLink(1, *cTrue, 1);
    cNor->setLink(2, *cTrue, 1);
    cr_assert_eq(cNor->compute(3), nts::Tristate::FALSE);
}
