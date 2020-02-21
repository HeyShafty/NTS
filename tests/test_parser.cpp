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
    bool error = false;
    std::vector<std::string> args(av + 1, av + ac);
    nts::Parser::ChipsetsMap chipsets;
    nts::Parser::LinksVector links;

    try
    {
        chipsets = parser.parseChipsets(args);
        links = parser.parseLinks(chipsets);
    }
    catch(const std::exception& e)
    {
        error = true;
    }
    cr_assert_eq(error, false);
    cr_assert(chipsets.size() != 0);
    cr_assert(links.size() != 0);
}

Test(parser, valid_file_2)
{
    nts::Parser parser("./my_test_files/simple_parser_test_2.nts");
    int ac = 4;
    const char *av[] = {"./nanotekspice", "i0=1", "i1=1", "i2=1"};
    bool error = false;
    std::vector<std::string> args(av + 1, av + ac);
    nts::Parser::ChipsetsMap chipsets;
    nts::Parser::LinksVector links;

    try
    {
        chipsets = parser.parseChipsets(args);
        links = parser.parseLinks(chipsets);
    }
    catch(const std::exception& e)
    {
        error = true;
    }
    cr_assert_eq(error, false);
    cr_assert(chipsets.size() != 0);
    cr_assert(links.size() != 0);
}

Test(parser, commented_valid_file)
{
    nts::Parser parser("./my_test_files/comment_valid_file.nts");
    int ac = 4;
    const char *av[] = {"./nanotekspice", "i0=1", "i1=1", "i2=1"};
    bool error = false;
    std::vector<std::string> args(av + 1, av + ac);
    nts::Parser::ChipsetsMap chipsets;
    nts::Parser::LinksVector links;

    try
    {
        chipsets = parser.parseChipsets(args);
        links = parser.parseLinks(chipsets);
    }
    catch(const std::exception& e)
    {
        error = true;
    }
    cr_assert_eq(error, false);
    cr_assert(chipsets.size() != 0);
    cr_assert(links.size() != 0);
}

