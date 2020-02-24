/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_MM2716EComponent
*/

#include <criterion/criterion.h>
#include "Factory.hpp"
#include "Components/MM2716EComponent.hpp"
#include "Components/TrueComponent.hpp"
#include "Components/FalseComponent.hpp"

Test(MM2716EComponent, onefile)
{
    std::shared_ptr<nts::IComponent> rom = nts::Factory::createComponent("2716", "advanced/rom.bin");
    std::shared_ptr<nts::IComponent> cTrue = nts::Factory::createComponent("true");
    std::shared_ptr<nts::IComponent> cFalse = nts::Factory::createComponent("false");
    char expected = 0x20;

    rom->setLink(5, *cFalse, 1);
    rom->setLink(6, *cFalse, 1);
    rom->setLink(7, *cFalse, 1);
    rom->setLink(8, *cFalse, 1);
    rom->setLink(18, *cTrue, 1);
    rom->setLink(20, *cTrue, 1);
    for (int i = 0; i < 32; ++i) {
        rom->setLink(4,  *(i >> 0 & 0x1 ? cTrue : cFalse), 1);
        rom->setLink(3,  *(i >> 1 & 0x1 ? cTrue : cFalse), 1);
        rom->setLink(2,  *(i >> 2 & 0x1 ? cTrue : cFalse), 1);
        rom->setLink(1,  *(i >> 3 & 0x1 ? cTrue : cFalse), 1);
        rom->setLink(23, *(i >> 4 & 0x1 ? cTrue : cFalse), 1);
        rom->setLink(22, *(i >> 5 & 0x1 ? cTrue : cFalse), 1);
        rom->setLink(19, *(i >> 6 & 0x1 ? cTrue : cFalse), 1);
        cr_assert_eq(rom->compute(9),  expected >> 7 & 0x1 ? nts::Tristate::TRUE
                                                           : nts::Tristate::FALSE);
        cr_assert_eq(rom->compute(10), expected >> 6 & 0x1 ? nts::Tristate::TRUE
                                                           : nts::Tristate::FALSE);
        cr_assert_eq(rom->compute(11), expected >> 5 & 0x1 ? nts::Tristate::TRUE
                                                           : nts::Tristate::FALSE);
        cr_assert_eq(rom->compute(13), expected >> 4 & 0x1 ? nts::Tristate::TRUE
                                                           : nts::Tristate::FALSE);
        cr_assert_eq(rom->compute(14), expected >> 3 & 0x1 ? nts::Tristate::TRUE
                                                           : nts::Tristate::FALSE);
        cr_assert_eq(rom->compute(15), expected >> 2 & 0x1 ? nts::Tristate::TRUE
                                                           : nts::Tristate::FALSE);
        cr_assert_eq(rom->compute(16), expected >> 1 & 0x1 ? nts::Tristate::TRUE
                                                           : nts::Tristate::FALSE);
        cr_assert_eq(rom->compute(17), expected >> 0 & 0x1 ? nts::Tristate::TRUE
                                                           : nts::Tristate::FALSE);
        ++expected;
    }
}
