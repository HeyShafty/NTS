/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** TerminalComponent
*/

#ifndef TerminalComponent_HPP_
#define TerminalComponent_HPP_

#include "AComponent.hpp"
#include "ISimulable.hpp"

namespace nts::Components
{
    class TerminalComponent : public AComponent, public ISimulable
    {
        public:
            TerminalComponent();
            ~TerminalComponent() = default;

            void simulate() const override;
    };
}

#endif /* !TerminalComponent_HPP_ */
