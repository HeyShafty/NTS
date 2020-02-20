/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CD4030C
*/

#include "Components/CD4030CComponent.hpp"
#include "Components/XorComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::CD4030CComponent::CD4030CComponent()
    : Component("CD4030CComponent", 14)
{
    std::shared_ptr<IComponent> cXor1 = std::make_shared<XorComponent>();
    std::shared_ptr<IComponent> cXor2 = std::make_shared<XorComponent>();
    std::shared_ptr<IComponent> cXor3 = std::make_shared<XorComponent>();
    std::shared_ptr<IComponent> cXor4 = std::make_shared<XorComponent>();

    this->pins[0] = cXor1->getPin(1);
    this->pins[1] = cXor1->getPin(2);
    this->pins[2] = cXor1->getPin(3);
    this->pins[3] = cXor1->getPin(3);
    this->pins[4] = cXor1->getPin(1);
    this->pins[5] = cXor1->getPin(2);
    this->pins[6]->type = PinType::ELECTRICAL;
    this->pins[7] = cXor1->getPin(1);
    this->pins[8] = cXor1->getPin(2);
    this->pins[9] = cXor1->getPin(3);
    this->pins[10] = cXor1->getPin(3);
    this->pins[11] = cXor1->getPin(1);
    this->pins[12] = cXor1->getPin(2);
    this->pins[13]->type = PinType::ELECTRICAL;
    this->innerComponents.push_back(cXor1);
    this->innerComponents.push_back(cXor2);
    this->innerComponents.push_back(cXor3);
    this->innerComponents.push_back(cXor4);
}

nts::Tristate nts::Components::CD4030CComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Pin is out of range.", "CD4030CComponent");
    if (this->pins[pin - 1]->type == PinType::ELECTRICAL)
        throw nts::Exception::WrongPinException("Pin cannot be computed (electrical)", "CD4030CComponent");
    return this->pins[pin - 1]->compute();
}
