/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Pin
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include <functional>
#include "Tristate.h"

namespace nts
{
    enum PinType
    {
        IN = 0,
        OUT = 1,
        ELECTRICAL = 2
    };

    class IComponent;

    /**
     * @brief Represents a chipset pin.
     *
     * @type Pin type (IN or OUT)
     * @link Component linked to pin.
     * @link_n Position of linked pin.
     */
    struct Pin
    {
        Pin();
        ~Pin() = default;

        PinType type;
        const IComponent *link;
        size_t link_n;
        std::function<Tristate ()> compute;
    };
}

#endif /* !PIN_HPP_ */
