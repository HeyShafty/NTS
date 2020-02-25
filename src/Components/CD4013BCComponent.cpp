/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CD4013BCComponent
*/

#include "Components/CD4013BCComponent.hpp"
#include "Components/DFlipFlopComponent.hpp"
#include "Exceptions/WrongPinException.hpp"
#include "Factory.hpp"

nts::Components::CD4013BCComponent::CD4013BCComponent(const std::string &name)
    : AComponent("CD4013BCComponent", name, 14)
{
    std::shared_ptr<IComponent> dFlipFlop1 = nts::Factory::createComponent("dFlipFlop");
    std::shared_ptr<IComponent> dFlipFlop2 = nts::Factory::createComponent("dFlipFlop");

    this->pins[0] = dFlipFlop1->getPin(1);
    this->pins[1] = dFlipFlop1->getPin(2);
    this->pins[2] = dFlipFlop1->getPin(3);
    this->pins[3] = dFlipFlop1->getPin(4);
    this->pins[4] = dFlipFlop1->getPin(5);
    this->pins[5] = dFlipFlop1->getPin(6);
    this->pins[6]->type = PinType::ELECTRICAL;
    this->pins[7] = dFlipFlop2->getPin(6);
    this->pins[8] = dFlipFlop2->getPin(5);
    this->pins[9] = dFlipFlop2->getPin(4);
    this->pins[10] = dFlipFlop2->getPin(3);
    this->pins[11] = dFlipFlop2->getPin(2);
    this->pins[12] = dFlipFlop2->getPin(1);
    this->pins[13]->type = PinType::ELECTRICAL;
    this->innerComponents.push_back(dFlipFlop1);
    this->innerComponents.push_back(dFlipFlop2);
}
