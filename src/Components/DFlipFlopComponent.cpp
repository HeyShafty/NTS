/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** DFlipFlopComponent
*/

#include "Components/DFlipFlopComponent.hpp"
#include "Exceptions/WrongPinException.hpp"
#include "Factory.hpp"

nts::Components::DFlipFlopComponent::DFlipFlopComponent()
    : AComponent("DFlipFlopComponent", 6), clockSave(Tristate::UNDEFINED)
{
    this->pins[0]->type = PinType::OUT;
    this->pins[0]->value = Tristate::UNDEFINED;
    this->pins[0]->compute = std::bind(&DFlipFlopComponent::computeComponent, this, 0);
    this->pins[1]->type = PinType::OUT;
    this->pins[1]->value = Tristate::UNDEFINED;
    this->pins[1]->compute = std::bind(&DFlipFlopComponent::computeComponent, this, 1);
    BIND_IN_PIN(2, DFlipFlopComponent);
    BIND_IN_PIN(3, DFlipFlopComponent);
    BIND_IN_PIN(4, DFlipFlopComponent);
    BIND_IN_PIN(5, DFlipFlopComponent);
}

nts::Tristate nts::Components::DFlipFlopComponent::computeComponent(size_t pin_index)
{
    Tristate clock = this->pins[2]->compute();
    Tristate prevClock = this->clockSave;

    this->clockSave = clock;
    this->pins[0]->value = this->computeQPin(clock, prevClock);
    this->pins[1]->value = this->computeNQPin(clock, prevClock);
    return this->pins[pin_index]->value;
}

nts::Tristate nts::Components::DFlipFlopComponent::computeQPin(nts::Tristate clock, nts::Tristate prevClock)
{
    Tristate reset = this->pins[3]->compute();
    Tristate data = this->pins[4]->compute();
    Tristate set = this->pins[5]->compute();

    if (clock == UNDEFINED || reset == UNDEFINED || data == UNDEFINED || set == UNDEFINED)
        return UNDEFINED;
    if (reset == TRUE && set == TRUE)
        return TRUE;
    if (set == TRUE)
        return TRUE;
    if (reset == TRUE)
        return FALSE;
    if (prevClock == TRUE && clock == FALSE)
        return this->pins[0]->value;
    if (prevClock == FALSE && clock == TRUE)
        return data;
    return this->pins[0]->value;
}

nts::Tristate nts::Components::DFlipFlopComponent::computeNQPin(nts::Tristate clock, nts::Tristate prevClock)
{
    Tristate reset = this->pins[3]->compute();
    Tristate data = this->pins[4]->compute();
    Tristate set = this->pins[5]->compute();

    if (clock == UNDEFINED || reset == UNDEFINED || data == UNDEFINED || set == UNDEFINED)
        return UNDEFINED;
    if (reset == TRUE && set == TRUE)
        return TRUE;
    if (set == TRUE)
        return FALSE;
    if (reset == TRUE)
        return TRUE;
    if (prevClock == TRUE && clock == FALSE)
        return this->pins[1]->value;
    if (prevClock == FALSE && clock == TRUE)
        return !data;
    return this->pins[1]->value;
}
