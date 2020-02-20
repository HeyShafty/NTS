/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** OrComponent
*/

#include "Components/OrComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::OrComponent::OrComponent()
    : AComponent("OrComponent", 3)
{
    BIND_IN_PIN(0, OrComponent);
    BIND_IN_PIN(1, OrComponent);
    this->pins[2]->type = PinType::OUT;
    this->pins[2]->compute = std::bind(&OrComponent::computeComponent, this);
}

nts::Tristate nts::Components::OrComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Pin is out of range.", "OrComponent");
    return this->pins[pin - 1]->compute();
}

nts::Tristate nts::Components::OrComponent::computeComponent() const
{
    return this->pins[0]->compute() || this->pins[1]->compute();
}
