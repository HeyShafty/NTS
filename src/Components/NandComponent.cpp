/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NandComponent
*/

#include "Components/NandComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::NandComponent::NandComponent(const std::string &name)
    : AComponent("NandComponent", name, 3)
{
    BIND_IN_PIN(0, NandComponent);
    BIND_IN_PIN(1, NandComponent);
    this->pins[2]->type = PinType::OUT;
    this->pins[2]->compute = std::bind(&NandComponent::computeComponent, this);
}

nts::Tristate nts::Components::NandComponent::computeComponent() const
{
    return !(this->pins[0]->compute() && this->pins[1]->compute());
}
