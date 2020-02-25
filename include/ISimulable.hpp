/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** ISimulable
*/

#ifndef ISIMULABLE_HPP_
#define ISIMULABLE_HPP_

class ISimulable
{
    public:
        virtual ~ISimulable() = default;

        virtual void simulate() const = 0;
};

#endif /* !ISIMULABLE_HPP_ */
