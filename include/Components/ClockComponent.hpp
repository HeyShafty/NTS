/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** ClockComponent
*/

#ifndef CLOCKCOMPONENT_HPP_
#define CLOCKCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class ClockComponent : public AComponent
    {
        public:
            ClockComponent(nts::Tristate pinValue);
            ~ClockComponent() = default;

            nts::Tristate computeCompoent(void);

        protected:
        private:
    };
}

#endif /* !CLOCKCOMPONENT_HPP_ */
