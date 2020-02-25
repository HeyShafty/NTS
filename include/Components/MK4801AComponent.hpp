/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** MK4801AComponent
*/

#ifndef MK4801AComponent_HPP_
#define MK4801AComponent_HPP_

#include "AComponent.hpp"
#include "ISimulable.hpp"

#define BIND_PIN(idx) this->pins[idx]->type = PinType::OUT; \
this->pins[idx]->compute = std::bind(&MK4801AComponent::computeComponent, this, idx)

namespace nts::Components
{
    class MK4801AComponent : public AComponent, public ISimulable
    {
        public:
            MK4801AComponent();
            ~MK4801AComponent() = default;

            void simulate() const override;

        private:
            Tristate computeComponent(size_t pin_index) const;
            int xDecode() const;
            int yDecode() const;

            char mem[1024] = {0};
    };
}


#endif /* !MK4801AComponent_HPP_ */
