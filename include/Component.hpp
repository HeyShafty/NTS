/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <memory>
#include "IComponent.hpp"
#include "Pin.hpp"

namespace nts
{
    class Component : public IComponent
    {
        public:
            Component(const std::string &name, size_t pin_nb);
            virtual ~Component();

            void setLink(size_t pin, const IComponent &other, size_t otherPin) const override;
            virtual void dump() const override;

        protected:
            const std::string name;
            const size_t pin_nb;
            std::unique_ptr<Pin[]> pins;
    };
}

#endif /* !COMPONENT_HPP_ */
