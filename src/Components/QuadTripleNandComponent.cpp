/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** QuadTripleNandComponent
*/

#include "Components/QuadTripleNandComponent.hpp"
#include "Components/TripleNandComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::QuadTripleNandComponent::QuadTripleNandComponent()
    : AComponent("QuadTripleNandComponent", 16)
{
    std::shared_ptr<IComponent> cTripleNand1 = std::make_shared<TripleNandComponent>();
    std::shared_ptr<IComponent> cTripleNand2 = std::make_shared<TripleNandComponent>();
    std::shared_ptr<IComponent> cTripleNand3 = std::make_shared<TripleNandComponent>();
    std::shared_ptr<IComponent> cTripleNand4 = std::make_shared<TripleNandComponent>();

    this->pins[0] = cTripleNand1->getPin(1);
    this->pins[1] = cTripleNand1->getPin(2);
    this->pins[2] = cTripleNand1->getPin(3);
    this->pins[3] = cTripleNand1->getPin(4);

    this->pins[4] = cTripleNand2->getPin(1);
    this->pins[5] = cTripleNand2->getPin(2);
    this->pins[6] = cTripleNand2->getPin(3);
    this->pins[7] = cTripleNand2->getPin(4);

    this->pins[8] = cTripleNand3->getPin(1);
    this->pins[9] = cTripleNand3->getPin(2);
    this->pins[10] = cTripleNand3->getPin(3);
    this->pins[11] = cTripleNand3->getPin(4);

    this->pins[12] = cTripleNand4->getPin(1);
    this->pins[13] = cTripleNand4->getPin(2);
    this->pins[14] = cTripleNand4->getPin(3);
    this->pins[15] = cTripleNand4->getPin(4);

    this->innerComponents.push_back(cTripleNand1);
    this->innerComponents.push_back(cTripleNand2);
    this->innerComponents.push_back(cTripleNand3);
    this->innerComponents.push_back(cTripleNand4);
}
