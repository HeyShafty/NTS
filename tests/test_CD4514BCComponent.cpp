/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_CD4514BCComponent
*/

#include <criterion/criterion.h>
#include "Components/CD4514BCComponent.hpp"
#include "Components/FalseComponent.hpp"
#include "Components/TrueComponent.hpp"

Test(CD4514BCComponent, undefined)
{
    std::unique_ptr<nts::IComponent> decoder(new nts::Components::CD4514BCComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    decoder->setLink(2, *cFalse, 1);
    decoder->setLink(3, *cFalse, 1);
    decoder->setLink(21, *cFalse, 1);
    decoder->setLink(22, *cFalse, 1);
    decoder->setLink(1, *cFalse, 1);
    decoder->setLink(23, *cFalse, 1);
    cr_assert_eq(decoder->compute(11), nts::Tristate::UNDEFINED);
    cr_assert_eq(decoder->compute(9),  nts::Tristate::UNDEFINED);
    cr_assert_eq(decoder->compute(10), nts::Tristate::UNDEFINED);
    cr_assert_eq(decoder->compute(8),  nts::Tristate::UNDEFINED);
    cr_assert_eq(decoder->compute(7),  nts::Tristate::UNDEFINED);
    cr_assert_eq(decoder->compute(6),  nts::Tristate::UNDEFINED);
    cr_assert_eq(decoder->compute(5),  nts::Tristate::UNDEFINED);
    cr_assert_eq(decoder->compute(4),  nts::Tristate::UNDEFINED);
    cr_assert_eq(decoder->compute(18), nts::Tristate::UNDEFINED);
    cr_assert_eq(decoder->compute(17), nts::Tristate::UNDEFINED);
    cr_assert_eq(decoder->compute(20), nts::Tristate::UNDEFINED);
    cr_assert_eq(decoder->compute(19), nts::Tristate::UNDEFINED);
    cr_assert_eq(decoder->compute(14), nts::Tristate::UNDEFINED);
    cr_assert_eq(decoder->compute(13), nts::Tristate::UNDEFINED);
    cr_assert_eq(decoder->compute(16), nts::Tristate::UNDEFINED);
    cr_assert_eq(decoder->compute(15), nts::Tristate::UNDEFINED);
}

Test(CD4514BCComponent, zero)
{
    std::unique_ptr<nts::IComponent> decoder(new nts::Components::CD4514BCComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    decoder->setLink(2, *cFalse, 1);
    decoder->setLink(3, *cFalse, 1);
    decoder->setLink(21, *cFalse, 1);
    decoder->setLink(22, *cFalse, 1);
    decoder->setLink(1, *cTrue, 1);
    decoder->setLink(23, *cFalse, 1);
    cr_assert_eq(decoder->compute(11), nts::Tristate::TRUE);
    cr_assert_eq(decoder->compute(9),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(10), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(8),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(7),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(6),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(5),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(4),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(18), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(17), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(20), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(19), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(14), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(13), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(16), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(15), nts::Tristate::FALSE);
}

Test(CD4514BCComponent, one)
{
    std::unique_ptr<nts::IComponent> decoder(new nts::Components::CD4514BCComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    decoder->setLink(2, *cTrue, 1);
    decoder->setLink(3, *cFalse, 1);
    decoder->setLink(21, *cFalse, 1);
    decoder->setLink(22, *cFalse, 1);
    decoder->setLink(1, *cTrue, 1);
    decoder->setLink(23, *cFalse, 1);
    cr_assert_eq(decoder->compute(11), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(9),  nts::Tristate::TRUE);
    cr_assert_eq(decoder->compute(10), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(8),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(7),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(6),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(5),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(4),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(18), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(17), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(20), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(19), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(14), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(13), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(16), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(15), nts::Tristate::FALSE);
}

Test(CD4514BCComponent, two)
{
    std::unique_ptr<nts::IComponent> decoder(new nts::Components::CD4514BCComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    decoder->setLink(2, *cFalse, 1);
    decoder->setLink(3, *cTrue, 1);
    decoder->setLink(21, *cFalse, 1);
    decoder->setLink(22, *cFalse, 1);
    decoder->setLink(1, *cTrue, 1);
    decoder->setLink(23, *cFalse, 1);
    cr_assert_eq(decoder->compute(11), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(9),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(10), nts::Tristate::TRUE);
    cr_assert_eq(decoder->compute(8),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(7),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(6),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(5),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(4),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(18), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(17), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(20), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(19), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(14), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(13), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(16), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(15), nts::Tristate::FALSE);
}

Test(CD4514BCComponent, three)
{
    std::unique_ptr<nts::IComponent> decoder(new nts::Components::CD4514BCComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    decoder->setLink(2, *cTrue, 1);
    decoder->setLink(3, *cTrue, 1);
    decoder->setLink(21, *cFalse, 1);
    decoder->setLink(22, *cFalse, 1);
    decoder->setLink(1, *cTrue, 1);
    decoder->setLink(23, *cFalse, 1);
    cr_assert_eq(decoder->compute(11), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(9),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(10), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(8),  nts::Tristate::TRUE);
    cr_assert_eq(decoder->compute(7),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(6),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(5),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(4),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(18), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(17), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(20), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(19), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(14), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(13), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(16), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(15), nts::Tristate::FALSE);
}

Test(CD4514BCComponent, four)
{
    std::unique_ptr<nts::IComponent> decoder(new nts::Components::CD4514BCComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    decoder->setLink(2, *cFalse, 1);
    decoder->setLink(3, *cFalse, 1);
    decoder->setLink(21, *cTrue, 1);
    decoder->setLink(22, *cFalse, 1);
    decoder->setLink(1, *cTrue, 1);
    decoder->setLink(23, *cFalse, 1);
    cr_assert_eq(decoder->compute(11), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(9),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(10), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(8),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(7),  nts::Tristate::TRUE);
    cr_assert_eq(decoder->compute(6),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(5),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(4),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(18), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(17), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(20), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(19), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(14), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(13), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(16), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(15), nts::Tristate::FALSE);
}

Test(CD4514BCComponent, five)
{
    std::unique_ptr<nts::IComponent> decoder(new nts::Components::CD4514BCComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    decoder->setLink(2, *cTrue, 1);
    decoder->setLink(3, *cFalse, 1);
    decoder->setLink(21, *cTrue, 1);
    decoder->setLink(22, *cFalse, 1);
    decoder->setLink(1, *cTrue, 1);
    decoder->setLink(23, *cFalse, 1);
    cr_assert_eq(decoder->compute(11), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(9),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(10), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(8),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(7),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(6),  nts::Tristate::TRUE);
    cr_assert_eq(decoder->compute(5),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(4),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(18), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(17), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(20), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(19), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(14), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(13), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(16), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(15), nts::Tristate::FALSE);
}

Test(CD4514BCComponent, six)
{
    std::unique_ptr<nts::IComponent> decoder(new nts::Components::CD4514BCComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    decoder->setLink(2, *cFalse, 1);
    decoder->setLink(3, *cTrue, 1);
    decoder->setLink(21, *cTrue, 1);
    decoder->setLink(22, *cFalse, 1);
    decoder->setLink(1, *cTrue, 1);
    decoder->setLink(23, *cFalse, 1);
    cr_assert_eq(decoder->compute(11), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(9),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(10), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(8),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(7),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(6),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(5),  nts::Tristate::TRUE);
    cr_assert_eq(decoder->compute(4),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(18), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(17), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(20), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(19), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(14), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(13), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(16), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(15), nts::Tristate::FALSE);
}

Test(CD4514BCComponent, seven)
{
    std::unique_ptr<nts::IComponent> decoder(new nts::Components::CD4514BCComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    decoder->setLink(2, *cTrue, 1);
    decoder->setLink(3, *cTrue, 1);
    decoder->setLink(21, *cTrue, 1);
    decoder->setLink(22, *cFalse, 1);
    decoder->setLink(1, *cTrue, 1);
    decoder->setLink(23, *cFalse, 1);
    cr_assert_eq(decoder->compute(11), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(9),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(10), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(8),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(7),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(6),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(5),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(4),  nts::Tristate::TRUE);
    cr_assert_eq(decoder->compute(18), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(17), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(20), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(19), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(14), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(13), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(16), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(15), nts::Tristate::FALSE);
}

Test(CD4514BCComponent, eight)
{
    std::unique_ptr<nts::IComponent> decoder(new nts::Components::CD4514BCComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    decoder->setLink(2, *cFalse, 1);
    decoder->setLink(3, *cFalse, 1);
    decoder->setLink(21, *cFalse, 1);
    decoder->setLink(22, *cTrue, 1);
    decoder->setLink(1, *cTrue, 1);
    decoder->setLink(23, *cFalse, 1);
    cr_assert_eq(decoder->compute(11), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(9),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(10), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(8),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(7),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(6),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(5),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(4),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(18), nts::Tristate::TRUE);
    cr_assert_eq(decoder->compute(17), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(20), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(19), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(14), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(13), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(16), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(15), nts::Tristate::FALSE);
}

Test(CD4514BCComponent, nine)
{
    std::unique_ptr<nts::IComponent> decoder(new nts::Components::CD4514BCComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    decoder->setLink(2, *cTrue, 1);
    decoder->setLink(3, *cFalse, 1);
    decoder->setLink(21, *cFalse, 1);
    decoder->setLink(22, *cTrue, 1);
    decoder->setLink(1, *cTrue, 1);
    decoder->setLink(23, *cFalse, 1);
    cr_assert_eq(decoder->compute(11), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(9),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(10), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(8),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(7),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(6),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(5),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(4),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(18), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(17), nts::Tristate::TRUE);
    cr_assert_eq(decoder->compute(20), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(19), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(14), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(13), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(16), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(15), nts::Tristate::FALSE);
}

Test(CD4514BCComponent, ten)
{
    std::unique_ptr<nts::IComponent> decoder(new nts::Components::CD4514BCComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    decoder->setLink(2, *cFalse, 1);
    decoder->setLink(3, *cTrue, 1);
    decoder->setLink(21, *cFalse, 1);
    decoder->setLink(22, *cTrue, 1);
    decoder->setLink(1, *cTrue, 1);
    decoder->setLink(23, *cFalse, 1);
    cr_assert_eq(decoder->compute(11), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(9),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(10), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(8),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(7),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(6),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(5),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(4),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(18), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(17), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(20), nts::Tristate::TRUE);
    cr_assert_eq(decoder->compute(19), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(14), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(13), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(16), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(15), nts::Tristate::FALSE);
}

Test(CD4514BCComponent, eleven)
{
    std::unique_ptr<nts::IComponent> decoder(new nts::Components::CD4514BCComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    decoder->setLink(2, *cTrue, 1);
    decoder->setLink(3, *cTrue, 1);
    decoder->setLink(21, *cFalse, 1);
    decoder->setLink(22, *cTrue, 1);
    decoder->setLink(1, *cTrue, 1);
    decoder->setLink(23, *cFalse, 1);
    cr_assert_eq(decoder->compute(11), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(9),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(10), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(8),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(7),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(6),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(5),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(4),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(18), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(17), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(20), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(19), nts::Tristate::TRUE);
    cr_assert_eq(decoder->compute(14), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(13), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(16), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(15), nts::Tristate::FALSE);
}

Test(CD4514BCComponent, twelve)
{
    std::unique_ptr<nts::IComponent> decoder(new nts::Components::CD4514BCComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    decoder->setLink(2, *cFalse, 1);
    decoder->setLink(3, *cFalse, 1);
    decoder->setLink(21, *cTrue, 1);
    decoder->setLink(22, *cTrue, 1);
    decoder->setLink(1, *cTrue, 1);
    decoder->setLink(23, *cFalse, 1);
    cr_assert_eq(decoder->compute(11), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(9),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(10), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(8),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(7),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(6),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(5),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(4),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(18), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(17), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(20), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(19), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(14), nts::Tristate::TRUE);
    cr_assert_eq(decoder->compute(13), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(16), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(15), nts::Tristate::FALSE);
}

Test(CD4514BCComponent, thirteen)
{
    std::unique_ptr<nts::IComponent> decoder(new nts::Components::CD4514BCComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    decoder->setLink(2, *cTrue, 1);
    decoder->setLink(3, *cFalse, 1);
    decoder->setLink(21, *cTrue, 1);
    decoder->setLink(22, *cTrue, 1);
    decoder->setLink(1, *cTrue, 1);
    decoder->setLink(23, *cFalse, 1);
    cr_assert_eq(decoder->compute(11), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(9),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(10), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(8),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(7),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(6),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(5),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(4),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(18), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(17), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(20), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(19), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(14), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(13), nts::Tristate::TRUE);
    cr_assert_eq(decoder->compute(16), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(15), nts::Tristate::FALSE);
}

Test(CD4514BCComponent, forteen)
{
    std::unique_ptr<nts::IComponent> decoder(new nts::Components::CD4514BCComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    decoder->setLink(2, *cFalse, 1);
    decoder->setLink(3, *cTrue, 1);
    decoder->setLink(21, *cTrue, 1);
    decoder->setLink(22, *cTrue, 1);
    decoder->setLink(1, *cTrue, 1);
    decoder->setLink(23, *cFalse, 1);
    cr_assert_eq(decoder->compute(11), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(9),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(10), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(8),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(7),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(6),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(5),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(4),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(18), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(17), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(20), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(19), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(14), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(13), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(16), nts::Tristate::TRUE);
    cr_assert_eq(decoder->compute(15), nts::Tristate::FALSE);
}

Test(CD4514BCComponent, fifteen)
{
    std::unique_ptr<nts::IComponent> decoder(new nts::Components::CD4514BCComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    decoder->setLink(2, *cTrue, 1);
    decoder->setLink(3, *cTrue, 1);
    decoder->setLink(21, *cTrue, 1);
    decoder->setLink(22, *cTrue, 1);
    decoder->setLink(1, *cTrue, 1);
    decoder->setLink(23, *cFalse, 1);
    cr_assert_eq(decoder->compute(11), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(9),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(10), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(8),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(7),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(6),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(5),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(4),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(18), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(17), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(20), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(19), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(14), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(13), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(16), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(15), nts::Tristate::TRUE);
}

Test(CD4514BCComponent, inhibitor1)
{
    std::unique_ptr<nts::IComponent> decoder(new nts::Components::CD4514BCComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    decoder->setLink(2, *cFalse, 1);
    decoder->setLink(3, *cFalse, 1);
    decoder->setLink(21, *cFalse, 1);
    decoder->setLink(22, *cFalse, 1);
    decoder->setLink(1, *cTrue, 1);
    decoder->setLink(23, *cTrue, 1);
    cr_assert_eq(decoder->compute(11), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(9),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(10), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(8),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(7),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(6),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(5),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(4),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(18), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(17), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(20), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(19), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(14), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(13), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(16), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(15), nts::Tristate::FALSE);
}

Test(CD4514BCComponent, inhibitor2)
{
    std::unique_ptr<nts::IComponent> decoder(new nts::Components::CD4514BCComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    decoder->setLink(2, *cTrue, 1);
    decoder->setLink(3, *cTrue, 1);
    decoder->setLink(21, *cTrue, 1);
    decoder->setLink(22, *cTrue, 1);
    decoder->setLink(1, *cTrue, 1);
    decoder->setLink(23, *cTrue, 1);
    cr_assert_eq(decoder->compute(11), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(9),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(10), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(8),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(7),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(6),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(5),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(4),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(18), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(17), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(20), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(19), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(14), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(13), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(16), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(15), nts::Tristate::FALSE);
}

Test(CD4514BCComponent, inhibitor3)
{
    std::unique_ptr<nts::IComponent> decoder(new nts::Components::CD4514BCComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    decoder->setLink(2, *cFalse, 1);
    decoder->setLink(3, *cFalse, 1);
    decoder->setLink(21, *cTrue, 1);
    decoder->setLink(22, *cTrue, 1);
    decoder->setLink(1, *cTrue, 1);
    decoder->setLink(23, *cTrue, 1);
    cr_assert_eq(decoder->compute(11), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(9),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(10), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(8),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(7),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(6),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(5),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(4),  nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(18), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(17), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(20), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(19), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(14), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(13), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(16), nts::Tristate::FALSE);
    cr_assert_eq(decoder->compute(15), nts::Tristate::FALSE);
}
