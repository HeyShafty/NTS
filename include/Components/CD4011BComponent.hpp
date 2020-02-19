/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CD4011B
*/

#ifndef CD4011B_HPP_
#define CD4011B_HPP_

#include "Component.hpp"

namespace nts::Components
{
    class CD4011BComponent : public Component
    {
        public:
            CD4011BComponent();
            ~CD4011BComponent() = default;

            nts::Tristate compute(size_t pin) const override;

        private:
            std::vector<std::shared_ptr<IComponent>> innerComponents;
    };
}



#endif /* !CD4011B_HPP_ */
