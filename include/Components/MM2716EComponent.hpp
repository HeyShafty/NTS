/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** MM2716EComponent
*/

#ifndef MM2716ECOMPONENT_HPP_
#define MM2716ECOMPONENT_HPP_

#include "AComponent.hpp"

#define BIND_PIN(idx) this->pins[idx]->type = PinType::OUT; \
this->pins[idx]->compute = std::bind(&MM2716EComponent::computeComponent, this, idx)

namespace nts::Components
{
    class MM2716EComponent : public AComponent {
        public:
            MM2716EComponent(const std::string &name, const std::string &filepath);
            ~MM2716EComponent() = default;

        private:
            Tristate computeComponent(size_t pin_index) const;
            int xDecode() const;
            int yDecode() const;

            char mem[2048] = {0};
    };
}


#endif /* !MM2716ECOMPONENT_HPP_ */
