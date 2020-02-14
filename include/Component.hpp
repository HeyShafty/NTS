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
            Component();
            ~Component();
    };
}

#endif /* !COMPONENT_HPP_ */
