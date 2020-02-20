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
#include "Exceptions/CircuitFileException.hpp"
#include "Exceptions/NoChipsetSectionException.hpp"
#include "Exceptions/NoLinksSectionException.hpp"

const std::regex nts::Parser::commentLine("^\\s*[#].*");
const std::regex nts::Parser::validChipsetLine("^\\S+\\s+\\S+\\s*(#.*)?");
const std::regex nts::Parser::linksRegex("\\.links:\\s*#?");
const std::regex nts::Parser::validLinksLine("^\\S+:\\d+\\s+\\S+:\\d+\\s*(#.*)?");
const std::regex nts::Parser::chipsetRegex("\\.chipsets:\\s*#?");
const std::regex nts::Parser::commandLineRegex("^\\S+=[01]");
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

void nts::Parser::addLinkToMap(LinksVector &linksVector, ChipsetsMap &chipsetMap, std::string line) const
{
    std::vector<std::string> words;

    if (line.find("#") != std::string::npos) {
        line = line.substr(0, line.find("#"));
    }
    std::istringstream iss(line);
    for (std::string word; iss >> word; words.push_back(word));
    if (words.size() != 2)
        throw nts::Exception::CircuitFileException("One given line is missed formatted", "Parser");
    std::string c1 = words[0].substr(0, words[0].find(":"));
    std::string c2 = words[1].substr(0, words[1].find_last_of(":"));
    int p1 = std::stoi(words[0].substr(words[0].find(":") + 1));
    int p2 = std::stoi(words[1].substr(words[1].find(":") + 1));
    if (chipsetMap.find(c1) == chipsetMap.end() || chipsetMap.find(c2) == chipsetMap.end()) {
        throw nts::Exception::CircuitFileException("One given component name in link section does not correspond to any component", "Parser");
    }
    linksVector.push_back({{c1, p1}, {c2, p2}});
}

void nts::Parser::addComponentToMap(ChipsetsMap &chipsetsMap, std::string line, std::vector<std::string> args) const
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
        throw nts::Exception::CircuitFileException("One given line is missed formatted", "Parser");
    if (words[1].find("(") != std::string::npos && (words[1].find(")") == std::string::npos || words[1].find(")") < words[1].find("("))) {
        throw nts::Exception::CircuitFileException("One given line is missed formatted", "Parser");
    } else if (words[1].find("(") != std::string::npos) {
        chipsetArg = words[1].substr(words[1].find("(") + 1);
        chipsetArg = chipsetArg.substr(0, chipsetArg.find(")"));
        chipsetName = words[1].substr(0, words[1].find("("));
    } else {
        chipsetName = words[1];
    }
    if (std::find(componentsWithCommandLineArg.begin(), componentsWithCommandLineArg.end(), words[0]) != componentsWithCommandLineArg.end()) {
        auto chipsetCommandLineArg = std::find_if(args.begin(), args.end(), [chipsetName](const std::string &toFind) {return toFind.find(chipsetName + "=") != std::string::npos;});
        if (chipsetCommandLineArg != args.end()) {
            chipsetArg.assign(*chipsetCommandLineArg);
            if (std::regex_match(chipsetArg, commandLineRegex) == false) {
                throw nts::Exception::CircuitFileException("One given argument is missed formatted", "Parser");
            }
            chipsetArg = chipsetArg.substr(chipsetArg.find("=") + 1);
        } else {
            throw nts::Exception::CircuitFileException("One given component need an argument given from command line", "Parser");
        }
    }
    if (chipsetsMap.find(chipsetName) != chipsetsMap.end()) {
        throw nts::Exception::CircuitFileException("One given component has the name of another component.", "Parser");
    }
    chipsetsMap.insert({chipsetName, {words[0], chipsetArg}});
}

nts::Parser::LinksVector nts::Parser::parseLinks(ChipsetsMap &chipsetMap) const
{
    std::string line;
    std::ifstream file(this->_filename);
    LinksVector linksMap;

    if (file.is_open() == false) {
        throw nts::Exception::CircuitFileException("Cannot open given file", "Parser");
    }
    while (std::getline(file, line)) {
        if (std::regex_match(line, linksRegex) == true)
            break;
    }
    if (std::regex_match(line, linksRegex) == false) {
        throw nts::Exception::NoChipsetSectionException("No links section found", "Parser");
    }
    while (std::getline(file, line)) {
        if (line.length() == 0 || std::regex_match(line, commentLine) == true)
            continue;
        else if (std::regex_match(line, validLinksLine) == true) {
            addLinkToMap(linksMap, chipsetMap, line);
        } else {
            throw nts::Exception::CircuitFileException("One given line is misformatted", "Parser");
        }
    }
    file.close();
    return linksMap;
}

nts::Parser::ChipsetsMap nts::Parser::parseChipsets(std::vector<std::string> args) const
{
    std::ifstream file(this->_filename);
    std::string line;
    ChipsetsMap chipsetsMap;

    if (file.is_open() == false) {
        throw nts::Exception::CircuitFileException("Cannot open given file", "Parser");
    }
    while (std::getline(file, line)) {
        if (std::regex_match(line, chipsetRegex) == true)
            break;
    }
    if (std::regex_match(line, chipsetRegex) == false) {
        throw nts::Exception::NoChipsetSectionException("No chipsets section found", "Parser");
    }
    while (std::getline(file, line)) {
        if (line.length() == 0 || std::regex_match(line, commentLine) == true) {
            continue;
        }
        if (std::regex_match(line, linksRegex) == true) {
            break;
        }
        else if (std::regex_match(line, validChipsetLine) == true) {
            addComponentToMap(chipsetsMap, line, args);
        } else {
            throw nts::Exception::CircuitFileException("One given line is misformatted", "Parser");
        }
    }
    file.close();
    return chipsetsMap;
}
