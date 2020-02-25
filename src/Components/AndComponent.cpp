/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AndComponent
*/

#include "Components/AndComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::AndComponent::AndComponent(const std::string &name)
    : AComponent("AndComponent", name, 3)
{
    BIND_IN_PIN(0, AndComponent);
    BIND_IN_PIN(1, AndComponent);
    this->pins[2]->type = PinType::OUT;
    this->pins[2]->compute = std::bind(&AndComponent::computeComponent, this);
}

nts::Tristate nts::Components::AndComponent::computeComponent() const
{
    return this->pins[0]->compute() && this->pins[1]->compute();
}
