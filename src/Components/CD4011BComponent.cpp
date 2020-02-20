/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CD4011B
*/

#include "Components/CD4011BComponent.hpp"
#include "Components/NandComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::CD4011BComponent::CD4011BComponent()
    : AComponent("CD4011BComponent", 14)
{
    std::shared_ptr<IComponent> cNand1 = std::make_shared<NandComponent>();
    std::shared_ptr<IComponent> cNand2 = std::make_shared<NandComponent>();
    std::shared_ptr<IComponent> cNand3 = std::make_shared<NandComponent>();
    std::shared_ptr<IComponent> cNand4 = std::make_shared<NandComponent>();

    this->pins[0] = cNand1->getPin(1);
    this->pins[1] = cNand1->getPin(2);
    this->pins[2] = cNand1->getPin(3);
    this->pins[3] = cNand2->getPin(3);
    this->pins[4] = cNand2->getPin(1);
    this->pins[5] = cNand2->getPin(2);
    this->pins[6]->type = PinType::ELECTRICAL;
    this->pins[7] = cNand3->getPin(1);
    this->pins[8] = cNand3->getPin(2);
    this->pins[9] = cNand3->getPin(3);
    this->pins[10] = cNand4->getPin(3);
    this->pins[11] = cNand4->getPin(1);
    this->pins[12] = cNand4->getPin(2);
    this->pins[13]->type = PinType::ELECTRICAL;
    this->innerComponents.push_back(cNand1);
    this->innerComponents.push_back(cNand2);
    this->innerComponents.push_back(cNand3);
    this->innerComponents.push_back(cNand4);
}

nts::Tristate nts::Components::CD4011BComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Pin is out of range.", "CD4011BComponent");
    if (this->pins[pin - 1]->type == PinType::ELECTRICAL)
        throw nts::Exception::WrongPinException("Pin cannot be computed (electrical)", "CD4011BComponent");
    return this->pins[pin - 1]->compute();
}
