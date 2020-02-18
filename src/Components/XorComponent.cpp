/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** XorComponent
*/

#include "Components/XorComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::XorComponent::XorComponent()
    : Component("XorComponent", 3)
{
    this->pins[0]->compute = std::bind(&XorComponent::computeInPin, this, 0);
    this->pins[1]->compute = std::bind(&XorComponent::computeInPin, this, 1);
    this->pins[2]->type = PinType::OUT;
    this->pins[2]->compute = std::bind(&XorComponent::computeComponent, this);
}

nts::Tristate nts::Components::XorComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Pin is out of range.", "XorComponent");
    return this->pins[pin - 1]->compute();
}

nts::Tristate nts::Components::XorComponent::computeComponent() const
{
    return this->pins[0]->compute() ^ this->pins[1]->compute();
}
