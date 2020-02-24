/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_CD4008BMSComponent
*/

#include <criterion/criterion.h>
#include "Components/CD4008BMSComponent.hpp"
#include "Factory.hpp"
#include "IComponent.hpp"

Test(c4008, simple_test_1)
{
    std::shared_ptr<nts::IComponent> c4008 = nts::Factory::createComponent("4008");
    std::shared_ptr<nts::IComponent> cTrue1 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue2 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue3 = nts::Factory::createComponent("true");

    c4008->setLink(6, *cTrue1, 1);
    c4008->setLink(7, *cTrue2, 1);
    c4008->setLink(9, *cTrue3, 1);
    cr_assert_eq(c4008->compute(10), 1);
}

Test(c4008, simple_test_2)
{
    std::shared_ptr<nts::IComponent> c4008 = nts::Factory::createComponent("4008");
    std::shared_ptr<nts::IComponent> cTrue1 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue2 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cFalse = nts::Factory::createComponent("false");

    c4008->setLink(6, *cTrue1, 1);
    c4008->setLink(7, *cTrue2, 1);
    c4008->setLink(9, *cFalse, 1);
    cr_assert_eq(c4008->compute(10), 0);
}

Test(c4008, simple_test_3)
{
    std::shared_ptr<nts::IComponent> c4008 = nts::Factory::createComponent("4008");
    std::shared_ptr<nts::IComponent> cTrue1 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cFalse1 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cFalse2 = nts::Factory::createComponent("false");

    c4008->setLink(6, *cTrue1, 1);
    c4008->setLink(7, *cFalse1, 1);
    c4008->setLink(9, *cFalse2, 1);
    cr_assert_eq(c4008->compute(10), 1);
}

Test(c4008, simple_test_4)
{
    std::shared_ptr<nts::IComponent> c4008 = nts::Factory::createComponent("4008");
    std::shared_ptr<nts::IComponent> cFalse1 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cFalse2 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cFalse3 = nts::Factory::createComponent("false");

    c4008->setLink(6, *cFalse1, 1);
    c4008->setLink(7, *cFalse2, 1);
    c4008->setLink(9, *cFalse3, 1);
    cr_assert_eq(c4008->compute(10), 0);
}

Test(c4008, simple_test_5)
{
    std::shared_ptr<nts::IComponent> c4008 = nts::Factory::createComponent("4008");
    std::shared_ptr<nts::IComponent> cFalse1 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cFalse2 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cFalse3 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cTrue1 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue2 = nts::Factory::createComponent("true");

    c4008->setLink(6, *cFalse1, 1);
    c4008->setLink(7, *cFalse2, 1);
    c4008->setLink(9, *cFalse3, 1);
    c4008->setLink(4, *cTrue1, 1);
    c4008->setLink(5, *cTrue2, 1);
    cr_assert_eq(c4008->compute(11), 0);
}

Test(c4008, simple_test_6)
{
    std::shared_ptr<nts::IComponent> c4008 = nts::Factory::createComponent("4008");
    std::shared_ptr<nts::IComponent> cFalse1 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cFalse2 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cFalse3 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cFalse4 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cTrue1 = nts::Factory::createComponent("true");

    c4008->setLink(6, *cFalse1, 1);
    c4008->setLink(7, *cFalse2, 1);
    c4008->setLink(9, *cFalse3, 1);
    c4008->setLink(4, *cFalse4, 1);
    c4008->setLink(5, *cTrue1, 1);
    cr_assert_eq(c4008->compute(11), 1);
}

Test(c4008, test_carry_in_1)
{
    std::shared_ptr<nts::IComponent> c4008 = nts::Factory::createComponent("4008");
    std::shared_ptr<nts::IComponent> cFalse1 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cTrue1 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue2 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue3 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue4 = nts::Factory::createComponent("true");

    c4008->setLink(6, *cFalse1, 1);
    c4008->setLink(7, *cTrue1, 1);
    c4008->setLink(9, *cTrue2, 1);
    c4008->setLink(4, *cTrue3, 1);
    c4008->setLink(5, *cTrue4, 1);
    cr_assert_eq(c4008->compute(10), 0);
    cr_assert_eq(c4008->compute(11), 1);
}

Test(c4008, test_carry_in_2)
{
    std::shared_ptr<nts::IComponent> c4008 = nts::Factory::createComponent("4008");
    std::shared_ptr<nts::IComponent> cFalse1 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cTrue1 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue2 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue3 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue4 = nts::Factory::createComponent("true");

    c4008->setLink(6, *cTrue1, 1);
    c4008->setLink(7, *cFalse1, 1);
    c4008->setLink(9, *cTrue2, 1);
    c4008->setLink(4, *cTrue3, 1);
    c4008->setLink(5, *cTrue4, 1);
    cr_assert_eq(c4008->compute(10), 0);
    cr_assert_eq(c4008->compute(11), 1);
}

