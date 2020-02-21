/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** SRFlipFlopComponent
*/

#include "Components/SRFlipFlopComponent.hpp"
#include "Components/HEF4001BComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::SRFlipFlopComponent::SRFlipFlopComponent()
    : AComponent("SRFlipFlopComponent", 4)
{
    std::shared_ptr<IComponent> cHEF4001B = std::make_shared<HEF4001BComponent>();

    cHEF4001B->setLink(2, *cHEF4001B, 4);
    cHEF4001B->setLink(5, *cHEF4001B, 3);
    this->pins[0] = cHEF4001B->getPin(1);
    this->pins[1] = cHEF4001B->getPin(6);
    this->pins[2] = cHEF4001B->getPin(3);
    this->pins[3] = cHEF4001B->getPin(4);
    this->innerComponents.push_back(cHEF4001B);
}
