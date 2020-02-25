/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** TripleNandComponent
*/

#include "Components/TripleNandComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::TripleNandComponent::TripleNandComponent(const std::string &name)
    : AComponent("TripleNandComponent", name, 4)
{
    BIND_IN_PIN(0, TripleNandComponent);
    BIND_IN_PIN(1, TripleNandComponent);
    BIND_IN_PIN(2, TripleNandComponent);
    this->pins[3]->type = PinType::OUT;
    this->pins[3]->compute = std::bind(&TripleNandComponent::computeComponent, this);
}

nts::Tristate nts::Components::TripleNandComponent::computeComponent() const
{
    nts::Tristate result = this->pins[0]->compute() && this->pins[1]->compute() && this->pins[2]->compute();

    return !result;
}
