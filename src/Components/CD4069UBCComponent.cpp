/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CD4069UBCComponent
*/

#include "Components/CD4069UBCComponent.hpp"
#include "Components/NotComponent.hpp"
#include "Exceptions/WrongPinException.hpp"
#include "Factory.hpp"

nts::Components::CD4069UBCComponent::CD4069UBCComponent()
    : AComponent("CD4069UBCComponent", 14)
{
    std::shared_ptr<IComponent> cNot1 = nts::Factory::createComponent("not");
    std::shared_ptr<IComponent> cNot2 = nts::Factory::createComponent("not");
    std::shared_ptr<IComponent> cNot3 = nts::Factory::createComponent("not");
    std::shared_ptr<IComponent> cNot4 = nts::Factory::createComponent("not");
    std::shared_ptr<IComponent> cNot5 = nts::Factory::createComponent("not");
    std::shared_ptr<IComponent> cNot6 = nts::Factory::createComponent("not");

    this->pins[0] = cNot1->getPin(1);
    this->pins[1] = cNot1->getPin(2);
    this->pins[2] = cNot2->getPin(1);
    this->pins[3] = cNot2->getPin(2);
    this->pins[4] = cNot3->getPin(1);
    this->pins[5] = cNot3->getPin(2);
    this->pins[6]->type = PinType::ELECTRICAL;
    this->pins[7] = cNot4->getPin(2);
    this->pins[8] = cNot4->getPin(1);
    this->pins[9] = cNot5->getPin(2);
    this->pins[10] = cNot5->getPin(1);
    this->pins[11] = cNot6->getPin(2);
    this->pins[12] = cNot6->getPin(1);
    this->pins[13]->type = PinType::ELECTRICAL;
    this->innerComponents.push_back(cNot1);
    this->innerComponents.push_back(cNot2);
    this->innerComponents.push_back(cNot3);
    this->innerComponents.push_back(cNot4);
    this->innerComponents.push_back(cNot5);
    this->innerComponents.push_back(cNot6);
}
