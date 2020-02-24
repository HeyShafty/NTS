/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** MC14040B
*/

#include "Components/MC14040BComponent.hpp"
#include "Factory.hpp"

nts::Components::MC14040BComponent::MC14040BComponent()
    : AComponent("4040Component", 16), _value(0), oldClockValue(nts::Tristate::UNDEFINED)
{
    BIND_IN_PIN(9, MC14040BComponent);
    BIND_IN_PIN(10, MC14040BComponent);

    this->pins[0]->type = nts::PinType::OUT;
    this->pins[0]->compute = std::bind(&MC14040BComponent::computeComponent, this, 1);

    this->pins[1]->type = nts::PinType::OUT;
    this->pins[1]->compute = std::bind(&MC14040BComponent::computeComponent, this, 2);

    this->pins[2]->type = nts::PinType::OUT;
    this->pins[2]->compute = std::bind(&MC14040BComponent::computeComponent, this, 3);

    this->pins[3]->type = nts::PinType::OUT;
    this->pins[3]->compute = std::bind(&MC14040BComponent::computeComponent, this, 4);

    this->pins[4]->type = nts::PinType::OUT;
    this->pins[4]->compute = std::bind(&MC14040BComponent::computeComponent, this, 5);

    this->pins[5]->type = nts::PinType::OUT;
    this->pins[5]->compute = std::bind(&MC14040BComponent::computeComponent, this, 6);

    this->pins[6]->type = nts::PinType::OUT;
    this->pins[6]->compute = std::bind(&MC14040BComponent::computeComponent, this, 7);

    this->pins[8]->type = nts::PinType::OUT;
    this->pins[8]->compute = std::bind(&MC14040BComponent::computeComponent, this, 9);

    this->pins[11]->type = nts::PinType::OUT;
    this->pins[11]->compute = std::bind(&MC14040BComponent::computeComponent, this, 12);

    this->pins[12]->type = nts::PinType::OUT;
    this->pins[12]->compute = std::bind(&MC14040BComponent::computeComponent, this, 13);

    this->pins[13]->type = nts::PinType::OUT;
    this->pins[13]->compute = std::bind(&MC14040BComponent::computeComponent, this, 14);

    this->pins[14]->type = nts::PinType::OUT;
    this->pins[14]->compute = std::bind(&MC14040BComponent::computeComponent, this, 15);

    this->pins[7]->type = nts::PinType::ELECTRICAL;
    this->pins[15]->type = nts::PinType::ELECTRICAL;
}

nts::Tristate nts::Components::MC14040BComponent::computeComponent(size_t pin_idx)
{
    nts::Tristate clock = this->pins[9]->compute();
    nts::Tristate reset = this->pins[10]->compute();
    std::vector<int> values = {11, 5, 4, 6, 3, 2, 1, 0, 0, 0, 0, 8, 7, 9, 10};

    if (clock == nts::Tristate::UNDEFINED || reset == nts::Tristate::UNDEFINED)
        return nts::Tristate::UNDEFINED;
    if (reset == 1) {
        this->_value = 0;
        return nts::Tristate::FALSE;
    }
    if (this->oldClockValue == nts::Tristate::UNDEFINED) {
        this->oldClockValue = clock;
        return nts::Tristate::FALSE;
    } else if (oldClockValue == nts::Tristate::TRUE && clock == nts::Tristate::FALSE) {
        if (this->_value == 0b111111111111) {
            this->_value = 0;
        } else {
            this->_value++;
        }
    }
    oldClockValue = clock;
    return (nts::Tristate)((this->_value >> values[pin_idx - 1]) & 0x1);
}