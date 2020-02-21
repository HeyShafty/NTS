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

namespace nts
{
    class Simulator
    {
        public:
            Simulator();
            ~Simulator() = default;

            IComponent *findComponent(std::string toFind);

            void initSimulation(int ac, char **av);
            void runSimulation(void);
            int displayOutputs(void);
            int exitSimulation(void);
            int simulate(void);
            int loop(void);
            static void signalHandler(int sig);
            int dump(void);

            static const std::map<std::string, int (nts::Simulator::*)(void)> functionnalitiesMap;
            static bool isLooping;
        private:
            std::map<std::string, std::unique_ptr<IComponent>> outputComponents;
            std::map<std::string, std::unique_ptr<IComponent>> inputComponents;
            std::map<std::string, std::unique_ptr<IComponent>> otherComponents;
    };
}

#endif /* !SIMULATOR_HPP_ */
