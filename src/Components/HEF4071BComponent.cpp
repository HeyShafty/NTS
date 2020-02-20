/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** HEF4071BComponent
*/

#include "Components/HEF4071BComponent.hpp"
#include "Components/OrComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::HEF4071BComponent::HEF4071BComponent()
    : Component("HEF4071BComponent", 14)
{
    std::shared_ptr<IComponent> cOr1 = std::make_shared<OrComponent>();
    std::shared_ptr<IComponent> cOr2 = std::make_shared<OrComponent>();
    std::shared_ptr<IComponent> cOr3 = std::make_shared<OrComponent>();
    std::shared_ptr<IComponent> cOr4 = std::make_shared<OrComponent>();

    this->pins[0] = cOr1->getPin(1);
    this->pins[1] = cOr1->getPin(2);
    this->pins[2] = cOr1->getPin(3);
    this->pins[3] = cOr2->getPin(3);
    this->pins[4] = cOr2->getPin(1);
    this->pins[5] = cOr2->getPin(2);
    this->pins[6]->type = PinType::ELECTRICAL;
    this->pins[7] = cOr3->getPin(1);
    this->pins[8] = cOr3->getPin(2);
    this->pins[9] = cOr3->getPin(3);
    this->pins[10] = cOr4->getPin(3);
    this->pins[11] = cOr4->getPin(1);
    this->pins[12] = cOr4->getPin(2);
    this->pins[13]->type = PinType::ELECTRICAL;
    this->innerComponents.push_back(cOr1);
    this->innerComponents.push_back(cOr2);
    this->innerComponents.push_back(cOr3);
    this->innerComponents.push_back(cOr4);
}

nts::Tristate nts::Components::HEF4071BComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Pin is out of range.", "CD4030CComponent");
    if (this->pins[pin - 1]->type == PinType::ELECTRICAL)
        throw nts::Exception::WrongPinException("Pin cannot be computed (electrical)", "HCF4081BComponent");
    return this->pins[pin - 1]->compute();
}
