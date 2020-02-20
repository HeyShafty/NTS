/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NorComponent
*/

#include "Components/NorComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::NorComponent::NorComponent()
    : AComponent("NorComponent", 3)
{
    BIND_IN_PIN(0, NorComponent);
    BIND_IN_PIN(1, NorComponent);
    this->pins[2]->type = PinType::OUT;
    this->pins[2]->compute = std::bind(&NorComponent::computeComponent, this);
}

nts::Tristate nts::Components::NorComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Pin is out of range.", "NorComponent");
    return this->pins[pin - 1]->compute();
}

nts::Tristate nts::Components::NorComponent::computeComponent() const
{
    return !(this->pins[0]->compute() || this->pins[1]->compute());
}
