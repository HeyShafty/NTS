/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** XorComponent
*/

#ifndef XorCOMPONENT_HPP_
#define XorCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class XorComponent : public AComponent
    {
        public:
            XorComponent();
            ~XorComponent() = default;

        private:
            Tristate computeComponent() const;
    };
}

#endif /* !XorCOMPONENT_HPP_ */