Test(parser, no_chipsets_section_file)
{
    nts::Parser parser("./my_test_files/no_chipsets_section.nts");
    int ac = 4;
    const char *av[] = {"./nanotekspice", "i0=1", "i1=1", "i2=1"};
    bool error = false;
    std::vector<std::string> args(av + 1, av + ac);
    nts::Parser::ChipsetsMap chipsets;

    try
    {
        chipsets = parser.parseChipsets(args);
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
    bool error = false;
    std::vector<std::string> args(av + 1, av + ac);
    nts::Parser::ChipsetsMap chipsets;
    nts::Parser::LinksVector links;

    try
    {
        chipsets = parser.parseChipsets(args);
        links = parser.parseLinks(chipsets);
    }
    catch(const std::exception& e)
    {
        error = true;
    }
    cr_assert_eq(error, true);
}

Test(parser, not_valid_chipset_file)
{
    nts::Parser parser("./my_test_files/unexistant_file.nts");
    int ac = 4;
    const char *av[] = {"./nanotekspice", "i0=1", "i1=1", "i2=1"};
    bool error = false;
    std::vector<std::string> args(av + 1, av + ac);
    nts::Parser::ChipsetsMap chipsets;

    try
    {
        chipsets = parser.parseChipsets(args);
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
    bool error = false;
    std::vector<std::string> args(av + 1, av + ac);
    nts::Parser::ChipsetsMap chipsets;

    try
    {
        chipsets = parser.parseChipsets(args);
    }
    catch(const std::exception& e)
    {
        error = true;
    }
    cr_assert_eq(error, true);
}

Test(parser, not_valid_chipset_line_2)
{
    nts::Parser parser("./my_test_files/not_valid_chipset_line_2.nts");
    int ac = 4;
    const char *av[] = {"./nanotekspice", "i0=1", "i1=1", "i2=1"};
    bool error = false;
    std::vector<std::string> args(av + 1, av + ac);
    nts::Parser::ChipsetsMap chipsets;

    try
    {
        chipsets = parser.parseChipsets(args);
    }
    catch(const std::exception& e)
    {
        error = true;
    }
    cr_assert_eq(error, true);
}

Test(parser, not_valid_chipset_line_3)
{
    nts::Parser parser("./my_test_files/not_valid_chipset_line_3.nts");
    int ac = 4;
    const char *av[] = {"./nanotekspice", "i0=1", "i1=1", "i2=1"};
    bool error = false;
    std::vector<std::string> args(av + 1, av + ac);
    nts::Parser::ChipsetsMap chipsets;

    try
    {
        chipsets = parser.parseChipsets(args);
    }
    catch(const std::exception& e)
    {
        error = true;
    }
    cr_assert_eq(error, true);
}

Test(parser, not_valid_chipset_line_4)
{
    nts::Parser parser("./my_test_files/not_valid_chipset_line_4.nts");
    int ac = 4;
    const char *av[] = {"./nanotekspice", "i0=1", "i1=1", "i2=1"};
    bool error = false;
    std::vector<std::string> args(av + 1, av + ac);
    nts::Parser::ChipsetsMap chipsets;

    try
    {
        chipsets = parser.parseChipsets(args);
    }
    catch(const std::exception& e)
    {
        error = true;
    }
    cr_assert_eq(error, true);
}

Test(parser, not_valid_link_file)
{
    nts::Parser parser("./my_test_files/unexistant_file.nts");
    int ac = 4;
    const char *av[] = {"./nanotekspice", "i0=1", "i1=1", "i2=1"};
    bool error = false;
    std::vector<std::string> args(av + 1, av + ac);
    nts::Parser::ChipsetsMap chipsets;
    nts::Parser::LinksVector links;

    try
    {
        links = parser.parseLinks(chipsets);
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
    bool error = false;
    std::vector<std::string> args(av + 1, av + ac);
    nts::Parser::ChipsetsMap chipsets;
    nts::Parser::LinksVector links;

    try
    {
        chipsets = parser.parseChipsets(args);
        links = parser.parseLinks(chipsets);
    }
    catch(const std::exception& e)
    {
        error = true;
    }
    cr_assert_eq(error, true);
}

Test(parser, not_valid_link_line_2)
{
    nts::Parser parser("./my_test_files/not_valid_link_line_2.nts");
    int ac = 4;
    const char *av[] = {"./nanotekspice", "i0=1", "i1=1", "i2=1"};
    bool error = false;
    std::vector<std::string> args(av + 1, av + ac);
    nts::Parser::ChipsetsMap chipsets;
    nts::Parser::LinksVector links;

    try
    {
        chipsets = parser.parseChipsets(args);
        links = parser.parseLinks(chipsets);
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
    bool error = false;
    std::vector<std::string> args(av + 1, av + ac);
    nts::Parser::ChipsetsMap chipsets;

    try
    {
        chipsets = parser.parseChipsets(args);
    }
    catch(const std::exception& e)
    {
        error = true;
    }
    cr_assert_eq(error, true);
}

Test(parser, not_valid_args_2)
{
    nts::Parser parser("./my_test_files/simple_parser_test.nts");
    int ac = 3;
    const char *av[] = {"./nanotekspice", "i0=2", "i1=1"};
    bool error = false;
    std::vector<std::string> args(av + 1, av + ac);
    nts::Parser::ChipsetsMap chipsets;

    try
    {
        chipsets = parser.parseChipsets(args);
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
    bool error = false;
    std::vector<std::string> args(av + 1, av + ac);
    nts::Parser::ChipsetsMap chipsets;

    try
    {
        chipsets = parser.parseChipsets(args);
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
    bool error = false;
    std::vector<std::string> args(av + 1, av + ac);
    nts::Parser::ChipsetsMap chipsets;
    nts::Parser::LinksVector links;

    try
    {
        chipsets = parser.parseChipsets(args);
        links = parser.parseLinks(chipsets);
    }
    catch(const std::exception& e)
    {
        error = true;
    }
    cr_assert_eq(error, true);
}