/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CD4514BCComponent
*/

#include "Components/CD4514BCComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

nts::Components::CD4514BCComponent::CD4514BCComponent()
    : AComponent("CD4514BCComponent", 24)
{
    // std::shared_ptr<IComponent> cXor1 = std::make_shared<XorComponent>();
    // std::shared_ptr<IComponent> cXor2 = std::make_shared<XorComponent>();
    // std::shared_ptr<IComponent> cXor3 = std::make_shared<XorComponent>();
    // std::shared_ptr<IComponent> cXor4 = std::make_shared<XorComponent>();

    this->pins[0]->compute = std::bind(&CD4514BCComponent::computeInPin, this, 0);
    this->pins[1]->compute = std::bind(&CD4514BCComponent::computeInPin, this, 1);
    this->pins[2]->compute = std::bind(&CD4514BCComponent::computeInPin, this, 2);
    this->pins[3]->compute = std::bind(&CD4514BCComponent::computeComponent, this, 3);
    this->pins[4]->compute = std::bind(&CD4514BCComponent::computeComponent, this, 4);
    this->pins[5]->compute = std::bind(&CD4514BCComponent::computeComponent, this, 5);
    this->pins[6]->compute = std::bind(&CD4514BCComponent::computeComponent, this, 6);
    this->pins[7]->compute = std::bind(&CD4514BCComponent::computeComponent, this, 7);
    this->pins[8]->compute = std::bind(&CD4514BCComponent::computeComponent, this, 8);
    this->pins[9]->compute = std::bind(&CD4514BCComponent::computeComponent, this, 9);
    this->pins[10]->compute = std::bind(&CD4514BCComponent::computeComponent, this, 10);
    this->pins[11]->type = PinType::ELECTRICAL;
    this->pins[12]->compute = std::bind(&CD4514BCComponent::computeComponent, this, 12);
    this->pins[13]->compute = std::bind(&CD4514BCComponent::computeComponent, this, 13);
    this->pins[14]->compute = std::bind(&CD4514BCComponent::computeComponent, this, 14);
    this->pins[15]->compute = std::bind(&CD4514BCComponent::computeComponent, this, 15);
    this->pins[16]->compute = std::bind(&CD4514BCComponent::computeComponent, this, 16);
    this->pins[17]->compute = std::bind(&CD4514BCComponent::computeComponent, this, 17);
    this->pins[18]->compute = std::bind(&CD4514BCComponent::computeComponent, this, 18);
    this->pins[19]->compute = std::bind(&CD4514BCComponent::computeComponent, this, 19);
    this->pins[20]->compute = std::bind(&CD4514BCComponent::computeInPin, this, 20);
    this->pins[21]->compute = std::bind(&CD4514BCComponent::computeInPin, this, 21);
    this->pins[22]->compute = std::bind(&CD4514BCComponent::computeInPin, this, 22);
    this->pins[23]->type = PinType::ELECTRICAL;
    // this->innerComponents.push_back();
}

nts::Tristate nts::Components::CD4514BCComponent::computeComponent(size_t bit_index) const
{
    Tristate strobe = this->pins[0]->compute();
    Tristate bit1 = this->pins[1]->compute();
    Tristate bit2 = this->pins[2]->compute();
    Tristate bit3 = this->pins[20]->compute();
    Tristate bit4 = this->pins[21]->compute();
    Tristate inhibit = this->pins[22]->compute();
    Tristate newValue;

    if (inhibit == Tristate::TRUE) {

    } else /* if (strobe == Tristate::TRUE) */ {

    }
    return this->pins[bit_index]->value;
}

int nts::Components::CD4514BCComponent::getBitValue(Tristate bit1,
                                                    Tristate bit2,
                                                    Tristate bit3,
                                                    Tristate bit4) const
{
    int bit = 0;

    if ((bit1 && bit2 && bit3 && bit4) == Tristate::UNDEFINED)
        return -1;
    bit += (bit1 << 3) | (bit2 << 2) | (bit3 << 1) | bit4;
    return bit;
}
