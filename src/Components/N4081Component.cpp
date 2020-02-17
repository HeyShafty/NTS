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
    std::vector<std::shared_ptr<IComponent>> innerComponents;
    std::shared_ptr<IComponent> ptr = std::make_shared<AndComponent>();
    this->pins[0].reset(ptr->getPin(0));
    this->pins[1].reset(ptr->getPin(1));
    this->pins[2].reset(ptr->getPin(2));
    innerComponents.push_back(ptr);

    // this->pins[3] = cAnd2->pins[0];
    // this->pins[4] = cAnd2->pins[1];
    // this->pins[5] = cAnd2->pins[2];
    this->pins[6]->type = PinType::ELECTRICAL;
    // this->pins[7] = cAnd3->pins[0];
    // this->pins[8] = cAnd3->pins[1];
    // this->pins[9] = cAnd3->pins[2];
    // this->pins[10] = cAnd4->pins[0];
    // this->pins[11] = cAnd4->pins[1];
    // this->pins[12] = cAnd4->pins[2];
    this->pins[13]->type = PinType::ELECTRICAL;
}

nts::Components::N4081Component::~N4081Component()
{
}

nts::Tristate nts::Components::N4081Component::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Given pin is out of range", "FalseComponent");
    if (this->pins[pin - 1]->type == PinType::ELECTRICAL)
        throw nts::Exception::WrongPinException("Pin cannot be computed (electrical)", "FalseComponent");
    return this->pins[pin - 1]->value;
}
