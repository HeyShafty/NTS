/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** CircuitFileException
*/

#ifndef CIRCUITFILEEXCEPTION_HPP_
#define CIRCUITFILEEXCEPTION_HPP_

#include "NtsException.hpp"

namespace nts::exception
{
    /**
     * @brief
     * To be raised when there is a syntax or lexical error in given circuit file
     */
    class CircuitFileException : public NtsException
    {
        public:
            CircuitFileException(std::string const &message, std::string const &component = "Unknown");

        protected:
        private:
    };
}

#endif /* !CIRCUITFILEEXCEPTION_HPP_ */
