/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <string>
#include <unordered_map>
#include <regex>
#include <vector>
#include "IComponent.hpp"

namespace nts
{
    class Parser
    {
        public:
            Parser(const std::string &filename);
            ~Parser();

            struct Link {
                std::string componentName;
                int pinNumber;
            };

            using ChipsetsMap = std::unordered_map<std::string, std::vector<std::string>>;
            using LinksVector = std::vector<std::tuple<Link, Link>>;

            void addComponentToMap(ChipsetsMap &chipsetsMap, std::string line, std::vector<std::string> args) const;
            void addLinkToMap(LinksVector &chipsetsMap, ChipsetsMap &chipsetMap, std::string line) const;
            ChipsetsMap parseChipsets(std::vector<std::string> args) const;
            LinksVector parseLinks(ChipsetsMap &chipsetMap) const;

            void setFilename(const std::string &filename);

            static const std::regex commentLine;
            static const std::regex chipsetRegex;
            static const std::regex validChipsetLine;
            static const std::regex linksRegex;
            static const std::regex validLinksLine;
            static const std::regex commandLineRegex;
            static const std::vector<std::string> componentsWithCommandLineArg;

        protected:
        private:
            std::string _filename;
    };
}

#endif /* !PARSER_HPP_ */
