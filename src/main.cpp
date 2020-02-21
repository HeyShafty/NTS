/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include <iostream>
#include "Parser.hpp"
#include "Simulator.hpp"

int main(int ac, char **av)
{
    if (ac < 2) {
        return 84;
    }
    nts::Simulator simulator;

    try
    {
        simulator.initSimulation(ac, av);
        simulator.runSimulation();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 84;
    }
    return 0;
}
