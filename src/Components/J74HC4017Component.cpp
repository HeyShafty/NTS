/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** J74HC4017Component
*/

#include <algorithm>
#include "Factory.hpp"
#include "Components/J74HC4017Component.hpp"

const std::vector<size_t> nts::Components::J74HC4017Component::indexes = {3, 2, 4, 7, 10, 1, 5, 6, 9, 11, 42};

nts::Components::J74HC4017Component::J74HC4017Component(const std::string &name)
    : AComponent("4017Component", name, 15), i(3), _oldClockValue(nts::Tristate::UNDEFINED)
{
    BIND_IN_PIN(12, J74HC4017Component);
    BIND_IN_PIN(13, J74HC4017Component);
    BIND_IN_PIN(14, J74HC4017Component);

    this->pins[2]->type = nts::PinType::OUT;
    this->pins[2]->compute = std::bind(&J74HC4017Component::computeComponent, this, 3);

    this->pins[1]->type = nts::PinType::OUT;
    this->pins[1]->compute = std::bind(&J74HC4017Component::computeComponent, this, 2);

    this->pins[3]->type = nts::PinType::OUT;
    this->pins[3]->compute = std::bind(&J74HC4017Component::computeComponent, this, 4);

    this->pins[6]->type = nts::PinType::OUT;
    this->pins[6]->compute = std::bind(&J74HC4017Component::computeComponent, this, 7);

    this->pins[9]->type = nts::PinType::OUT;
    this->pins[9]->compute = std::bind(&J74HC4017Component::computeComponent, this, 10);

    this->pins[0]->type = nts::PinType::OUT;
    this->pins[0]->compute = std::bind(&J74HC4017Component::computeComponent, this, 1);

    this->pins[4]->type = nts::PinType::OUT;
    this->pins[4]->compute = std::bind(&J74HC4017Component::computeComponent, this, 5);

    this->pins[5]->type = nts::PinType::OUT;
    this->pins[5]->compute = std::bind(&J74HC4017Component::computeComponent, this, 6);

    this->pins[8]->type = nts::PinType::OUT;
    this->pins[8]->compute = std::bind(&J74HC4017Component::computeComponent, this, 9);

    this->pins[10]->type = nts::PinType::OUT;
    this->pins[10]->compute = std::bind(&J74HC4017Component::computeComponent, this, 11);

    this->pins[11]->type = nts::PinType::OUT;
    this->pins[11]->compute = std::bind(&J74HC4017Component::compute12Pin, this);

    this->pins[7]->type = nts::PinType::ELECTRICAL;
}

nts::Tristate nts::Components::J74HC4017Component::computeComponent(size_t pin_index)
{
    nts::Tristate clock = this->pins[13]->compute();
    nts::Tristate reset = this->pins[14]->compute();

    if (clock == nts::Tristate::UNDEFINED || reset == nts::Tristate::UNDEFINED)
        return nts::Tristate::UNDEFINED;
    if (_oldClockValue == nts::Tristate::UNDEFINED) {
        _oldClockValue = clock;
        return nts::TRUE;
    }
    if (reset == 1)
        this->i = indexes[0];
    else if (clock == 1 && _oldClockValue == 0) {
        auto currentCounter = std::find(indexes.begin(), indexes.end(), this->i);
        this->i = *(currentCounter + 1);
        if (this->i == 42)
            this->i = indexes[0];
    }
    _oldClockValue = clock;
    if (pin_index == this->i)
        return nts::Tristate::TRUE;
    else
        return nts::Tristate::FALSE;
}

nts::Tristate nts::Components::J74HC4017Component::compute12Pin(void)
{
    size_t idx = 0;

    for (auto it = indexes.begin(); it != indexes.end(); ++it) {
        if (this->i == *it) {
            break;
        } else {
            idx++;
        }
    }
    if (idx >= 5) {
        return nts::Tristate::FALSE;
    } else {
        return nts::Tristate::TRUE;
    }
}