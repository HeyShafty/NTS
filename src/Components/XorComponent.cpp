/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** XorComponent
*/

#include "Components/XorComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::XorComponent::XorComponent(const std::string &name)
    : AComponent("XorComponent", name, 3)
{
    BIND_IN_PIN(0, XorComponent);
    BIND_IN_PIN(1, XorComponent);
    this->pins[2]->type = PinType::OUT;
    this->pins[2]->compute = std::bind(&XorComponent::computeComponent, this);
}

nts::Tristate nts::Components::XorComponent::computeComponent() const
{
    return this->pins[0]->compute() ^ this->pins[1]->compute();
}
