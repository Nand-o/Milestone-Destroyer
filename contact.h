#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <boost/serialization/access.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>

struct Contact { 
    int contactId;
    int userId;
    std::string name;

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive & ar, [[maybe_unused]] const unsigned int version) {
        ar & contactId;
        ar & userId;
        ar & name;
        ar & phoneNumber;
    }

    int phoneNumber;

    // Default constructor required for Boost.Serialization when loading
    Contact() : contactId(0), userId(0), name(""), phoneNumber(0) {}

    Contact(int userId, const std::string& contactName, int contactPhoneNumber) {
        this->contactId = 0;
        this->userId = userId;
        this->name = contactName;
        this->phoneNumber = contactPhoneNumber;
    }
};

#endif
