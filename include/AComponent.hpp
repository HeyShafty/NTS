/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AComponent
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <unordered_set>
#include <vector>
#include "IComponent.hpp"

#define BIND_IN_PIN(idx, o) this->pins[idx]->compute = std::bind(&o::computeInPin, this, idx)

namespace nts
{
    class AComponent : public IComponent
    {
        protected:
            AComponent(const std::string &componentName, size_t pin_nb);

        public:
            virtual ~AComponent() = default;

            const std::shared_ptr<Pin> &getPin(size_t pin) const override;

            Tristate compute(size_t pin = 1) const final;
            void setLink(size_t pin, const IComponent &other, size_t otherPin) const final;
            void dump() const override;

        protected:
            const std::string componentName;
            const size_t pin_nb;
            std::vector<std::shared_ptr<Pin>> pins;

            Tristate computeInPin(size_t pin_index) const;

        private:
            static std::unordered_set<Pin *> callHistory;
            static Pin *callingPin;
    };
}

#endif /* !COMPONENT_HPP_ */
