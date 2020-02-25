/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** TerminalComponent
*/

#include <iostream>
#include "Components/TerminalComponent.hpp"

nts::Components::TerminalComponent::TerminalComponent(const std::string &name)
    : AComponent("TerminalComponent", name, 9)
{
    BIND_IN_PIN(0, TerminalComponent);
    BIND_IN_PIN(1, TerminalComponent);
    BIND_IN_PIN(2, TerminalComponent);
    BIND_IN_PIN(3, TerminalComponent);
    BIND_IN_PIN(4, TerminalComponent);
    BIND_IN_PIN(5, TerminalComponent);
    BIND_IN_PIN(6, TerminalComponent);
    BIND_IN_PIN(7, TerminalComponent);
    BIND_IN_PIN(8, TerminalComponent); // Write enabled
}

void nts::Components::TerminalComponent::simulate() const
{
    Tristate bit1 = this->pins[0]->compute();
    Tristate bit2 = this->pins[1]->compute();
    Tristate bit3 = this->pins[2]->compute();
    Tristate bit4 = this->pins[3]->compute();
    Tristate bit5 = this->pins[4]->compute();
    Tristate bit6 = this->pins[5]->compute();
    Tristate bit7 = this->pins[6]->compute();
    Tristate bit8 = this->pins[7]->compute();
    char bit = 0;

    if (this->pins[8]->compute() != Tristate::TRUE)
        return;
    if (bit1 == UNDEFINED || bit2 == UNDEFINED || bit3 == UNDEFINED || bit4 == UNDEFINED
    || bit5 == UNDEFINED || bit6 == UNDEFINED || bit7 == UNDEFINED || bit8 == UNDEFINED)
        return;
    bit += bit8 << 7 | bit7 << 6 | bit6 << 5 | bit5 << 4
         | bit4 << 3 | bit3 << 2 | bit2 << 1 | bit1;
    std::cerr << bit << std::endl;
}
