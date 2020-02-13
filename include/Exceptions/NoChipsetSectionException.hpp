/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NoChipsetSectionException
*/

#ifndef NoChipsetSectionException_HPP_
#define NoChipsetSectionException_HPP_

#include "NtsException.hpp"

namespace nts::Exception
{
    /**
     * @brief
     * Exception to be raised when there is no chipset section in given file
     */
    class NoChipsetSectionException : public NtsException
    {
        public:
            NoChipsetSectionException(std::string const &message, std::string const &component = "Unknown");

        protected:
        private:
    };
}


#endif /* !NoChipsetSectionException_HPP_ */
