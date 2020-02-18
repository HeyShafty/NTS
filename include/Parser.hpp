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

            using ChipsetsMap = std::unordered_map<std::string, std::unique_ptr<IComponent>>;

            std::unique_ptr<ChipsetsMap> parseFile(int ac, const char *av[]) const;
            void addComponentToMap(std::unique_ptr<ChipsetsMap> &chipsetsMap, std::string line, std::vector<std::string> args) const;
            void linkComponents(std::unique_ptr<ChipsetsMap> &chipsetsMap, std::string line) const;
            void parseChipsets(std::unique_ptr<ChipsetsMap> &chipsetsMap, std::ifstream &file, std::vector<std::string> args, std::string &line) const;
            void parseLinks(std::unique_ptr<ChipsetsMap> &chipsetsMap, std::ifstream &file) const;

            void setFilename(const std::string &filename);

            static const std::regex commentLine;
            static const std::regex chipsetRegex;
            static const std::regex validChipsetLine;
            static const std::regex linksRegex;
            static const std::regex validLinksLine;
            static const std::vector<std::string> componentsWithCommandLineArg;

        protected:
        private:
            std::string _filename;
    };
}

#endif /* !PARSER_HPP_ */
