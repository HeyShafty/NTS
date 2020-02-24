/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** J74HC4017Component
*/

#include "Components/J74HC4017Component.hpp"
#include "Factory.hpp"

nts::Components::J74HC4017Component::J74HC4017Component()
    : AComponent("4017Component", 15)
{
    std::shared_ptr<IComponent> cNor1 = nts::Factory::createComponent("nor");
    std::shared_ptr<IComponent> cNor2 = nts::Factory::createComponent("nor");
    std::shared_ptr<IComponent> cNor3 = nts::Factory::createComponent("nor");
    std::shared_ptr<IComponent> cNor4 = nts::Factory::createComponent("nor");
    std::shared_ptr<IComponent> cNor5 = nts::Factory::createComponent("nor");
    std::shared_ptr<IComponent> cNor6 = nts::Factory::createComponent("nor");
    std::shared_ptr<IComponent> cNor7 = nts::Factory::createComponent("nor");
    std::shared_ptr<IComponent> cNor8 = nts::Factory::createComponent("nor");
    std::shared_ptr<IComponent> cNor9 = nts::Factory::createComponent("nor");
    std::shared_ptr<IComponent> cNor10 = nts::Factory::createComponent("nor");
    std::shared_ptr<IComponent> cDFlipFlop1 = nts::Factory::createComponent("dFlipFlop");
    std::shared_ptr<IComponent> cDFlipFlop2 = nts::Factory::createComponent("dFlipFlop");
    std::shared_ptr<IComponent> cDFlipFlop3 = nts::Factory::createComponent("dFlipFlop");
    std::shared_ptr<IComponent> cDFlipFlop4 = nts::Factory::createComponent("dFlipFlop");
    std::shared_ptr<IComponent> cDFlipFlop5 = nts::Factory::createComponent("dFlipFlop");
    std::shared_ptr<IComponent> cAnd1 = nts::Factory::createComponent("and");
    std::shared_ptr<IComponent> cAnd2 = nts::Factory::createComponent("and");
    std::shared_ptr<IComponent> cOr = nts::Factory::createComponent("or");
    std::shared_ptr<IComponent> cNot = nts::Factory::createComponent("not");
    std::shared_ptr<IComponent> cFalse1 = nts::Factory::createComponent("false");
    std::shared_ptr<IComponent> cFalse2 = nts::Factory::createComponent("false");
    std::shared_ptr<IComponent> cFalse3 = nts::Factory::createComponent("false");
    std::shared_ptr<IComponent> cFalse4 = nts::Factory::createComponent("false");
    std::shared_ptr<IComponent> cFalse5 = nts::Factory::createComponent("false");

    this->pins[12] = cNot->getPin(1); // CP1
    this->pins[13] = cAnd1->getPin(2); // CP0
    cAnd1->setLink(1, *cNot, 2); // left one
    BIND_IN_PIN(14, J74HC4017Component); // MR
    cDFlipFlop1->setLink(6, *cFalse1, 1);
    cDFlipFlop2->setLink(6, *cFalse2, 1);
    cDFlipFlop3->setLink(6, *cFalse3, 1);
    cDFlipFlop4->setLink(6, *cFalse4, 1);
    cDFlipFlop5->setLink(6, *cFalse5, 1);

    cDFlipFlop1->setLink(3, *cAnd1, 3);
    cDFlipFlop1->setLink(4, *this, 15);
    cDFlipFlop2->setLink(3, *cAnd1, 3);
    cDFlipFlop2->setLink(4, *this, 15);
    cDFlipFlop3->setLink(3, *cAnd1, 3);
    cDFlipFlop3->setLink(4, *this, 15);
    cDFlipFlop4->setLink(3, *cAnd1, 3);
    cDFlipFlop4->setLink(4, *this, 15);
    cDFlipFlop5->setLink(3, *cAnd1, 3);
    cDFlipFlop5->setLink(4, *this, 15);

    this->pins[11] = cDFlipFlop5->getPin(2);

    cDFlipFlop1->setLink(5, *cDFlipFlop5, 2);
    cDFlipFlop2->setLink(5, *cDFlipFlop1, 1);
    cDFlipFlop3->setLink(5, *cAnd2, 3);
    cAnd2->setLink(1, *cOr, 3);
    cAnd2->setLink(2, *cDFlipFlop2, 1);
    cOr->setLink(1, *cDFlipFlop3, 1);
    cOr->setLink(2, *cDFlipFlop1, 1);
    cDFlipFlop4->setLink(5, *cDFlipFlop3, 1);
    cDFlipFlop5->setLink(5, *cDFlipFlop4, 1);

    cNor1->setLink(1, *cDFlipFlop5, 1);
    cNor1->setLink(2, *cDFlipFlop1, 1);
    this->pins[2] = cNor1->getPin(3); // Q0
    cNor2->setLink(1, *cDFlipFlop2, 1);
    cNor2->setLink(2, *cDFlipFlop1, 2);
    this->pins[1] = cNor2->getPin(3); // Q1
    cNor3->setLink(1, *cDFlipFlop2, 2);
    cNor3->setLink(2, *cDFlipFlop3, 1);
    this->pins[3] = cNor3->getPin(3); // Q2
    cNor4->setLink(1, *cDFlipFlop4, 1);
    cNor4->setLink(2, *cDFlipFlop3, 2);
    this->pins[6] = cNor4->getPin(3); // Q3
    cNor5->setLink(1, *cDFlipFlop5, 1);
    cNor5->setLink(2, *cDFlipFlop4, 2);
    this->pins[9] = cNor5->getPin(3); // Q4
    cNor6->setLink(1, *cDFlipFlop1, 2);
    cNor6->setLink(2, *cDFlipFlop5, 2);
    this->pins[0] = cNor6->getPin(3); // Q5
    cNor7->setLink(1, *cDFlipFlop1, 1);
    cNor7->setLink(2, *cDFlipFlop2, 2);
    this->pins[4] = cNor7->getPin(3); // Q6
    cNor8->setLink(1, *cDFlipFlop2, 1);
    cNor8->setLink(2, *cDFlipFlop3, 2);
    this->pins[5] = cNor8->getPin(3); // Q7
    cNor9->setLink(1, *cDFlipFlop4, 2);
    cNor9->setLink(2, *cDFlipFlop3, 1);
    this->pins[8] = cNor9->getPin(3); // Q8
    cNor10->setLink(1, *cDFlipFlop4, 1);
    cNor10->setLink(2, *cDFlipFlop5, 2);
    this->pins[10] = cNor10->getPin(3); // Q9

    this->innerComponents.push_back(cNor1);
    this->innerComponents.push_back(cNor2);
    this->innerComponents.push_back(cNor3);
    this->innerComponents.push_back(cNor4);
    this->innerComponents.push_back(cNor5);
    this->innerComponents.push_back(cNor6);
    this->innerComponents.push_back(cNor7);
    this->innerComponents.push_back(cNor8);
    this->innerComponents.push_back(cNor9);
    this->innerComponents.push_back(cNor10);
    this->innerComponents.push_back(cDFlipFlop1);
    this->innerComponents.push_back(cDFlipFlop2);
    this->innerComponents.push_back(cDFlipFlop3);
    this->innerComponents.push_back(cDFlipFlop4);
    this->innerComponents.push_back(cDFlipFlop5);
    this->innerComponents.push_back(cAnd1);
    this->innerComponents.push_back(cAnd2);
    this->innerComponents.push_back(cOr);
    this->innerComponents.push_back(cNot);
    this->innerComponents.push_back(cFalse1);
    this->innerComponents.push_back(cFalse2);
    this->innerComponents.push_back(cFalse3);
    this->innerComponents.push_back(cFalse4);
    this->innerComponents.push_back(cFalse5);
}
