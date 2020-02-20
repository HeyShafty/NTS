/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** t'as le seum
*/

#include "Components/SumComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::SumComponent::SumComponent()
    : Component("Sum", 5)
{
    this->pins[0]->type = PinType::IN;
    this->pins[0]->compute = std::bind(&SumComponent::computeInPin, this, 0);
    this->pins[1]->type = PinType::IN;
    this->pins[1]->compute = std::bind(&SumComponent::computeInPin, this, 1);
    this->pins[2]->type = PinType::IN;
    this->pins[2]->compute = std::bind(&SumComponent::computeInPin, this, 2);
    this->pins[3]->type = PinType::OUT;
    this->pins[3]->compute = std::bind(&SumComponent::computeComponent, this);
    this->pins[4]->type = PinType::OUT;
    this->pins[4]->compute = std::bind(&SumComponent::computeCarry, this);
}

nts::Tristate nts::Components::SumComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Pin is out of range.", "SumComponent");
    return this->pins[pin - 1]->compute();
}

nts::Tristate nts::Components::SumComponent::computeComponent(void) const
{
    return this->pins[0]->compute() ^ this->pins[1]->compute() ^ this->pins[2]->compute();
}

nts::Tristate nts::Components::SumComponent::computeCarry(void) const
{
    nts::Tristate in1 = this->pins[0]->compute();
    nts::Tristate in2 = this->pins[1]->compute();
    nts::Tristate cIn = this->pins[2]->compute();
    nts::Tristate carry = in1 && in2;

    if (carry == nts::Tristate::UNDEFINED)
        return nts::Tristate::UNDEFINED;
    if (carry == nts::Tristate::TRUE)
        return carry;
    return (in1 ^ in2) && cIn;
}
