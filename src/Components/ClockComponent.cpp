/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** ClockComponent
*/

#include "Components/ClockComponent.hpp"

nts::Components::ClockComponent::ClockComponent(nts::Tristate pinValue)
    : AComponent("clock", 1)
{
    this->pins[0]->type = nts::PinType::OUT;
    this->pins[0]->value = pinValue;
    this->pins[0]->compute = std::bind(&nts::Components::ClockComponent::computeCompoent, this);
}

nts::Tristate nts::Components::ClockComponent::computeCompoent(void)
{
    return this->pins[0]->value;
}

