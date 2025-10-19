#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

struct Contact {
    static inline int counterId = 1;
    int contactId;
    std::string name;
    int phoneNumber;

    Contact() {
        this->contactId = counterId;
        counterId++;
        this->name = "";
        this->phoneNumber = 0;
    }

    Contact(const std::string& contactName, int contactPhoneNumber) {
        this->contactId = counterId;
        counterId++;
        this->name = contactName;
        this->phoneNumber = contactPhoneNumber;
    }
};

#endif
