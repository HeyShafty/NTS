/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Simulator
*/

#ifndef SIMULATOR_HPP_
#define SIMULATOR_HPP_

#include <map>
#include "AComponent.hpp"
#include "Parser.hpp"

namespace nts
{
    class Simulator
    {
        public:
            Simulator();
            ~Simulator() = default;

            void initSimulation(int ac, char **av);
            void runSimulation(void) const;
            int displayOutputs(void) const;
            int exitSimulation(void) const;
            int simulate(void) const;
            int loop(void) const;
            int dump(void) const;

            static void signalHandler(int sig);

            static bool isLooping;
        private:
            IComponent *findComponent(std::string toFind) const;
            void initChipsets(nts::Parser::ChipsetsMap &chipsetsMap, nts::Parser &parser, const std::vector<std::string> args);
            void initLinks(nts::Parser::ChipsetsMap &chipsetsMap, nts::Parser &parser) const;
            static const std::map<std::string, int (nts::Simulator::*)(void) const> functionnalitiesMap;

            std::map<std::string, std::unique_ptr<IComponent>> outputComponents;
            std::map<std::string, std::unique_ptr<IComponent>> inputComponents;
            std::map<std::string, std::unique_ptr<IComponent>> clockComponents;
            std::map<std::string, std::unique_ptr<IComponent>> otherComponents;
    };
}

#endif /* !SIMULATOR_HPP_ */
