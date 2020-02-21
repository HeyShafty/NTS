/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CD4514BC
*/

#ifndef CD4514BC_HPP_
#define CD4514BC_HPP_

#include "AComponent.hpp"

namespace nts::Components
{
    class CD4514BCComponent : public AComponent {
        public:
            CD4514BCComponent();
            ~CD4514BCComponent() = default;

        private:
            // Tristate computeComponent(size_t bit_index) const;
            // int getBitValue(Tristate bit1, Tristate bit2, Tristate bit3, Tristate bit4) const;

            std::vector<std::shared_ptr<IComponent>> innerComponents;
    };

}

#endif /* !CD4514BC_HPP_ */
