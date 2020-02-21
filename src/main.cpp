/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include <stdio.h>
#include <stdbool.h>
#include "Components/TrueComponent.hpp"
#include "Components/FalseComponent.hpp"
#include "Components/DFlipFlopComponent.hpp"
#include "Components/AndComponent.hpp"
#include "Components/HCF4081BComponent.hpp"
#include "Components/CD4514BCComponent.hpp"
#include "Components/SRFlipFlopComponent.hpp"

// int toto(int argc, char *argv[])
// {
    // std::unique_ptr<nts::IComponent> c4081(new nts::Components::HCF4081BComponent);
//     std::unique_ptr<nts::IComponent> cAnd(new nts::Components::AndComponent);
//     std::unique_ptr<nts::IComponent> cFalse1(new nts::Components::TrueComponent);
//     std::unique_ptr<nts::IComponent> cFalse2(new nts::Components::TrueComponent);


//     (void)argc;
//     (void)argv;
//     printf("%d\n", cAnd->compute(3));
//     cAnd->setLink(1, *cFalse1, 1);
//     printf("%d\n", cAnd->compute(3));
//     cAnd->setLink(2, *cFalse2, 1);
//     printf("%d\n", cAnd->compute(3));
//     c4081->setLink(1, *cFalse1, 1);
//     c4081->setLink(2, *cFalse2, 1);
//     printf("%d %d %d %d\n", c4081->compute(3), c4081->compute(6), c4081->compute(10), c4081->compute(13));
//     return (0);
// }

// int toto2(void)
// {
//     std::unique_ptr<nts::IComponent> clock(new nts::Components::FalseComponent);
//     std::unique_ptr<nts::IComponent> reset(new nts::Components::FalseComponent);
//     std::unique_ptr<nts::IComponent> data(new nts::Components::FalseComponent);
//     std::unique_ptr<nts::IComponent> set(new nts::Components::FalseComponent);
//     std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::DFlipFlopComponent);

//     dFlipFlop->setLink(3, *clock, 1);
//     dFlipFlop->setLink(4, *reset, 1);
//     dFlipFlop->setLink(5, *data, 1);
//     dFlipFlop->setLink(6, *set, 1);
//     printf("%d\n", dFlipFlop->compute(1));
//     printf("%d\n", dFlipFlop->compute(1));
//     printf("%d\n", dFlipFlop->compute(1));
// }

// int toto3(void)
// {
//     std::unique_ptr<nts::IComponent> set(new nts::Components::TrueComponent);
//     std::unique_ptr<nts::IComponent> dFlipFlop(new nts::Components::DFlipFlopComponent);

//     dFlipFlop->setLink(6, *set, 1);
//     printf("%d\n", dFlipFlop->compute(1));
//     return 0;
// }

// int toto4(void)
// {
//     std::unique_ptr<nts::IComponent> srFlipFlop(new nts::Components::SRFlipFlopComponent);
//     std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
//     std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

//     srFlipFlop->setLink(1, *cTrue, 1);
//     srFlipFlop->setLink(2, *cTrue, 1);
//     printf("%d\n", srFlipFlop->compute(3));
//     printf("%d\n", srFlipFlop->compute(4));
//     srFlipFlop->setLink(1, *cFalse, 1);
//     printf("%d\n", srFlipFlop->compute(3)); // FALSE
//     printf("%d\n", srFlipFlop->compute(4)); // TRUE
// }

int main(void)
{
    std::unique_ptr<nts::IComponent> decoder(new nts::Components::CD4514BCComponent);
    std::unique_ptr<nts::IComponent> cTrue(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse(new nts::Components::FalseComponent);

    decoder->setLink(1, *cFalse, 1);
    decoder->setLink(2, *cFalse, 1);
    decoder->setLink(21, *cFalse, 1);
    decoder->setLink(22, *cFalse, 1);
    decoder->setLink(23, *cFalse, 1);
    printf("%d\n", decoder->compute(11));
    printf("%d\n", decoder->compute(9));
    printf("%d\n", decoder->compute(10));
    printf("%d\n", decoder->compute(8));
    printf("%d\n", decoder->compute(7));
    printf("%d\n", decoder->compute(6));
    printf("%d\n", decoder->compute(5));
    printf("%d\n", decoder->compute(4));
    printf("%d\n", decoder->compute(18));
    printf("%d\n", decoder->compute(17));
    printf("%d\n", decoder->compute(20));
    printf("%d\n", decoder->compute(19));
    printf("%d\n", decoder->compute(14));
    printf("%d\n", decoder->compute(13));
    printf("%d\n", decoder->compute(16));
    printf("%d\n", decoder->compute(15));
}
