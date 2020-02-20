/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** QuadNotComponent
*/

#include "Components/QuadNotComponent.hpp"
#include "Components/NotComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::QuadNotComponent::QuadNotComponent()
    : AComponent("QuadNotComponent", 8)
{
    std::shared_ptr<IComponent> cNot1 = std::make_shared<NotComponent>();
    std::shared_ptr<IComponent> cNot2 = std::make_shared<NotComponent>();
    std::shared_ptr<IComponent> cNot3 = std::make_shared<NotComponent>();
    std::shared_ptr<IComponent> cNot4 = std::make_shared<NotComponent>();

    this->pins[0] = cNot1->getPin(1);
    this->pins[1] = cNot1->getPin(2);
    this->pins[2] = cNot2->getPin(1);
    this->pins[3] = cNot2->getPin(2);
    this->pins[4] = cNot3->getPin(1);
    this->pins[5] = cNot3->getPin(2);
    this->pins[6] = cNot4->getPin(1);
    this->pins[7] = cNot4->getPin(2);
    this->innerComponents.push_back(cNot1);
    this->innerComponents.push_back(cNot2);
    this->innerComponents.push_back(cNot3);
    this->innerComponents.push_back(cNot4);
}
