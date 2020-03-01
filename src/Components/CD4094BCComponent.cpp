/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CD4094BCComponent
*/

#include "Components/CD4094BCComponent.hpp"

nts::Components::CD4094BCComponent::CD4094BCComponent(const std::string &name)
    : AComponent("CD4094BCComponent", name, 16),
    clockSave(Tristate::UNDEFINED), value(0)
{
    BIND_IN_PIN(0, CD4094BCComponent); // Strobe
    BIND_IN_PIN(1, CD4094BCComponent); // Data
    BIND_IN_PIN(2, CD4094BCComponent); // Clock
    this->pins[3]->type = PinType::OUT; // Q1
    this->pins[3]->compute = std::bind(&CD4094BCComponent::computeComponent, this, 0);
    this->pins[4]->type = PinType::OUT; // Q2
    this->pins[4]->compute = std::bind(&CD4094BCComponent::computeComponent, this, 1);
    this->pins[5]->type = PinType::OUT; // Q3
    this->pins[5]->compute = std::bind(&CD4094BCComponent::computeComponent, this, 2);
    this->pins[6]->type = PinType::OUT; // Q4
    this->pins[6]->compute = std::bind(&CD4094BCComponent::computeComponent, this, 3);
    this->pins[7]->type = PinType::ELECTRICAL;
    this->pins[8]->type = PinType::OUT; // QS
    this->pins[8]->value = Tristate::FALSE;
    this->pins[8]->compute = std::bind(&CD4094BCComponent::computeComponent, this, -1);
    this->pins[9]->type = PinType::OUT; // Q'
    this->pins[9]->value = Tristate::FALSE;
    this->pins[9]->compute = std::bind(&CD4094BCComponent::computeComponent, this, -2);
    this->pins[10]->type = PinType::OUT; // Q8
    this->pins[10]->compute = std::bind(&CD4094BCComponent::computeComponent, this, 7);
    this->pins[11]->type = PinType::OUT; // Q7
    this->pins[11]->compute = std::bind(&CD4094BCComponent::computeComponent, this, 6);
    this->pins[12]->type = PinType::OUT; // Q6
    this->pins[12]->compute = std::bind(&CD4094BCComponent::computeComponent, this, 5);
    this->pins[13]->type = PinType::OUT; // Q5
    this->pins[13]->compute = std::bind(&CD4094BCComponent::computeComponent, this, 4);
    BIND_IN_PIN(14, CD4094BCComponent); // Output enable
    this->pins[15]->type = PinType::ELECTRICAL;
}

nts::Tristate nts::Components::CD4094BCComponent::computeComponent(int q)
{
    Tristate strobe = this->pins[0]->compute();
    Tristate data = this->pins[1]->compute();
    Tristate clock = this->pins[2]->compute();
    Tristate enable = this->pins[14]->compute();
    Tristate prevClock = this->clockSave;

    if (strobe == UNDEFINED || data == UNDEFINED || clock == UNDEFINED || enable == UNDEFINED)
        return Tristate::UNDEFINED;
    this->clockSave = clock;
    if (strobe == Tristate::TRUE) {
        if (prevClock == FALSE && clock == TRUE) {
            this->value <<= 1;
            this->value += data;
        }
    }
    if (prevClock == FALSE && clock == TRUE)
        this->pins[8]->value = (Tristate)((this->value >> 7) & 0x1);
    if (enable == FALSE || strobe == TRUE) {
        if (prevClock == TRUE && clock == FALSE) {
            this->pins[9]->value = (Tristate)((this->value >> 7) & 0x1);
        }
    }
    if (enable == FALSE)
        return Tristate::TRUE;
    if (q >= 0)
        return (Tristate)((this->value >> q) & 0x1);
    else
        return this->pins[q == -1 ? 8 : 9]->value;
}
