#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "contact.h"
#include <boost/serialization/access.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>

class User {
private :
    int userId;
    std::string name;
    int phoneNumber;
    int loginState;
    std::vector<Contact> contacts;

    int contactIdCounter = 1;
    static int userIdCounter;

    friend class boost::serialization::access;

    template<class Archive>
    void serialize(Archive & ar, [[maybe_unused]] const unsigned int version) {
        ar & userId;
        ar & name;
        ar & phoneNumber;
        ar & loginState;
        ar & contacts;
        ar & contactIdCounter;
    }

public :
    User();
    User(const std::string& userName, int userPhoneNumber);

    // Getters
    int getUserId() const { return userId; }
    std::string getName() const { return name; }
    int getPhoneNumber() const { return phoneNumber; }
    std::vector<Contact> getContacts() const { return contacts; }

    // Method User
    bool addContact(std::string name, int phoneNumber);
    void printContacts() const;
};

#endif
