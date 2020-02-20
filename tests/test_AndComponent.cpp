/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_AndComponent
*/

#include <criterion/criterion.h>
#include <memory>
#include "Components/FalseComponent.hpp"
#include "Components/TrueComponent.hpp"
#include "Components/AndComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

Test(AndComponent, false_false)
{
    std::unique_ptr<nts::IComponent> cAnd(new nts::Components::AndComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    cAnd->setLink(1, *cFalse, 1);
    cAnd->setLink(2, *cFalse, 1);
    cr_assert_eq(cAnd->compute(3), nts::Tristate::FALSE);
}

Test(AndComponent, false_true)
{
    std::unique_ptr<nts::IComponent> cAnd(new nts::Components::AndComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);

    cAnd->setLink(1, *cFalse, 1);
    cAnd->setLink(2, *cTrue, 1);
    cr_assert_eq(cAnd->compute(3), nts::Tristate::FALSE);
}

Test(AndComponent, true_false)
{
    std::unique_ptr<nts::IComponent> cAnd(new nts::Components::AndComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);

    cAnd->setLink(1, *cFalse, 1);
    cAnd->setLink(2, *cTrue, 1);
    cr_assert_eq(cAnd->compute(3), nts::Tristate::FALSE);
}

Test(AndComponent, true_true)
{
    std::unique_ptr<nts::IComponent> cAnd(new nts::Components::AndComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);

    cAnd->setLink(1, *cTrue, 1);
    cAnd->setLink(2, *cTrue, 1);
    cr_assert_eq(cAnd->compute(3), nts::Tristate::TRUE);
}

Test(AndComponent, bad_linking)
{
    std::unique_ptr<nts::IComponent> cAnd(new nts::Components::AndComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    size_t vals[] = { 0, 10, 1000, 3 };

    for (size_t val : vals) {
        try
        {
            cAnd->setLink(val, *cTrue, 1);
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
