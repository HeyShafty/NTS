/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** MC14040B
*/

#include "Components/MC14040BComponent.hpp"
#include "Factory.hpp"

nts::Components::MC14040BComponent::MC14040BComponent()
    : AComponent("4040Component", 16)
{
    std::shared_ptr<IComponent> cNot1 = nts::Factory::createComponent("not"); // fst top
    std::shared_ptr<IComponent> cNot2 = nts::Factory::createComponent("not"); // fst down
    std::shared_ptr<IComponent> cNot3 = nts::Factory::createComponent("not"); // snd down
    std::shared_ptr<IComponent> cNot4 = nts::Factory::createComponent("not"); // thrid down
    std::shared_ptr<IComponent> cNot5 = nts::Factory::createComponent("not"); // snd top
    std::shared_ptr<IComponent> cNot6 = nts::Factory::createComponent("not"); // third top
    std::shared_ptr<IComponent> cNot7 = nts::Factory::createComponent("not"); // fst ff down
    std::shared_ptr<IComponent> cNot8 = nts::Factory::createComponent("not"); // snd ff down
    std::shared_ptr<IComponent> cNot9 = nts::Factory::createComponent("not"); // third ff down
    std::shared_ptr<IComponent> cNot10 = nts::Factory::createComponent("not"); // fourth ff down
    std::shared_ptr<IComponent> cNot11 = nts::Factory::createComponent("not"); // fifth ff down
    std::shared_ptr<IComponent> cNot12 = nts::Factory::createComponent("not"); // sixth ff down
    std::shared_ptr<IComponent> cNot13 = nts::Factory::createComponent("not"); // fourth top
    std::shared_ptr<IComponent> cNot14 = nts::Factory::createComponent("not"); // fifth top
    std::shared_ptr<IComponent> cNot15 = nts::Factory::createComponent("not"); // sixth top
    std::shared_ptr<IComponent> cNot16 = nts::Factory::createComponent("not"); // seventh top
    std::shared_ptr<IComponent> cNot17 = nts::Factory::createComponent("not"); // eigth top
    std::shared_ptr<IComponent> cNot18 = nts::Factory::createComponent("not"); // nine top
    std::shared_ptr<IComponent> cNot19 = nts::Factory::createComponent("not"); // ten top
    std::shared_ptr<IComponent> cNot20 = nts::Factory::createComponent("not"); // eleven top
    std::shared_ptr<IComponent> cNot21 = nts::Factory::createComponent("not"); // twelve top
    std::shared_ptr<IComponent> cNot22 = nts::Factory::createComponent("not"); // thirteen top
    std::shared_ptr<IComponent> cNot23 = nts::Factory::createComponent("not"); // fourteen top
    std::shared_ptr<IComponent> cNot24 = nts::Factory::createComponent("not"); // fourteen top
    std::shared_ptr<IComponent> cDFlipFlop1 = nts::Factory::createComponent("dFlipFlop");
    std::shared_ptr<IComponent> cDFlipFlop2 = nts::Factory::createComponent("dFlipFlop");
    std::shared_ptr<IComponent> cDFlipFlop3 = nts::Factory::createComponent("dFlipFlop");
    std::shared_ptr<IComponent> cDFlipFlop4 = nts::Factory::createComponent("dFlipFlop");
    std::shared_ptr<IComponent> cDFlipFlop5 = nts::Factory::createComponent("dFlipFlop");
    std::shared_ptr<IComponent> cDFlipFlop6 = nts::Factory::createComponent("dFlipFlop");
    std::shared_ptr<IComponent> cDFlipFlop7 = nts::Factory::createComponent("dFlipFlop");
    std::shared_ptr<IComponent> cDFlipFlop8 = nts::Factory::createComponent("dFlipFlop");
    std::shared_ptr<IComponent> cDFlipFlop9 = nts::Factory::createComponent("dFlipFlop");
    std::shared_ptr<IComponent> cDFlipFlop10 = nts::Factory::createComponent("dFlipFlop");
    std::shared_ptr<IComponent> cDFlipFlop11 = nts::Factory::createComponent("dFlipFlop");
    std::shared_ptr<IComponent> cDFlipFlop12 = nts::Factory::createComponent("dFlipFlop");
    std::shared_ptr<IComponent> cDFlipFlop13 = nts::Factory::createComponent("dFlipFlop");
    std::shared_ptr<IComponent> cNor1 = nts::Factory::createComponent("nor");
    std::shared_ptr<IComponent> cNor2 = nts::Factory::createComponent("nor");

    this->pins[9] = cNot1->getPin(1);
    this->pins[10] = cNot2->getPin(1);

    cNot3->setLink(1, *cNot2, 2);
    cNot4->setLink(1, *cNot3, 2);

    cNor1->setLink(1, *cNot1, 2);
    cNor1->setLink(2, *cNot3, 2);
    cNor2->setLink(1, *cNot1, 2);
    cNor2->setLink(2, *cNot3, 2);

    cNot7->setLink(1, *cNot4, 2);
    cNot8->setLink(1, *cNot4, 2);
    cNot9->setLink(1, *cNot4, 2);
    cNot10->setLink(1, *cNot4, 2);
    cNot11->setLink(1, *cNot4, 2);
    cNot12->setLink(1, *cNot4, 2);
    cDFlipFlop1->setLink(4, *cNot7, 2);
    cDFlipFlop2->setLink(4, *cNot8, 2);
    cDFlipFlop3->setLink(4, *cNot9, 2);
    cDFlipFlop4->setLink(4, *cNot10, 2);
    cDFlipFlop5->setLink(4, *cNot11, 2);
    cDFlipFlop6->setLink(4, *cNot12, 2);

    cNot5->setLink(1, *cNor1, 3);
    cDFlipFlop1->setLink(3, *cNot5, 2);
    cNot6->setLink(1, *cNor2, 3);
    cDFlipFlop1->setLink(5, *cNot6, 2);

    cDFlipFlop2->setLink(3, *cDFlipFlop1, 2);
    cNot13->setLink(1, *cDFlipFlop1, 1);
    cDFlipFlop2->setLink(5, *cNot13, 2);
    this->pins[8] = cDFlipFlop1->getPin(1); // Q1

    cDFlipFlop3->setLink(3, *cDFlipFlop2, 2);
    cNot14->setLink(1, *cDFlipFlop2, 1);
    cDFlipFlop3->setLink(5, *cNot14, 2);
    this->pins[6] = cDFlipFlop2->getPin(1); // Q2

    cDFlipFlop4->setLink(3, *cDFlipFlop3, 2);
    cNot15->setLink(1, *cDFlipFlop3, 1);
    cDFlipFlop4->setLink(5, *cNot15, 2);
    this->pins[5] = cDFlipFlop3->getPin(1); // Q3

    cDFlipFlop5->setLink(3, *cDFlipFlop4, 2);
    cNot16->setLink(1, *cDFlipFlop4, 1);
    cDFlipFlop5->setLink(5, *cNot16, 2);
    this->pins[4] = cDFlipFlop4->getPin(1); // Q4

    cDFlipFlop6->setLink(3, *cDFlipFlop5, 2);
    cNot17->setLink(1, *cDFlipFlop5, 1);
    cDFlipFlop6->setLink(5, *cNot17, 2);
    this->pins[2] = cDFlipFlop5->getPin(1); // Q5

    cDFlipFlop7->setLink(3, *cDFlipFlop6, 2);
    cNot18->setLink(1, *cDFlipFlop6, 1);
    cDFlipFlop7->setLink(5, *cNot18, 2);
    this->pins[1] = cDFlipFlop6->getPin(1); // Q6

    cDFlipFlop8->setLink(3, *cDFlipFlop7, 2);
    cNot19->setLink(1, *cDFlipFlop7, 1);
    cDFlipFlop8->setLink(5, *cNot19, 2);
    this->pins[3] = cDFlipFlop7->getPin(1); // Q7

    cDFlipFlop9->setLink(3, *cDFlipFlop8, 2);
    cNot20->setLink(1, *cDFlipFlop8, 1);
    cDFlipFlop9->setLink(5, *cNot20, 2);
    this->pins[12] = cDFlipFlop8->getPin(1); // Q8

    cDFlipFlop10->setLink(3, *cDFlipFlop9, 2);
    cNot21->setLink(1, *cDFlipFlop9, 1);
    cDFlipFlop10->setLink(5, *cNot21, 2);
    this->pins[11] = cDFlipFlop9->getPin(1); // Q9

    cDFlipFlop11->setLink(3, *cDFlipFlop10, 2);
    cNot22->setLink(1, *cDFlipFlop10, 1);
    cDFlipFlop11->setLink(5, *cNot22, 2);
    this->pins[13] = cDFlipFlop10->getPin(1); // Q10

    cDFlipFlop12->setLink(3, *cDFlipFlop11, 2);
    cNot23->setLink(1, *cDFlipFlop11, 1);
    cDFlipFlop12->setLink(5, *cNot23, 2);
    this->pins[14] = cDFlipFlop11->getPin(1); // Q11

    cDFlipFlop13->setLink(3, *cDFlipFlop12, 2);
    cNot24->setLink(1, *cDFlipFlop12, 1);
    cDFlipFlop13->setLink(5, *cNot24, 2);
    this->pins[0] = cDFlipFlop12->getPin(1); // Q12

    this->pins[7]->type = nts::PinType::ELECTRICAL;
    this->pins[15]->type = nts::PinType::ELECTRICAL;
    this->innerComponents.push_back(cNot1);
    this->innerComponents.push_back(cNot2);
    this->innerComponents.push_back(cNot3);
    this->innerComponents.push_back(cNot4);
    this->innerComponents.push_back(cNot5);
    this->innerComponents.push_back(cNot6);
    this->innerComponents.push_back(cNot7);
    this->innerComponents.push_back(cNot8);
    this->innerComponents.push_back(cNot9);
    this->innerComponents.push_back(cNot10);
    this->innerComponents.push_back(cNot11);
    this->innerComponents.push_back(cNot12);
    this->innerComponents.push_back(cNot13);
    this->innerComponents.push_back(cNot14);
    this->innerComponents.push_back(cNot15);
    this->innerComponents.push_back(cNot16);
    this->innerComponents.push_back(cNot17);
    this->innerComponents.push_back(cNot18);
    this->innerComponents.push_back(cNot19);
    this->innerComponents.push_back(cNot20);
    this->innerComponents.push_back(cNot21);
    this->innerComponents.push_back(cNot22);
    this->innerComponents.push_back(cNot23);
    this->innerComponents.push_back(cNot24);
    this->innerComponents.push_back(cDFlipFlop1);
    this->innerComponents.push_back(cDFlipFlop2);
    this->innerComponents.push_back(cDFlipFlop3);
    this->innerComponents.push_back(cDFlipFlop4);
    this->innerComponents.push_back(cDFlipFlop5);
    this->innerComponents.push_back(cDFlipFlop6);
    this->innerComponents.push_back(cDFlipFlop7);
    this->innerComponents.push_back(cDFlipFlop8);
    this->innerComponents.push_back(cDFlipFlop9);
    this->innerComponents.push_back(cDFlipFlop10);
    this->innerComponents.push_back(cDFlipFlop11);
    this->innerComponents.push_back(cDFlipFlop12);
    this->innerComponents.push_back(cDFlipFlop13);
    this->innerComponents.push_back(cNor1);
    this->innerComponents.push_back(cNor2);
}