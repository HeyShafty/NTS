/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Parser
*/

#include <iostream>
#include <fstream>
#include <regex>
#include "Parser.hpp"
#include "Factory.hpp"
#include "IComponent.hpp"
#include "Exceptions/BadFileException.hpp"
#include "Exceptions/NoChipsetSectionException.hpp"
#include "Exceptions/NoLinksSectionException.hpp"

const std::regex nts::Parser::commentLine("^\\s*[#].*");
const std::regex nts::Parser::validChipsetLine("^\\S+\\s+\\S+\\s*(#.*)?");
const std::regex nts::Parser::linksRegex("\\.links:\\s*#?");
const std::regex nts::Parser::validLinksLine("^\\S+:\\d+\\s+\\S+:\\d+\\s*(#.*)?");
const std::regex nts::Parser::chipsetRegex("\\.chipsets:\\s*#?");
const std::vector<std::string> nts::Parser::componentsWithCommandLineArg = {"input", "clock"};


nts::Parser::Parser(const std::string &filename)
    : _filename(filename)
{}

nts::Parser::~Parser()
{}

void nts::Parser::setFilename(const std::string &filename)
{
    this->_filename = filename;
}

void nts::Parser::linkComponents(std::unique_ptr<ChipsetsMap> &chipsetsMap, std::string line) const
{
    std::vector<std::string> words;

    if (line.find("#") != std::string::npos) {
        line = line.substr(0, line.find("#"));
    }
    std::istringstream iss(line);
    for (std::string word; iss >> word; words.push_back(word));
    if (words.size() != 2)
        throw nts::Exception::BadFileException("One given line is missed formatted", "Parser");
    std::cout << "---begin of link---" << std::endl;
    std::cout << words[0].substr(0, words[0].find(":")) << " = " << std::stoi(words[0].substr(words[0].find(":") + 1)) << std::endl;
    std::cout << words[1].substr(0, words[1].find_last_of(":")) << " = " << std::stoi(words[1].substr(words[1].find(":") + 1)) << std::endl;
    std::cout << "---end of link---" << std::endl;
    (void) chipsetsMap;
    //(*chipsetsMap)[words[0].substr(0, words[0].length() - words[0].find(":"))]->setLink(std::stoi(words[0].substr(words[0].find(":") + 1)), *(*chipsetsMap)[words[1].substr(0, words[1].find(":"))], std::stoi(words[1].substr(words[1].find(":") + 1)));
}

void nts::Parser::addComponentToMap(std::unique_ptr<ChipsetsMap> &chipsetsMap, std::string line, std::vector<std::string> args) const
{
    std::vector<std::string> words;
    std::string chipsetName;
    std::string chipsetArg;

    if (line.find("#") != std::string::npos) {
        line = line.substr(0, line.find("#"));
    }
    std::istringstream iss(line);
    for (std::string word; iss >> word; words.push_back(word));
    if (words.size() != 2)
        throw nts::Exception::BadFileException("One given line is missed formatted", "Parser");
    if (words[1].find("(") != std::string::npos && (words[1].find(")") == std::string::npos || words[1].find(")") < words[1].find("("))) {
        throw nts::Exception::BadFileException("One given line is missed formatted", "Parser");
    } else if (words[1].find("(") != std::string::npos) {
        std::cout << words[1].length() << std::endl;
        std::cout << words[1].length() - words[1].find(")") << std::endl;
        chipsetArg = words[1].substr(words[1].find("(") + 1, words[1].length());
        chipsetArg = chipsetArg.substr(0, chipsetArg.find(")"));
        chipsetName = words[1].substr(0, words[1].find("("));
    } else {
        chipsetName = words[1];
    }
    if (chipsetArg != "" && (words[0] == "input" || words[0] == "clock"))
        throw nts::Exception::BadFileException("One given line is missed formatted", "Parser");
    if (std::find(componentsWithCommandLineArg.begin(), componentsWithCommandLineArg.end(), words[0]) != componentsWithCommandLineArg.end()) {
        std::vector<std::string>::iterator oui = std::find_if(args.begin(), args.end(), [chipsetName](const std::string &toFind) {return toFind.find(chipsetName + "=") != std::string::npos;});
        if (oui != args.end()) {
            chipsetArg.assign(*oui);
            chipsetArg = chipsetArg.substr(chipsetArg.find("=") + 1, chipsetArg.length());
            if (chipsetArg.compare("0") != 0 && chipsetArg.compare("1") != 0)
                throw nts::Exception::BadFileException("One given line is missed formatted", "Parser");
        } else {
            throw nts::Exception::BadFileException("One given component need an argument given from command line", "Parser");
        }
    }
    std::cout << "---new component---" << std::endl;
    std::cout << words[0] << std::endl;
    std::cout << chipsetName << std::endl;
    std::cout << chipsetArg << std::endl;
    std::cout << "---end of new component---" << std::endl;
    (void)chipsetsMap;
    //chipsetsMap->insert({chipsetName, nts::Factory::createComponent(words[0], chipsetArg)});
}

void nts::Parser::parseLinks(std::unique_ptr<ChipsetsMap> &chipsetsMap, std::ifstream &file) const
{
    std::string line;

    while (std::getline(file, line)) {
        if (line.length() == 0 || std::regex_match(line, commentLine) == true)
            continue;
        else if (std::regex_match(line, validLinksLine) == true) {
            linkComponents(chipsetsMap, line);
        } else {
            throw nts::Exception::BadFileException("One given line is missed formatted", "Parser");
        }
    }
}

void nts::Parser::parseChipsets(std::unique_ptr<ChipsetsMap> &chipsetsMap, std::ifstream &file, std::vector<std::string> args, std::string &line) const
{
    while (std::getline(file, line)) {
        if (line.length() == 0 || std::regex_match(line, commentLine) == true)
            continue;
        if (std::regex_match(line, linksRegex) == true) {
            break;
        }
        else if (std::regex_match(line, validChipsetLine) == true) {
            addComponentToMap(chipsetsMap, line, args);
        } else {
            throw nts::Exception::BadFileException("One given line is missed formatted", "Parser");
        }
    }
}

std::unique_ptr<nts::Parser::ChipsetsMap> nts::Parser::parseFile(int ac, const char *av[]) const
{
    std::ifstream file(this->_filename);
    std::string line;
    std::unique_ptr<nts::Parser::ChipsetsMap> chipsetsMap = std::make_unique<nts::Parser::ChipsetsMap>();
    std::vector<std::string> args(av + 1, av + ac);

    if (file.is_open() == false) {
        throw nts::Exception::BadFileException("Cannot open given file", "Parser");
    }
    while (std::getline(file, line)) {
        if (line.length() > 0 && std::regex_match(line, commentLine) == false)
            break;
    }
    if (std::regex_match(line, chipsetRegex) == false) {
        throw nts::Exception::NoChipsetSectionException("No chipsets section found", "Parser");
    }
    this->parseChipsets(chipsetsMap, file, args, line);
    if (std::regex_match(line, linksRegex) == false) {
        throw nts::Exception::NoLinksSectionException("No links section found", "Parser");
    }
    parseLinks(chipsetsMap, file);
    return chipsetsMap;
}