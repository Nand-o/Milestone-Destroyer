#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "contact.h"

class User {
private :
    int userIdCounter = 1;
    int userId;
    std::string name;
    int phoneNumber;
    int loginState;
    std::vector<Contact> contacts;

public :
    User() {
        this->userId = userIdCounter;
        userIdCounter++;
        this->name = "";
        this->phoneNumber = 0;
        this->loginState = 0;  // Default login state
        this->contacts = std::vector<Contact>();
    }

    User(int id, const std::string& userName, int userPhoneNumber)
        : name(userName), phoneNumber(userPhoneNumber) {
            this->userId = userIdCounter;
            userIdCounter++;
            this->loginState = 0;  // Default login state
            this->contacts = std::vector<Contact>();
    }

    // Getters
    int getUserId() const { return userId; }
    std::string getName() const { return name; }
    int getPhoneNumber() const { return phoneNumber; }
    std::vector<Contact> getContacts() const { return contacts; }

    // Method User
    void addContact(std::string name, int phoneNumber);
    void printContacts() const;
};

#endif
