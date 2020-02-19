/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** DFlipFlopComponent
*/

#include "Components/DFlipFlopComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::DFlipFlopComponent::DFlipFlopComponent()
    : Component("DFlipFlopComponent", 6), currClock(Tristate::UNDEFINED)
{
    this->pins[Q]->type = PinType::OUT;
    this->pins[Q]->compute = [this]() {
        this->computeComponent();
        return this->pins[Q]->value;
    };
    this->pins[NQ]->type = PinType::OUT;
    this->pins[NQ]->compute = [this]() {
        this->computeComponent();
        return this->pins[NQ]->value;
    };
    this->pins[2]->compute = std::bind(&DFlipFlopComponent::computeInPin, this, 2);
    this->pins[3]->compute = std::bind(&DFlipFlopComponent::computeInPin, this, 3);
    this->pins[4]->compute = std::bind(&DFlipFlopComponent::computeInPin, this, 4);
    this->pins[5]->compute = std::bind(&DFlipFlopComponent::computeInPin, this, 5);
}

nts::Tristate nts::Components::DFlipFlopComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Pin is out of range.", "DFlipFlopComponent");
    return this->pins[pin - 1]->compute();
}

void nts::Components::DFlipFlopComponent::computeComponent()
{
    Tristate clock = this->pins[CLOCK]->compute();
    Tristate reset = this->pins[RESET]->compute();
    Tristate data = this->pins[DATA]->compute();
    Tristate set = this->pins[SET]->compute();
    Tristate prevClock = this->currClock;
    Tristate states[6] = {UNDEFINED, prevClock, clock, reset, data, set};

    this->currClock = clock;
    this->pins[Q]->value = this->computeQPin(states);
    this->pins[NQ]->value = this->computeNotQPin(states);
}

nts::Tristate nts::Components::DFlipFlopComponent::computeQPin(const Tristate * const states)
{
    if ((states[RESET] && states[SET]) == Tristate::UNDEFINED)
        return Tristate::UNDEFINED;
    else if (states[SET] == Tristate::TRUE)
        return Tristate::TRUE;
    else if (states[RESET] == Tristate::TRUE)
        return Tristate::FALSE;
    else if (IS_ASCENDANT(states[1], this->currClock))
        return states[DATA];
    else if (IS_DESCENDANT(states[1], this->currClock))
        return this->pins[Q]->value;
    return Tristate::UNDEFINED;
}

nts::Tristate nts::Components::DFlipFlopComponent::computeNotQPin(const Tristate * const states)
{
    if ((states[RESET] && states[SET]) == Tristate::UNDEFINED)
        return Tristate::UNDEFINED;
    else if (states[RESET] == Tristate::TRUE)
        return Tristate::TRUE;
    else if (states[SET] == Tristate::TRUE)
        return Tristate::FALSE;
    else if (IS_ASCENDANT(states[1], this->currClock))
        return ~states[DATA];
    else if (IS_DESCENDANT(states[1], this->currClock))
        return this->pins[NQ]->value;
    return Tristate::UNDEFINED;
}
