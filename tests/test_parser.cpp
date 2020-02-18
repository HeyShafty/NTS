/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_parser
*/

#include <criterion/criterion.h>
#include "Parser.hpp"

Test(parser, valid_file)
{
    nts::Parser parser("./my_test_files/simple_parser_test.nts");
    int ac = 4;
    const char *av[] = {"./nanotekspice", "i0=1", "i1=1", "i2=1"};
    std::unique_ptr<nts::Parser::ChipsetsMap> map;
    bool error = false;

    try
    {
        map = parser.parseFile(ac, av);
    }
    catch(const std::exception& e)
    {
        error = true;
    }
    cr_assert_eq(error, false);
    cr_assert((*map).size() != 0);
}

Test(parser, commented_valid_file)
{
    nts::Parser parser("./my_test_files/simple_parser_test.nts");
    int ac = 4;
    const char *av[] = {"./nanotekspice", "i0=1", "i1=1", "i2=1"};
    std::unique_ptr<nts::Parser::ChipsetsMap> map;
    bool error = false;

    try
    {
        map = parser.parseFile(ac, av);
    }
    catch(const std::exception& e)
    {
        error = true;
    }
    cr_assert_eq(error, false);
    cr_assert((*map).size() != 0);
}

Test(parser, no_chipsets_section_file)
{
    nts::Parser parser("./my_test_files/no_chipsets_section.nts");
    int ac = 4;
    const char *av[] = {"./nanotekspice", "i0=1", "i1=1", "i2=1"};
    std::unique_ptr<nts::Parser::ChipsetsMap> map;
    bool error = false;

    try
    {
        map = parser.parseFile(ac, av);
    }
    catch(const std::exception& e)
    {
        error = true;
    }
    cr_assert_eq(error, true);
}

Test(parser, no_links_section_file)
{
    nts::Parser parser("./my_test_files/no_links_section.nts");
    int ac = 4;
    const char *av[] = {"./nanotekspice", "i0=1", "i1=1", "i2=1"};
    std::unique_ptr<nts::Parser::ChipsetsMap> map;
    bool error = false;

    try
    {
        map = parser.parseFile(ac, av);
    }
    catch(const std::exception& e)
    {
        error = true;
    }
    cr_assert_eq(error, true);
}

Test(parser, not_valid_chipset_line)
{
    nts::Parser parser("./my_test_files/not_valid_chipset_line.nts");
    int ac = 4;
    const char *av[] = {"./nanotekspice", "i0=1", "i1=1", "i2=1"};
    std::unique_ptr<nts::Parser::ChipsetsMap> map;
    bool error = false;

    try
    {
        map = parser.parseFile(ac, av);
    }
    catch(const std::exception& e)
    {
        error = true;
    }
    cr_assert_eq(error, true);
}

Test(parser, not_valid_link_line)
{
    nts::Parser parser("./my_test_files/not_valid_link_line.nts");
    int ac = 4;
    const char *av[] = {"./nanotekspice", "i0=1", "i1=1", "i2=1"};
    std::unique_ptr<nts::Parser::ChipsetsMap> map;
    bool error = false;

    try
    {
        map = parser.parseFile(ac, av);
    }
    catch(const std::exception& e)
    {
        error = true;
    }
    cr_assert_eq(error, true);
}

Test(parser, not_valid_args)
{
    nts::Parser parser("./my_test_files/simple_parser_test.nts");
    int ac = 3;
    const char *av[] = {"./nanotekspice", "i0=1", "i1=1"};
    std::unique_ptr<nts::Parser::ChipsetsMap> map;
    bool error = false;

    try
    {
        map = parser.parseFile(ac, av);
    }
    catch(const std::exception& e)
    {
        error = true;
    }
    cr_assert_eq(error, true);
}

Test(parser, not_valid_args_clock)
{
    nts::Parser parser("./my_test_files/test_input_clock.nts");
    int ac = 3;
    const char *av[] = {"./nanotekspice", "i0=1", "i2=1"};
    std::unique_ptr<nts::Parser::ChipsetsMap> map;
    bool error = false;

    try
    {
        map = parser.parseFile(ac, av);
    }
    catch(const std::exception& e)
    {
        error = true;
    }
    cr_assert_eq(error, true);
}

Test(parser, invalid_link_component)
{
    nts::Parser parser("./my_test_files/invalid_link_component.nts");
    int ac = 3;
    const char *av[] = {"./nanotekspice", "i0=1", "i2=1"};
    std::unique_ptr<nts::Parser::ChipsetsMap> map;
    bool error = false;

    try
    {
        map = parser.parseFile(ac, av);
    }
    catch(const std::exception& e)
    {
        error = true;
    }
    cr_assert_eq(error, true);
}