Test(c4008, test_carry_in_3)
{
    std::shared_ptr<nts::IComponent> c4008 = nts::Factory::createComponent("4008");
    std::shared_ptr<nts::IComponent> cFalse1 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cFalse2 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cFalse3 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cTrue1 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue2 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue3 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue4 = nts::Factory::createComponent("true");

    c4008->setLink(6, *cTrue1, 1);
    c4008->setLink(7, *cFalse1, 1);
    c4008->setLink(9, *cTrue2, 1);
    c4008->setLink(4, *cTrue3, 1);
    c4008->setLink(5, *cTrue4, 1);
    c4008->setLink(3, *cFalse2, 1);
    c4008->setLink(2, *cFalse3, 1);
    cr_assert_eq(c4008->compute(10), 0);
    cr_assert_eq(c4008->compute(11), 1);
    cr_assert_eq(c4008->compute(12), 1);
}

Test(c4008, test_carry_in_4)
{
    std::shared_ptr<nts::IComponent> c4008 = nts::Factory::createComponent("4008");
    std::shared_ptr<nts::IComponent> cFalse1 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cFalse2 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cFalse3 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cTrue1 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue2 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue3 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue4 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue5 = nts::Factory::createComponent("true");

    c4008->setLink(6, *cTrue1, 1);
    c4008->setLink(7, *cFalse1, 1);
    c4008->setLink(9, *cTrue2, 1);
    c4008->setLink(4, *cTrue3, 1);
    c4008->setLink(5, *cTrue4, 1);
    c4008->setLink(3, *cTrue5, 1);
    c4008->setLink(2, *cFalse3, 1);
    c4008->setLink(1, *cFalse3, 1);
    c4008->setLink(15, *cFalse3, 1);
    cr_assert_eq(c4008->compute(10), 0);
    cr_assert_eq(c4008->compute(11), 1);
    cr_assert_eq(c4008->compute(12), 0);
    cr_assert_eq(c4008->compute(13), 1);
}

Test(c4008, test_carry_out_1)
{
    std::shared_ptr<nts::IComponent> c4008 = nts::Factory::createComponent("4008");
    std::shared_ptr<nts::IComponent> cFalse1 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cFalse2 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cFalse3 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cTrue1 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue2 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue3 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue4 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue5 = nts::Factory::createComponent("true");

    c4008->setLink(6, *cTrue1, 1);
    c4008->setLink(7, *cFalse1, 1);
    c4008->setLink(9, *cTrue2, 1);
    c4008->setLink(4, *cTrue3, 1);
    c4008->setLink(5, *cTrue4, 1);
    c4008->setLink(3, *cTrue5, 1);
    c4008->setLink(2, *cFalse3, 1);
    c4008->setLink(1, *cFalse3, 1);
    c4008->setLink(15, *cFalse3, 1);
    cr_assert_eq(c4008->compute(10), 0);
    cr_assert_eq(c4008->compute(11), 1);
    cr_assert_eq(c4008->compute(12), 0);
    cr_assert_eq(c4008->compute(13), 1);
    cr_assert_eq(c4008->compute(14), 0);
}

Test(c4008, test_carry_out_2)
{
    std::shared_ptr<nts::IComponent> c4008 = nts::Factory::createComponent("4008");
    std::shared_ptr<nts::IComponent> cFalse1 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cFalse2 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cFalse3 = nts::Factory::createComponent("false");
    std::shared_ptr<nts::IComponent> cTrue1 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue2 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue3 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue4 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue5 = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cTrue6 = nts::Factory::createComponent("true");

    c4008->setLink(6, *cTrue1, 1);
    c4008->setLink(7, *cFalse1, 1);
    c4008->setLink(9, *cTrue2, 1);
    c4008->setLink(4, *cTrue3, 1);
    c4008->setLink(5, *cTrue4, 1);
    c4008->setLink(3, *cTrue5, 1);
    c4008->setLink(2, *cFalse3, 1);
    c4008->setLink(1, *cTrue6, 1);
    c4008->setLink(15, *cFalse3, 1);
    cr_assert_eq(c4008->compute(10), 0);
    cr_assert_eq(c4008->compute(11), 1);
    cr_assert_eq(c4008->compute(12), 0);
    cr_assert_eq(c4008->compute(13), 0);
    cr_assert_eq(c4008->compute(14), 1);
}