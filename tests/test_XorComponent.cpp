/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_XorComponent
*/

#include <criterion/criterion.h>
#include <memory>
#include "Components/FalseComponent.hpp"
#include "Components/TrueComponent.hpp"
#include "Components/XorComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

Test(XorComponent, false_false)
{
    std::unique_ptr<nts::IComponent> cXor(new nts::Components::XorComponent(""));
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent(""));

    cXor->setLink(1, *cFalse, 1);
    cXor->setLink(2, *cFalse, 1);
    cr_assert_eq(cXor->compute(3), nts::Tristate::FALSE);
}

Test(XorComponent, false_true)
{
    std::unique_ptr<nts::IComponent> cXor(new nts::Components::XorComponent(""));
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent(""));
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent(""));

    cXor->setLink(1, *cFalse, 1);
    cXor->setLink(2, *cTrue, 1);
    cr_assert_eq(cXor->compute(3), nts::Tristate::TRUE);
}

Test(XorComponent, true_false)
{
    std::unique_ptr<nts::IComponent> cXor(new nts::Components::XorComponent(""));
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent(""));
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent(""));

    cXor->setLink(1, *cTrue, 1);
    cXor->setLink(2, *cFalse, 1);
    cr_assert_eq(cXor->compute(3), nts::Tristate::TRUE);
}

Test(XorComponent, true_true)
{
    std::unique_ptr<nts::IComponent> cXor(new nts::Components::XorComponent(""));
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent(""));

    cXor->setLink(1, *cTrue, 1);
    cXor->setLink(2, *cTrue, 1);
    cr_assert_eq(cXor->compute(3), nts::Tristate::FALSE);
}

Test(XorComponent, bad_linking)
{
    std::unique_ptr<nts::IComponent> cXor(new nts::Components::XorComponent(""));
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent(""));
    size_t vals[] = { 0, 10, 1000, 3 };

    for (size_t val : vals) {
        try
        {
            cXor->setLink(val, *cTrue, 1);
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
