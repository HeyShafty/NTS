/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** OrComponent
*/

#include "Components/OrComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::OrComponent::OrComponent(const std::string &name)
    : AComponent("OrComponent", name, 3)
{
    BIND_IN_PIN(0, OrComponent);
    BIND_IN_PIN(1, OrComponent);
    this->pins[2]->type = PinType::OUT;
    this->pins[2]->compute = std::bind(&OrComponent::computeComponent, this);
}

nts::Tristate nts::Components::OrComponent::computeComponent() const
{
    return this->pins[0]->compute() || this->pins[1]->compute();
}
