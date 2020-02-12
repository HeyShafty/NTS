/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Pin
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include "IComponent.hpp"

namespace nts
{
    enum PinType
    {
        IN = 0,
        OUT = 1
    };

    /**
     * @brief Represents a chipset pin.
     *
     * @n Pin position on the chipset.
     * @value Value of the pin.
     * @type Pin type (IN or OUT)
     * @link Component linked to pin.
     * @link_n Position of linked pin.
     */
    struct Pin
    {
        size_t n;
        Tristate value;
        PinType type;
        const IComponent *link;
        size_t link_n;
    };
}

#endif /* !PIN_HPP_ */
