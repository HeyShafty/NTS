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
#include "ISimulable.hpp"
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

        private:
            static void signalHandler(int sig);
            static bool isLooping;

            int displayOutputs(void) const;
            int exitSimulation(void) const;
            int simulate(void) const;
            int loop(void) const;
            int dump(void) const;
            IComponent *findComponent(std::string toFind) const;
            void initChipsets(nts::Parser::ChipsetsMap &chipsetsMap, nts::Parser &parser, const std::vector<std::string> args);
            void initLinks(nts::Parser::ChipsetsMap &chipsetsMap, nts::Parser &parser) const;
            static const std::map<std::string, int (nts::Simulator::*)(void) const> functionnalitiesMap;

            std::map<std::string, std::shared_ptr<IComponent>> components;
            std::map<std::string, std::shared_ptr<IComponent>> outputComponents;
            std::map<std::string, std::shared_ptr<IComponent>> inputComponents;
            std::vector<std::shared_ptr<ISimulable>> simulableComponents;
    };
}

#endif /* !SIMULATOR_HPP_ */
