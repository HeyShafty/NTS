/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** OutputComponent
*/

#include "Components/OutputComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::OutputComponent::OutputComponent()
    : AComponent("OutputComponent", 1)
{
    BIND_IN_PIN(0, OutputComponent);
}
