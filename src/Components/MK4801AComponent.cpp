/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** MK4801AComponent
*/

#include <fstream>
#include "Components/MK4801AComponent.hpp"
#include "Exceptions/WrongPinException.hpp"
#include "Exceptions/BadFileException.hpp"

nts::Components::MK4801AComponent::MK4801AComponent(const std::string &name)
    : AComponent("MK4801AComponent", name, 24)
{
    BIND_IN_PIN(0, MK4801AComponent); // A7
    BIND_IN_PIN(1, MK4801AComponent); // A6
    BIND_IN_PIN(2, MK4801AComponent); // A5
    BIND_IN_PIN(3, MK4801AComponent); // A4
    BIND_IN_PIN(4, MK4801AComponent); // A3
    BIND_IN_PIN(5, MK4801AComponent); // A2
    BIND_IN_PIN(6, MK4801AComponent); // A1
    BIND_IN_PIN(7, MK4801AComponent); // A0
    BIND_PIN(8); // Q0
    BIND_PIN(9); // Q1
    BIND_PIN(10); // Q2
    this->pins[11]->type = PinType::ELECTRICAL; // VSS
    BIND_PIN(12); // Q3
    BIND_PIN(13); // Q4
    BIND_PIN(14); // Q5
    BIND_PIN(15); // Q6
    BIND_PIN(16); // Q7
    BIND_IN_PIN(17, MK4801AComponent); // CE
    BIND_IN_PIN(18, MK4801AComponent); // NC
    BIND_IN_PIN(19, MK4801AComponent); // OE
    BIND_IN_PIN(20, MK4801AComponent); // WE
    BIND_IN_PIN(21, MK4801AComponent); // A9
    BIND_IN_PIN(22, MK4801AComponent); // A8
    this->pins[23]->type = PinType::ELECTRICAL; // VCC
}

nts::Tristate nts::Components::MK4801AComponent::computeComponent(size_t pin_index) const
{
    // if (this->pins[17]->compute() != Tristate::TRUE || this->pins[19]->compute() != Tristate::TRUE)
    //     return Tristate::UNDEFINED;
    int x = this->xDecode();
    int y = this->yDecode();
    unsigned char byte;

    if (x == -1 || y == -1)
        return Tristate::UNDEFINED;
    byte = this->mem[y * 128 + x];
    this->pins[8]->value = (Tristate)((byte >> 7) & 0x1); // Q0
    this->pins[9]->value = (Tristate)((byte >> 6) & 0x1); // Q1
    this->pins[10]->value = (Tristate)((byte >> 5) & 0x1); // Q2
    this->pins[12]->value = (Tristate)((byte >> 4) & 0x1); // Q3
    this->pins[13]->value = (Tristate)((byte >> 3) & 0x1); // Q4
    this->pins[14]->value = (Tristate)((byte >> 2) & 0x1); // Q5
    this->pins[15]->value = (Tristate)((byte >> 1) & 0x1); // Q6
    this->pins[16]->value = (Tristate)(byte & 0x1); // Q7
    return this->pins[pin_index]->value;
}

void nts::Components::MK4801AComponent::simulate() const
{
    throw "Wow";
}

int nts::Components::MK4801AComponent::xDecode() const
{
    int x = 0;
    Tristate bit1 = this->pins[7]->compute(); // A0
    Tristate bit2 = this->pins[5]->compute(); // A2
    Tristate bit3 = this->pins[4]->compute(); // A3
    Tristate bit4 = this->pins[3]->compute(); // A4
    Tristate bit5 = this->pins[2]->compute(); // A5
    Tristate bit6 = this->pins[0]->compute(); // A7
    Tristate bit7 = this->pins[21]->compute(); // A9

    if (bit1 == UNDEFINED || bit2 == UNDEFINED || bit3 == UNDEFINED || bit4 == UNDEFINED
    || bit5 == UNDEFINED || bit6 == UNDEFINED || bit7 == UNDEFINED)
        return -1;
    x += bit7 << 6 | bit6 << 5 | bit5 << 4 | bit4 << 3 | bit3 << 2 | bit2 << 1 | bit1;
    return x;
}

int nts::Components::MK4801AComponent::yDecode() const
{
    int y = 0;
    Tristate bit1 = this->pins[6]->compute(); // A1
    Tristate bit2 = this->pins[1]->compute(); // A6
    Tristate bit3 = this->pins[22]->compute(); // A8

    if (bit1 == UNDEFINED || bit2 == UNDEFINED || bit3 == UNDEFINED)
        return -1;
    y += bit3 << 2 | bit2 << 1 | bit1;
    return y;
}
