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
            ClockComponent(const std::string &name, nts::Tristate pinValue);
            ~ClockComponent() = default;

            void simulate() const override;

        private:
            nts::Tristate computeComponent(void);
            std::unique_ptr<bool> init;
    };
}

#endif /* !CLOCKCOMPONENT_HPP_ */
