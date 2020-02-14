/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** TrueComponent
*/

#ifndef TRUECOMPONENT_HPP_
#define TRUECOMPONENT_HPP_

#include "Component.hpp"

namespace nts::Components
{
    class TrueComponent : public IComponent
    {
        private:
            size_t pin_nb;
            std::unique_ptr<Pin[]> pins;

        public:
            TrueComponent();
            ~TrueComponent();

            Tristate compute(size_t pin = 1) const override;
            void setLink(size_t pin, const IComponent &other, size_t otherPin) const override;
            void dump() const override;
    };
}

#endif /* !TRUECOMPONENT_HPP_ */
