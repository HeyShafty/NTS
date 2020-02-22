/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AComponent
*/

#include "AComponent.hpp"
#include "Exceptions/WrongPinException.hpp"

std::unordered_set<nts::Pin *> nts::AComponent::callHistory;
nts::Pin *nts::AComponent::callingPin = nullptr;

nts::AComponent::AComponent(const std::string &name, size_t pin_nb)
    : name(name), pin_nb(pin_nb)
{
    for (size_t i = 0; i < this->pin_nb; i++) {
        this->pins.push_back(std::make_shared<Pin>());
    }
}

const std::shared_ptr<nts::Pin> &nts::AComponent::getPin(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Cannot get pin: out of range.", this->name);
    return this->pins[pin - 1];
}

void nts::AComponent::setLink(size_t pin, const IComponent &other, size_t otherPin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Cannot link pin: out of range.", this->name);
    if (this->pins[pin - 1]->type != PinType::IN)
        throw nts::Exception::WrongPinException("Cannot link pin: not an input pin.", this->name);
    this->pins[pin - 1]->link = &other;
    this->pins[pin - 1]->link_n = otherPin;
}

nts::Tristate nts::AComponent::compute(size_t pin) const
{
    if (pin == 0 || pin > this->pin_nb)
        throw nts::Exception::WrongPinException("Cannot compute pin: out of range.", this->name);
    if (this->pins[pin - 1]->type == PinType::ELECTRICAL)
        throw nts::Exception::WrongPinException("Cannot compute pin: electrical pin.", this->name);
    Tristate result = this->pins[pin - 1]->compute();
    this->pins[pin - 1]->value = result;
    return result;
}

void nts::AComponent::dump() const
{
    // TODEV
}

nts::Tristate nts::AComponent::computeInPin(size_t pin_index) const
{
    if (this->pins[pin_index]->link == nullptr)
        return Tristate::UNDEFINED;
    if (this->callHistory.find(this->pins[pin_index].get()) != this->callHistory.end())
        return this->pins[pin_index]->link->getPin(this->pins[pin_index]->link_n)->value;
    else {
        if (this->callingPin == nullptr)
            this->callingPin = this->pins[pin_index].get();
        this->callHistory.insert(this->pins[pin_index].get());

        Tristate value = this->pins[pin_index]->link->compute(this->pins[pin_index]->link_n);

        if (this->pins[pin_index].get() == this->callingPin) {
            this->callingPin = nullptr;
            this->callHistory.clear();
        }
        return value;
    }
}
