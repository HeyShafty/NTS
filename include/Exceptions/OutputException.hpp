/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** OutputException
*/

#ifndef OUTPUTEXCEPTION_HPP_
#define OUTPUTEXCEPTION_HPP_

#include "NtsException.hpp"

namespace nts::Exception
{
    /**
     * @brief
     * To be raised when one or several outputs are not linked
     */
    class OutputException : NtsException
    {
        public:
            OutputException(std::string const &message, std::string const &component = "Unknown");

        protected:
        private:
    };
}

#endif /* !OUTPUTEXCEPTION_HPP_ */
