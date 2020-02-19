/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** FalseComponent
*/

#include "Components/FalseComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::FalseComponent::FalseComponent()
    : Component("FalseComponent", 1)
{
    this->pins[0]->type = PinType::OUT;
    this->pins[0]->compute = std::bind(&FalseComponent::computeComponent, this);
}

nts::Tristate nts::Components::FalseComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Pin is out of range.", "FalseComponent");
    return this->pins[pin - 1]->compute();
}

nts::Tristate nts::Components::FalseComponent::computeComponent() const
{
    return Tristate::FALSE;
}
