/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** QuadSRFlipFlopComponent
*/

#include "Components/QuadSRFlipFlopComponent.hpp"
#include "Components/SRFlipFlopComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::QuadSRFlipFlopComponent::QuadSRFlipFlopComponent()
    : AComponent("QuadSRFlipFlopComponent", 16)
{
    std::shared_ptr<IComponent> cSRFlipFlop1 = std::make_shared<SRFlipFlopComponent>();
    std::shared_ptr<IComponent> cSRFlipFlop2 = std::make_shared<SRFlipFlopComponent>();
    std::shared_ptr<IComponent> cSRFlipFlop3 = std::make_shared<SRFlipFlopComponent>();
    std::shared_ptr<IComponent> cSRFlipFlop4 = std::make_shared<SRFlipFlopComponent>();

    this->pins[0] = cSRFlipFlop1->getPin(1);
    this->pins[1] = cSRFlipFlop1->getPin(2);
    this->pins[2] = cSRFlipFlop1->getPin(3);
    this->pins[3] = cSRFlipFlop1->getPin(4);
    this->pins[4] = cSRFlipFlop2->getPin(1);
    this->pins[5] = cSRFlipFlop2->getPin(2);
    this->pins[6] = cSRFlipFlop2->getPin(3);
    this->pins[7] = cSRFlipFlop2->getPin(4);
    this->pins[8] = cSRFlipFlop3->getPin(1);
    this->pins[9] = cSRFlipFlop3->getPin(2);
    this->pins[10] = cSRFlipFlop3->getPin(3);
    this->pins[11] = cSRFlipFlop3->getPin(4);
    this->pins[12] = cSRFlipFlop4->getPin(1);
    this->pins[13] = cSRFlipFlop4->getPin(2);
    this->pins[14] = cSRFlipFlop4->getPin(3);
    this->pins[15] = cSRFlipFlop4->getPin(4);
    this->innerComponents.push_back(cSRFlipFlop1);
    this->innerComponents.push_back(cSRFlipFlop2);
    this->innerComponents.push_back(cSRFlipFlop3);
    this->innerComponents.push_back(cSRFlipFlop4);
}
