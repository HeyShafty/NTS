/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** HCF4081BComponent
*/

#include "Components/HCF4081BComponent.hpp"
#include "Components/AndComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::HCF4081BComponent::HCF4081BComponent()
    : Component("4081Component", 14)
{
    std::shared_ptr<IComponent> cAnd1 = std::make_shared<AndComponent>();
    std::shared_ptr<IComponent> cAnd2 = std::make_shared<AndComponent>();
    std::shared_ptr<IComponent> cAnd3 = std::make_shared<AndComponent>();
    std::shared_ptr<IComponent> cAnd4 = std::make_shared<AndComponent>();

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
    this->innerComponents.push_back(cAnd1);
    this->innerComponents.push_back(cAnd2);
    this->innerComponents.push_back(cAnd3);
    this->innerComponents.push_back(cAnd4);
}

nts::Tristate nts::Components::HCF4081BComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Given pin is out of range", "HCF4081BComponent");
    if (this->pins[pin - 1]->type == PinType::ELECTRICAL)
        throw nts::Exception::WrongPinException("Pin cannot be computed (electrical)", "HCF4081BComponent");
    return this->pins[pin - 1]->compute();
}
