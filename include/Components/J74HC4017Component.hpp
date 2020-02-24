/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** J74HC4017Component
*/

#ifndef J74HC4017COMPONENT_HPP_
#define J74HC4017COMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class J74HC4017Component : public AComponent
    {
        public:
            J74HC4017Component();
            ~J74HC4017Component() = default;

        protected:
        private:
            std::vector<std::shared_ptr<IComponent>> innerComponents;
    };
}

#endif /* !J74HC4017COMPONENT_HPP_ */
