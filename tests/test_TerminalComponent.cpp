/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_TerminalComponent
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Factory.hpp"
#include "OSRedirector.hpp"

Test(TerminalComponent, no_display)
{
    std::unique_ptr<nts::IComponent> terminal = nts::Factory::createComponent("terminal");
    std::unique_ptr<nts::IComponent> cTrue = nts::Factory::createComponent("true");
    std::unique_ptr<nts::IComponent> cFalse = nts::Factory::createComponent("false");
    std::string got;

    terminal->setLink(1, *cFalse, 1);
    terminal->setLink(2, *cFalse, 1);
    terminal->setLink(3, *cFalse, 1);
    terminal->setLink(4, *cFalse, 1);
    terminal->setLink(5, *cFalse, 1);
    terminal->setLink(6, *cFalse, 1);
    terminal->setLink(7, *cFalse, 1);
    terminal->setLink(8, *cFalse, 1);
    terminal->setLink(9, *cFalse, 1);
    {
        OSRedirector oss(std::cout);

        terminal->dump();
        got = oss.getContent();
    }
    cr_assert_str_eq(got.c_str(), "");
}

Test(TerminalComponent, display_ascii_1)
{
    std::unique_ptr<nts::IComponent> terminal = nts::Factory::createComponent("terminal");
    std::unique_ptr<nts::IComponent> cTrue = nts::Factory::createComponent("true");
    std::unique_ptr<nts::IComponent> cFalse = nts::Factory::createComponent("false");
    std::string got;

    terminal->setLink(1, *cFalse, 1);
    terminal->setLink(2, *cFalse, 1);
    terminal->setLink(3, *cFalse, 1);
    terminal->setLink(4, *cFalse, 1);
    terminal->setLink(5, *cTrue, 1);
    terminal->setLink(6, *cTrue, 1);
    terminal->setLink(7, *cFalse, 1);
    terminal->setLink(8, *cFalse, 1);
    terminal->setLink(9, *cTrue, 1);
    {
        OSRedirector oss(std::cout);

        terminal->dump();
        got = oss.getContent();
    }
    cr_assert_str_eq(got.c_str(), "0\n");
}

Test(TerminalComponent, display_ascii_2)
{
    std::unique_ptr<nts::IComponent> terminal = nts::Factory::createComponent("terminal");
    std::unique_ptr<nts::IComponent> cTrue = nts::Factory::createComponent("true");
    std::unique_ptr<nts::IComponent> cFalse = nts::Factory::createComponent("false");
    std::string got;

    terminal->setLink(1, *cFalse, 1);
    terminal->setLink(2, *cFalse, 1);
    terminal->setLink(3, *cFalse, 1);
    terminal->setLink(4, *cFalse, 1);
    terminal->setLink(5, *cFalse, 1);
    terminal->setLink(6, *cFalse, 1);
    terminal->setLink(7, *cTrue, 1);
    terminal->setLink(8, *cFalse, 1);
    terminal->setLink(9, *cTrue, 1);
    {
        OSRedirector oss(std::cout);

        terminal->dump();
        got = oss.getContent();
    }
    cr_assert_str_eq(got.c_str(), "@\n");
}
