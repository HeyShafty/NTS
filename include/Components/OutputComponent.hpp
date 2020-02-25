/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** OutputComponent
*/

#ifndef OUTPUTCOMPONENT_HPP_
#define OUTPUTCOMPONENT_HPP_

#include "AComponent.hpp"
#include "ISimulable.hpp"

namespace nts::Components
{
    class OutputComponent : public AComponent, public ISimulable
    {
        public:
            OutputComponent();
            ~OutputComponent() = default;

            void simulate() const;
    };
}

#endif /* !OUTPUTCOMPONENT_HPP_ */
