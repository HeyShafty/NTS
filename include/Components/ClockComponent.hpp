/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** ClockComponent
*/

#ifndef CLOCKCOMPONENT_HPP_
#define CLOCKCOMPONENT_HPP_

#include "AComponent.hpp"
#include "ISimulable.hpp"

namespace nts::Components
{
    class ClockComponent : public AComponent, public ISimulable
    {
        public:
            ClockComponent(nts::Tristate pinValue);
            ~ClockComponent() = default;

            void simulate() const override;

        private:
            nts::Tristate computeComponent(void);
    };
}

#endif /* !CLOCKCOMPONENT_HPP_ */
