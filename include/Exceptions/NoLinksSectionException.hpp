/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NoLinksSectionException
*/

#ifndef NoLinksSectionException_HPP_
#define NoLinksSectionException_HPP_

#include "NtsException.hpp"

namespace nts::Exception
{
    /**
     * @brief
     * To be raised when there is no links section in given file
     */
    class NoLinksSectionException : public NtsException
    {
        public:
            NoLinksSectionException(std::string const &message, std::string const &component = "Unknown");

        protected:
        private:
    };
}



#endif /* !NoLinksSectionException_HPP_ */
