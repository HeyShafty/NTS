/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CD4094BCComponent
*/

#ifndef CD4094BCCOMPONENT_HPP_
#define CD4094BCCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class CD4094BCComponent : public AComponent
    {
        public:
            CD4094BCComponent(const std::string &name);
            ~CD4094BCComponent() = default;

        private:
            Tristate computeComponent(int q);

            Tristate clockSave;
            unsigned char value;
    };
}

#endif /* !CD4094BCCOMPONENT_HPP_ */
