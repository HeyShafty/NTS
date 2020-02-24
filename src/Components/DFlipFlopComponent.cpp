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
    : AComponent("DFlipFlopComponent", 6), clockPrev(Tristate::UNDEFINED), firstComputed(Tristate::UNDEFINED)
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

    this->pins[0]->type = PinType::OUT;
    this->pins[0]->compute = [this, cNand3]() {
        auto tmp = cNand3->getPin(3)->compute();
        if (this->computeComponent() == Tristate::UNDEFINED)
            return Tristate::UNDEFINED;
        return tmp;
    };
    this->pins[1]->type = PinType::OUT;
    this->pins[1]->compute = [this, cNand4]() {
        auto tmp = cNand4->getPin(3)->compute();
        if (this->computeComponent() == Tristate::UNDEFINED)
            return Tristate::UNDEFINED;
        return tmp;
    };
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

/**
 * @brief Returns undefined if the clock never yet changed value.
 * Else returns another Tristate value
 *
 * @return nts::Tristate
 */
nts::Tristate nts::Components::DFlipFlopComponent::computeComponent()
{
    if (this->pins[3]->compute() == TRUE || this->pins[5]->compute() == TRUE)
        return Tristate::FALSE;
    if (this->firstComputed == Tristate::UNDEFINED && this->clockPrev == Tristate::UNDEFINED)
        this->firstComputed = this->pins[2]->compute();
    if (this->firstComputed == Tristate::UNDEFINED)
        return Tristate::FALSE;
    if (this->clockPrev == Tristate::UNDEFINED) {
        this->clockPrev = this->firstComputed;
        return Tristate::UNDEFINED;
    }
    this->clockPrev = this->pins[2]->compute();
    if (this->clockPrev == this->firstComputed) {
        return Tristate::UNDEFINED;
    }
    this->firstComputed = Tristate::UNDEFINED;
    return Tristate::FALSE;
}
