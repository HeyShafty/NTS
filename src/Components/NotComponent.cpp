/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NotComponent
*/

#include "Components/NotComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::NotComponent::NotComponent()
    : AComponent("NotComponent", 2)
{
    BIND_IN_PIN(0, NotComponent);
    this->pins[1]->type = PinType::OUT;
    this->pins[1]->compute = std::bind(&NotComponent::computeComponent, this);
}

nts::Tristate nts::Components::NotComponent::computeComponent() const
{
    return !this->pins[0]->compute();
}
