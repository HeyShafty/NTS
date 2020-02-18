/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** N4081Component
*/

#include "Components/N4081Component.hpp"
#include "Components/AndComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::N4081Component::N4081Component()
    : Component("4081Component", 14)
{
    std::shared_ptr<IComponent> cAnd1 = std::make_shared<AndComponent>();
    std::shared_ptr<IComponent> cAnd2 = std::make_shared<AndComponent>();
    std::shared_ptr<IComponent> cAnd3 = std::make_shared<AndComponent>();
    std::shared_ptr<IComponent> cAnd4 = std::make_shared<AndComponent>();
    this->pins[0].reset(cAnd1->getPin(0));
    this->pins[1].reset(cAnd1->getPin(1));
    this->pins[2].reset(cAnd1->getPin(2));
    this->pins[3].reset(cAnd2->getPin(0));
    this->pins[4].reset(cAnd2->getPin(1));
    this->pins[5].reset(cAnd2->getPin(2));
    this->pins[6]->type = PinType::ELECTRICAL;
    this->pins[7].reset(cAnd3->getPin(0));
    this->pins[8].reset(cAnd3->getPin(1));
    this->pins[9].reset(cAnd3->getPin(2));
    this->pins[10].reset(cAnd4->getPin(0));
    this->pins[11].reset(cAnd4->getPin(1));
    this->pins[12].reset(cAnd4->getPin(2));
    this->pins[13]->type = PinType::ELECTRICAL;
    this->innerComponents.push_back(cAnd1);
    this->innerComponents.push_back(cAnd2);
    this->innerComponents.push_back(cAnd3);
    this->innerComponents.push_back(cAnd4);
}

nts::Tristate nts::Components::N4081Component::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Given pin is out of range", "FalseComponent");
    if (this->pins[pin - 1]->type == PinType::ELECTRICAL)
        throw nts::Exception::WrongPinException("Pin cannot be computed (electrical)", "FalseComponent");
    return this->pins[pin - 1]->value;
}
