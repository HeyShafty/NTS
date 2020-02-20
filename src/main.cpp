/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include <stdio.h>
#include <stdbool.h>
#include "Components/TrueComponent.hpp"
#include "Components/FalseComponent.hpp"
#include "Components/DFlipFlopComponent.hpp"
#include "Components/AndComponent.hpp"
#include "Components/HCF4081BComponent.hpp"
#include "Components/SumComponent.hpp"

// int toto(int argc, char *argv[])
// {
    // std::unique_ptr<nts::IComponent> c4081(new nts::Components::HCF4081BComponent);
//     std::unique_ptr<nts::IComponent> cAnd(new nts::Components::AndComponent);
//     std::unique_ptr<nts::IComponent> cFalse1(new nts::Components::TrueComponent);
//     std::unique_ptr<nts::IComponent> cFalse2(new nts::Components::TrueComponent);


//     (void)argc;
//     (void)argv;
//     printf("%d\n", cAnd->compute(3));
//     cAnd->setLink(1, *cFalse1, 1);
//     printf("%d\n", cAnd->compute(3));
//     cAnd->setLink(2, *cFalse2, 1);
//     printf("%d\n", cAnd->compute(3));
//     c4081->setLink(1, *cFalse1, 1);
//     c4081->setLink(2, *cFalse2, 1);
//     printf("%d %d %d %d\n", c4081->compute(3), c4081->compute(6), c4081->compute(10), c4081->compute(13));
//     return (0);
// }

// int toto2(void)
// {
//     std::unique_ptr<nts::IComponent> clock(new nts::Components::FalseComponent);
//     std::unique_ptr<nts::IComponent> reset(new nts::Components::FalseComponent);
//     std::unique_ptr<nts::IComponent> data(new nts::Components::FalseComponent);
//     std::unique_ptr<nts::IComponent> set(new nts::Components::FalseComponent);
//     std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::DFlipFlopComponent);

//     dFlipFlop->setLink(3, *clock, 1);
//     dFlipFlop->setLink(4, *reset, 1);
//     dFlipFlop->setLink(5, *data, 1);
//     dFlipFlop->setLink(6, *set, 1);
//     printf("%d\n", dFlipFlop->compute(1));
//     printf("%d\n", dFlipFlop->compute(1));
//     printf("%d\n", dFlipFlop->compute(1));
// }

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
