/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_OrComponent
*/

#include <criterion/criterion.h>
#include <memory>
#include "Components/FalseComponent.hpp"
#include "Components/TrueComponent.hpp"
#include "Components/OrComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

Test(OrComponent, false_false)
{
    std::unique_ptr<nts::IComponent> cOr(new nts::Components::OrComponent);
    std::unique_ptr<nts::IComponent> cFalse1(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> cFalse2(new nts::Components::FalseComponent);

    cOr->setLink(1, *cFalse1, 1);
    cOr->setLink(2, *cFalse2, 1);
    cr_assert_eq(cOr->compute(3), nts::Tristate::FALSE, "Value: %d");
}

Test(OrComponent, false_true)
{
    std::unique_ptr<nts::IComponent> cOr(new nts::Components::OrComponent);
    std::unique_ptr<nts::IComponent> cFalse1(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> cFalse2(new nts::Components::TrueComponent);

    cOr->setLink(1, *cFalse1, 1);
    cOr->setLink(2, *cFalse2, 1);
    cr_assert_eq(cOr->compute(3), nts::Tristate::TRUE, "Value: %d");
}

Test(OrComponent, true_false)
{
    std::unique_ptr<nts::IComponent> cOr(new nts::Components::OrComponent);
    std::unique_ptr<nts::IComponent> cFalse1(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse2(new nts::Components::FalseComponent);

    cOr->setLink(1, *cFalse1, 1);
    cOr->setLink(2, *cFalse2, 1);
    cr_assert_eq(cOr->compute(3), nts::Tristate::TRUE, "Value: %d");
}

Test(OrComponent, true_true)
{
    std::unique_ptr<nts::IComponent> cOr(new nts::Components::OrComponent);
    std::unique_ptr<nts::IComponent> cFalse1(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse2(new nts::Components::TrueComponent);

    cOr->setLink(1, *cFalse1, 1);
    cOr->setLink(2, *cFalse2, 1);
    cr_assert_eq(cOr->compute(3), nts::Tristate::TRUE, "Value: %d");
}

Test(OrComponent, bad_linking)
{
    std::unique_ptr<nts::IComponent> cOr(new nts::Components::OrComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::TrueComponent);
    size_t vals[] = { 0, 10, 1000, 3 };

    for (size_t val : vals) {
        try
        {
            cOr->setLink(val, *cFalse, 1);
            cr_assert_fail("No exception thrown.");
        }
        catch (nts::Exception::WrongPinException &ex)
        {
            cr_assert(true);
        }
        catch (std::exception &ex)
        {
            cr_assert_fail("Bad exception type. (%s)", ex.what());
        }
    }
}
