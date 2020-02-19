/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AndComponent
*/

#include "Components/AndComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::AndComponent::AndComponent()
    : Component("AndComponent", 3)
{
    this->pins[0]->compute = std::bind(&AndComponent::computeInPin, this, 0);
    this->pins[1]->compute = std::bind(&AndComponent::computeInPin, this, 1);
    this->pins[2]->type = PinType::OUT;
    this->pins[2]->compute = std::bind(&AndComponent::computeComponent, this);
}

nts::Tristate nts::Components::AndComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Pin is out of range.", "AndComponent");
    return this->pins[pin - 1]->compute();
}

nts::Tristate nts::Components::AndComponent::computeComponent() const
{
    return this->pins[0]->compute() && this->pins[1]->compute();
}
