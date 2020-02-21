/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** HCF4081BComponent
*/

#include "Components/HCF4081BComponent.hpp"
#include "Components/AndComponent.hpp"
#include "Exceptions/WrongPinException.hpp"
#include "Factory.hpp"

nts::Components::HCF4081BComponent::HCF4081BComponent()
    : AComponent("HCF4081BComponent", 14)
{
    std::unique_ptr<IComponent> cAnd1 = nts::Factory::createComponent("and");
    std::unique_ptr<IComponent> cAnd2 = nts::Factory::createComponent("and");
    std::unique_ptr<IComponent> cAnd3 = nts::Factory::createComponent("and");
    std::unique_ptr<IComponent> cAnd4 = nts::Factory::createComponent("and");

    this->pins[0] = cAnd1->getPin(1);
    this->pins[1] = cAnd1->getPin(2);
    this->pins[2] = cAnd1->getPin(3);
    this->pins[3] = cAnd2->getPin(3);
    this->pins[4] = cAnd2->getPin(1);
    this->pins[5] = cAnd2->getPin(2);
    this->pins[6]->type = PinType::ELECTRICAL;
    this->pins[7] = cAnd3->getPin(1);
    this->pins[8] = cAnd3->getPin(2);
    this->pins[9] = cAnd3->getPin(3);
    this->pins[10] = cAnd4->getPin(3);
    this->pins[11] = cAnd4->getPin(1);
    this->pins[12] = cAnd4->getPin(2);
    this->pins[13]->type = PinType::ELECTRICAL;
    this->innerComponents.push_back(std::move(cAnd1));
    this->innerComponents.push_back(std::move(cAnd2));
    this->innerComponents.push_back(std::move(cAnd3));
    this->innerComponents.push_back(std::move(cAnd4));
}
