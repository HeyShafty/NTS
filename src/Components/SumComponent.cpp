/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** t'as le seum
*/

#include "Components/SumComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::SumComponent::SumComponent()
    : AComponent("SumComponent", 5)
{
    BIND_IN_PIN(0, SumComponent);
    BIND_IN_PIN(1, SumComponent);
    BIND_IN_PIN(2, SumComponent);
    this->pins[3]->type = PinType::OUT;
    this->pins[3]->compute = std::bind(&SumComponent::computeComponent, this);
    this->pins[4]->type = PinType::OUT;
    this->pins[4]->compute = std::bind(&SumComponent::computeCarry, this);
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
