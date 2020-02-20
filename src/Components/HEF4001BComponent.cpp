/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** HEF4001BComponent
*/

#include "Components/HEF4001BComponent.hpp"
#include "Components/NorComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::HEF4001BComponent::HEF4001BComponent()
    : Component("4071", 14)
{
    std::shared_ptr<IComponent> cNor1 = std::make_shared<NorComponent>();
    std::shared_ptr<IComponent> cNor2 = std::make_shared<NorComponent>();
    std::shared_ptr<IComponent> cNor3 = std::make_shared<NorComponent>();
    std::shared_ptr<IComponent> cNor4 = std::make_shared<NorComponent>();

    this->pins[0] = cNor1->getPin(1);
    this->pins[1] = cNor1->getPin(2);
    this->pins[2] = cNor1->getPin(3);
    this->pins[3] = cNor2->getPin(3);
    this->pins[4] = cNor2->getPin(1);
    this->pins[5] = cNor2->getPin(2);
    this->pins[6]->type = PinType::ELECTRICAL;
    this->pins[7] = cNor3->getPin(1);
    this->pins[8] = cNor3->getPin(2);
    this->pins[9] = cNor3->getPin(3);
    this->pins[10] = cNor4->getPin(3);
    this->pins[11] = cNor4->getPin(1);
    this->pins[12] = cNor4->getPin(2);
    this->pins[13]->type = PinType::ELECTRICAL;
    this->innerComponents.push_back(cNor1);
    this->innerComponents.push_back(cNor2);
    this->innerComponents.push_back(cNor3);
    this->innerComponents.push_back(cNor4);
}

nts::Tristate nts::Components::HEF4001BComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Pin is out of range.", "CD4030CComponent");
    if (this->pins[pin - 1]->type == PinType::ELECTRICAL)
        throw nts::Exception::WrongPinException("Pin cannot be computed (electrical)", "HCF4081BComponent");
    return this->pins[pin - 1]->compute();
}
