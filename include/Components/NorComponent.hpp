/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NorComponent
*/

#ifndef NorComponent_HPP_
#define NorComponent_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class NorComponent : public AComponent
    {
        public:
            NorComponent(const std::string &name);
            ~NorComponent() = default;

        private:
            Tristate computeComponent() const;
    };
}

#endif /* !NorComponent_HPP_ */
