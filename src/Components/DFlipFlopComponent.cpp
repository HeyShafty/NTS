/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** DFlipFlopComponent
*/

#include "Components/DFlipFlopComponent.hpp"
#include "Exceptions/WrongPinException.hpp"
#include "Factory.hpp"

nts::Components::DFlipFlopComponent::DFlipFlopComponent()
    : AComponent("DFlipFlopComponent", 6)
{
    std::shared_ptr<IComponent> cNot1 = nts::Factory::createComponent("not");
    std::shared_ptr<IComponent> cNot2 = nts::Factory::createComponent("not");
    std::shared_ptr<IComponent> cNot3 = nts::Factory::createComponent("not");
    std::shared_ptr<IComponent> cNand1 = nts::Factory::createComponent("nand");
    std::shared_ptr<IComponent> cNand2 = nts::Factory::createComponent("nand");
    std::shared_ptr<IComponent> cNand3 = nts::Factory::createComponent("nand");
    std::shared_ptr<IComponent> cNand4 = nts::Factory::createComponent("nand");
    std::shared_ptr<IComponent> cNor1 = nts::Factory::createComponent("nor");
    std::shared_ptr<IComponent> cNor2 = nts::Factory::createComponent("nor");

    this->pins[0] = cNand3->getPin(3);
    this->pins[1] = cNand4->getPin(3);
    BIND_IN_PIN(2, DFlipFlopComponent);
    this->pins[3] = cNor2->getPin(2);
    BIND_IN_PIN(4, DFlipFlopComponent);
    this->pins[5] = cNor1->getPin(1);
    cNot1->setLink(1, *this, 5);
    cNand1->setLink(1, *this, 5);
    cNand1->setLink(2, *this, 3);
    cNand2->setLink(1, *this, 3);
    cNand2->setLink(2, *cNot1, 2);
    cNot2->setLink(1, *cNand1, 3);
    cNot3->setLink(1, *cNand2, 3);
    cNor1->setLink(2, *cNot2, 2);
    cNor2->setLink(1, *cNot3, 2);
    cNand3->setLink(1, *cNor1, 3);
    cNand3->setLink(2, *cNand4, 3);
    cNand4->setLink(1, *cNand3, 3);
    cNand4->setLink(2, *cNor2, 3);
    this->innerComponents.push_back(cNot1);
    this->innerComponents.push_back(cNot2);
    this->innerComponents.push_back(cNot3);
    this->innerComponents.push_back(cNand1);
    this->innerComponents.push_back(cNand2);
    this->innerComponents.push_back(cNand3);
    this->innerComponents.push_back(cNand4);
    this->innerComponents.push_back(cNor1);
    this->innerComponents.push_back(cNor2);
}
