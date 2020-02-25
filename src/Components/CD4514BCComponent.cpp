/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CD4514BCComponent
*/

#include "Components/CD4514BCComponent.hpp"
#include "Components/HEF4001BComponent.hpp"
#include "Components/QuadSRFlipFlopComponent.hpp"
#include "Components/CD4011BComponent.hpp"
#include "Components/CD4069UBCComponent.hpp"
#include "Components/NotComponent.hpp"
#include "Components/QuadTripleNandComponent.hpp"
#include "Exceptions/WrongPinException.hpp"
#include "Factory.hpp"

nts::Components::CD4514BCComponent::CD4514BCComponent(const std::string &name)
    : AComponent("CD4514BCComponent", name, 24)
{
    std::shared_ptr<IComponent> latchIn_4069 = nts::Factory::createComponent("4069");
    std::shared_ptr<IComponent> latchIn_4001_1 = nts::Factory::createComponent("4001");
    std::shared_ptr<IComponent> latchIn_4001_2 = nts::Factory::createComponent("4001");
    std::shared_ptr<IComponent> quadSRFlipFlop = nts::Factory::createComponent("quadSRFlipFlop");
    std::shared_ptr<IComponent> latchOut_4001_1 = nts::Factory::createComponent("4001");
    std::shared_ptr<IComponent> latchOut_4001_2 = nts::Factory::createComponent("4001");
    std::shared_ptr<IComponent> decoder_QuadTripleNand_1 = nts::Factory::createComponent("quadTripleNand");
    std::shared_ptr<IComponent> decoder_QuadTripleNand_2 = nts::Factory::createComponent("quadTripleNand");
    std::shared_ptr<IComponent> decoder_QuadTripleNand_3 = nts::Factory::createComponent("quadTripleNand");
    std::shared_ptr<IComponent> decoder_QuadTripleNand_4 = nts::Factory::createComponent("quadTripleNand");
    std::shared_ptr<IComponent> decoder_4069_1 = nts::Factory::createComponent("4069");
    std::shared_ptr<IComponent> decoder_4069_2 = nts::Factory::createComponent("4069");
    std::shared_ptr<IComponent> decoder_4069_3 = nts::Factory::createComponent("4069");

    latchIn_4001_1->setLink(1, *latchIn_4069, 2);
    latchIn_4001_1->setLink(2, *latchIn_4069, 10);
    latchIn_4001_1->setLink(5, *latchIn_4069, 4);
    latchIn_4001_1->setLink(6, *latchIn_4069, 10);
    latchIn_4001_1->setLink(8, *latchIn_4069, 6);
    latchIn_4001_1->setLink(9, *latchIn_4069, 10);
    latchIn_4001_1->setLink(12, *latchIn_4069, 8);
    latchIn_4001_1->setLink(13, *latchIn_4069, 10);

    latchIn_4001_2->setLink(1, *latchIn_4001_1, 3);
    latchIn_4001_2->setLink(2, *latchIn_4069, 10);
    latchIn_4001_2->setLink(5, *latchIn_4001_1, 4);
    latchIn_4001_2->setLink(6, *latchIn_4069, 10);
    latchIn_4001_2->setLink(8, *latchIn_4001_1, 10);
    latchIn_4001_2->setLink(9, *latchIn_4069, 10);
    latchIn_4001_2->setLink(12, *latchIn_4001_1, 11);
    latchIn_4001_2->setLink(13, *latchIn_4069, 10);

    quadSRFlipFlop->setLink(1, *latchIn_4001_1, 3);
    quadSRFlipFlop->setLink(2, *latchIn_4001_2, 3);
    quadSRFlipFlop->setLink(5, *latchIn_4001_1, 4);
    quadSRFlipFlop->setLink(6, *latchIn_4001_2, 4);
    quadSRFlipFlop->setLink(9, *latchIn_4001_1, 10);
    quadSRFlipFlop->setLink(10, *latchIn_4001_2, 10);
    quadSRFlipFlop->setLink(13, *latchIn_4001_1, 11);
    quadSRFlipFlop->setLink(14, *latchIn_4001_2, 11);

    latchOut_4001_1->setLink(1, *quadSRFlipFlop, 3);
    latchOut_4001_1->setLink(2, *quadSRFlipFlop, 7);
    latchOut_4001_1->setLink(5, *quadSRFlipFlop, 4);
    latchOut_4001_1->setLink(6, *quadSRFlipFlop, 7);
    latchOut_4001_1->setLink(8, *quadSRFlipFlop, 3);
    latchOut_4001_1->setLink(9, *quadSRFlipFlop, 8);
    latchOut_4001_1->setLink(12, *quadSRFlipFlop, 4);
    latchOut_4001_1->setLink(13, *quadSRFlipFlop, 8);
    latchOut_4001_2->setLink(1, *quadSRFlipFlop, 15);
    latchOut_4001_2->setLink(2, *quadSRFlipFlop, 11);
    latchOut_4001_2->setLink(5, *quadSRFlipFlop, 12);
    latchOut_4001_2->setLink(6, *quadSRFlipFlop, 15);
    latchOut_4001_2->setLink(8, *quadSRFlipFlop, 11);
    latchOut_4001_2->setLink(9, *quadSRFlipFlop, 16);
    latchOut_4001_2->setLink(12, *quadSRFlipFlop, 12);
    latchOut_4001_2->setLink(13, *quadSRFlipFlop, 16);

    decoder_QuadTripleNand_1->setLink(1, *latchOut_4001_2, 3);
    decoder_QuadTripleNand_1->setLink(2, *latchOut_4001_1, 3);
    decoder_QuadTripleNand_1->setLink(3, *latchIn_4069, 12);
    decoder_QuadTripleNand_1->setLink(5, *latchOut_4001_2, 3);
    decoder_QuadTripleNand_1->setLink(6, *latchOut_4001_1, 4);
    decoder_QuadTripleNand_1->setLink(7, *latchIn_4069, 12);
    decoder_QuadTripleNand_1->setLink(9, *latchOut_4001_2, 3);
    decoder_QuadTripleNand_1->setLink(10, *latchOut_4001_1, 10);
    decoder_QuadTripleNand_1->setLink(11, *latchIn_4069, 12);
    decoder_QuadTripleNand_1->setLink(13, *latchOut_4001_2, 3);
    decoder_QuadTripleNand_1->setLink(14, *latchOut_4001_1, 11);
    decoder_QuadTripleNand_1->setLink(15, *latchIn_4069, 12);

    decoder_QuadTripleNand_2->setLink(1, *latchOut_4001_2, 4);
    decoder_QuadTripleNand_2->setLink(2, *latchOut_4001_1, 3);
    decoder_QuadTripleNand_2->setLink(3, *latchIn_4069, 12);
    decoder_QuadTripleNand_2->setLink(5, *latchOut_4001_2, 4);
    decoder_QuadTripleNand_2->setLink(6, *latchOut_4001_1, 4);
    decoder_QuadTripleNand_2->setLink(7, *latchIn_4069, 12);
    decoder_QuadTripleNand_2->setLink(9, *latchOut_4001_2, 4);
    decoder_QuadTripleNand_2->setLink(10, *latchOut_4001_1, 10);
    decoder_QuadTripleNand_2->setLink(11, *latchIn_4069, 12);
    decoder_QuadTripleNand_2->setLink(13, *latchOut_4001_2, 4);
    decoder_QuadTripleNand_2->setLink(14, *latchOut_4001_1, 11);
    decoder_QuadTripleNand_2->setLink(15, *latchIn_4069, 12);

    decoder_QuadTripleNand_3->setLink(1, *latchOut_4001_2, 10);
    decoder_QuadTripleNand_3->setLink(2, *latchOut_4001_1, 3);
    decoder_QuadTripleNand_3->setLink(3, *latchIn_4069, 12);
    decoder_QuadTripleNand_3->setLink(5, *latchOut_4001_2, 10);
    decoder_QuadTripleNand_3->setLink(6, *latchOut_4001_1, 4);
    decoder_QuadTripleNand_3->setLink(7, *latchIn_4069, 12);
    decoder_QuadTripleNand_3->setLink(9, *latchOut_4001_2, 10);
    decoder_QuadTripleNand_3->setLink(10, *latchOut_4001_1, 10);
    decoder_QuadTripleNand_3->setLink(11, *latchIn_4069, 12);
    decoder_QuadTripleNand_3->setLink(13, *latchOut_4001_2, 10);
    decoder_QuadTripleNand_3->setLink(14, *latchOut_4001_1, 11);
    decoder_QuadTripleNand_3->setLink(15, *latchIn_4069, 12);

    decoder_QuadTripleNand_4->setLink(1, *latchOut_4001_2, 11);
    decoder_QuadTripleNand_4->setLink(2, *latchOut_4001_1, 3);
    decoder_QuadTripleNand_4->setLink(3, *latchIn_4069, 12);
    decoder_QuadTripleNand_4->setLink(5, *latchOut_4001_2, 11);
    decoder_QuadTripleNand_4->setLink(6, *latchOut_4001_1, 4);
    decoder_QuadTripleNand_4->setLink(7, *latchIn_4069, 12);
    decoder_QuadTripleNand_4->setLink(9, *latchOut_4001_2, 11);
    decoder_QuadTripleNand_4->setLink(10, *latchOut_4001_1, 10);
    decoder_QuadTripleNand_4->setLink(11, *latchIn_4069, 12);
    decoder_QuadTripleNand_4->setLink(13, *latchOut_4001_2, 11);
    decoder_QuadTripleNand_4->setLink(14, *latchOut_4001_1, 11);
    decoder_QuadTripleNand_4->setLink(15, *latchIn_4069, 12);

    decoder_4069_1->setLink(1, *decoder_QuadTripleNand_1, 4);
    decoder_4069_1->setLink(3, *decoder_QuadTripleNand_1, 8);
    decoder_4069_1->setLink(5, *decoder_QuadTripleNand_1, 12);
    decoder_4069_1->setLink(9, *decoder_QuadTripleNand_1, 16);
    decoder_4069_1->setLink(11, *decoder_QuadTripleNand_2, 4);
    decoder_4069_1->setLink(13, *decoder_QuadTripleNand_2, 8);

    decoder_4069_2->setLink(1, *decoder_QuadTripleNand_2, 12);
    decoder_4069_2->setLink(3, *decoder_QuadTripleNand_2, 16);
    decoder_4069_2->setLink(5, *decoder_QuadTripleNand_3, 4);
    decoder_4069_2->setLink(9, *decoder_QuadTripleNand_3, 8);
    decoder_4069_2->setLink(11, *decoder_QuadTripleNand_3, 12);
    decoder_4069_2->setLink(13, *decoder_QuadTripleNand_3, 16);

    decoder_4069_3->setLink(1, *decoder_QuadTripleNand_4, 4);
    decoder_4069_3->setLink(3, *decoder_QuadTripleNand_4, 8);
    decoder_4069_3->setLink(5, *decoder_QuadTripleNand_4, 12);
    decoder_4069_3->setLink(9, *decoder_QuadTripleNand_4, 16);

    this->pins[0] = latchIn_4069->getPin(11);
    this->pins[1] = latchIn_4069->getPin(1);
    this->pins[2] = latchIn_4069->getPin(3);
    this->pins[3] = decoder_4069_2->getPin(4);
    this->pins[4] = decoder_4069_2->getPin(2);
    this->pins[5] = decoder_4069_1->getPin(12);
    this->pins[6] = decoder_4069_1->getPin(10);
    this->pins[7] = decoder_4069_1->getPin(8);
    this->pins[8] = decoder_4069_1->getPin(4);
    this->pins[9] = decoder_4069_1->getPin(6);
    this->pins[10] = decoder_4069_1->getPin(2);
    this->pins[11]->type = PinType::ELECTRICAL;
    this->pins[12] = decoder_4069_3->getPin(4);
    this->pins[13] = decoder_4069_3->getPin(2);
    this->pins[14] = decoder_4069_3->getPin(8);
    this->pins[15] = decoder_4069_3->getPin(6);
    this->pins[16] = decoder_4069_2->getPin(8);
    this->pins[17] = decoder_4069_2->getPin(6);
    this->pins[18] = decoder_4069_2->getPin(12);
    this->pins[19] = decoder_4069_2->getPin(10);
    this->pins[20] = latchIn_4069->getPin(5);
    this->pins[21] = latchIn_4069->getPin(9);
    this->pins[22] = latchIn_4069->getPin(13);
    this->pins[23]->type = PinType::ELECTRICAL;
    this->innerComponents.push_back(latchIn_4069);
    this->innerComponents.push_back(latchIn_4001_1);
    this->innerComponents.push_back(latchIn_4001_2);
    this->innerComponents.push_back(quadSRFlipFlop);
    this->innerComponents.push_back(latchOut_4001_1);
    this->innerComponents.push_back(latchOut_4001_2);
    this->innerComponents.push_back(decoder_QuadTripleNand_1);
    this->innerComponents.push_back(decoder_QuadTripleNand_2);
    this->innerComponents.push_back(decoder_QuadTripleNand_3);
    this->innerComponents.push_back(decoder_QuadTripleNand_4);
    this->innerComponents.push_back(decoder_4069_1);
    this->innerComponents.push_back(decoder_4069_2);
    this->innerComponents.push_back(decoder_4069_3);
}
