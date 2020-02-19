/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include <stdio.h>
#include <stdbool.h>
#include "Components/TrueComponent.hpp"
#include "Components/AndComponent.hpp"
#include "Components/N4081Component.hpp"

int main(int argc, char *argv[])
{
    std::unique_ptr<nts::IComponent> c4081(new nts::Components::HCF4081BComponent);
    std::unique_ptr<nts::IComponent> cAnd(new nts::Components::AndComponent);
    std::unique_ptr<nts::IComponent> cFalse1(new nts::Components::TrueComponent);
    std::unique_ptr<nts::IComponent> cFalse2(new nts::Components::TrueComponent);


    (void)argc;
    (void)argv;
    printf("%d\n", cAnd->compute(3));
    cAnd->setLink(1, *cFalse1, 1);
    printf("%d\n", cAnd->compute(3));
    cAnd->setLink(2, *cFalse2, 1);
    printf("%d\n", cAnd->compute(3));
    c4081->setLink(1, *cFalse1, 1);
    c4081->setLink(2, *cFalse2, 1);
    printf("%d %d %d %d\n", c4081->compute(3), c4081->compute(6), c4081->compute(10), c4081->compute(13));
    return (0);
}
