/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_Sum
*/

#include <criterion/criterion.h>
#include "Components/SumComponent.hpp"
#include "Factory.hpp"
#include "IComponent.hpp"
#include <iostream>

Test(sum, simple_sum_1)
{
    std::unique_ptr<nts::IComponent> cSum = nts::Factory::createComponent("sum");
    std::unique_ptr<nts::IComponent> cTrue1 = nts::Factory::createComponent("true");
    std::unique_ptr<nts::IComponent> cTrue2 = nts::Factory::createComponent("true");
    std::unique_ptr<nts::IComponent> cFalse = nts::Factory::createComponent("false");

    cSum->setLink(1, *cTrue1, 1);
    cSum->setLink(2, *cTrue2, 1);
    cSum->setLink(3, *cFalse, 1);
    cr_assert_eq(cSum->compute(4), 0);
    cr_assert_eq(cSum->compute(5), 1);
}

Test(sum, simple_sum_2)
{
    std::unique_ptr<nts::IComponent> cSum = nts::Factory::createComponent("sum");
    std::unique_ptr<nts::IComponent> cTrue1 = nts::Factory::createComponent("true");
    std::unique_ptr<nts::IComponent> cTrue2 = nts::Factory::createComponent("true");
    std::unique_ptr<nts::IComponent> cFalse = nts::Factory::createComponent("false");

    cSum->setLink(1, *cTrue1, 1);
    cSum->setLink(2, *cTrue2, 1);
    cSum->setLink(3, *cTrue2, 1);
    cr_assert_eq(cSum->compute(4), 1);
    cr_assert_eq(cSum->compute(5), 1);
}

Test(sum, simple_sum_3)
{
    std::unique_ptr<nts::IComponent> cSum = nts::Factory::createComponent("sum");
    std::unique_ptr<nts::IComponent> cTrue1 = nts::Factory::createComponent("true");
    std::unique_ptr<nts::IComponent> cFalse1 = nts::Factory::createComponent("false");
    std::unique_ptr<nts::IComponent> cFalse2 = nts::Factory::createComponent("false");

    cSum->setLink(1, *cTrue1, 1);
    cSum->setLink(2, *cFalse1, 1);
    cSum->setLink(3, *cFalse1, 1);
    cr_assert_eq(cSum->compute(4), 1);
    cr_assert_eq(cSum->compute(5), 0);
}
