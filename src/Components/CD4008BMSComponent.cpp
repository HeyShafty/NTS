/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CD4008BMSComponent
*/

#include "Components/CD4008BMSComponent.hpp"
#include "Components/SumComponent.hpp"
#include "Exceptions/WrongPinException.hpp"
#include "Factory.hpp"

nts::Components::CD4008BMSComponent::CD4008BMSComponent()
    : AComponent("CD4008BMSComponent", 16)
{
    std::shared_ptr<IComponent> cSum1 = nts::Factory::createComponent("sum");
    std::shared_ptr<IComponent> cSum2 = nts::Factory::createComponent("sum");
    std::shared_ptr<IComponent> cSum3 = nts::Factory::createComponent("sum");
    std::shared_ptr<IComponent> cSum4 = nts::Factory::createComponent("sum");

    this->pins[5] = cSum1->getPin(1); // input
    this->pins[6] = cSum1->getPin(2); // input
    this->pins[8] = cSum1->getPin(3); // carryIn
    this->pins[9] = cSum1->getPin(4); // output

    this->pins[3] = cSum2->getPin(1);
    this->pins[4] = cSum2->getPin(2);
    cSum2->setLink(3, *cSum1, 5); // linking output carry of cSum1 to input carry of cSum2
    this->pins[10] = cSum2->getPin(4);

    this->pins[1] = cSum3->getPin(1);
    this->pins[2] = cSum3->getPin(2);
    cSum3->setLink(3, *cSum2, 5);
    this->pins[11] = cSum3->getPin(4);

    this->pins[0] = cSum4->getPin(1);
    this->pins[14] = cSum4->getPin(2);
    cSum4->setLink(3, *cSum3, 5);
    this->pins[12] = cSum4->getPin(4);

    this->pins[7]->type = PinType::ELECTRICAL;
    this->pins[15]->type = PinType::ELECTRICAL;
    this->pins[13] = cSum4->getPin(5);
    this->innerComponents.push_back(cSum1);
    this->innerComponents.push_back(cSum2);
    this->innerComponents.push_back(cSum3);
    this->innerComponents.push_back(cSum4);
}
