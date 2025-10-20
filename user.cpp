#include <iostream>
#include <string>
#include "user.h"

using namespace std;

int User::userIdCounter = 100;

User::User() {
    this->userId = userIdCounter++;
    this->name = "";
    this->phoneNumber = 0;
    this->loginState = 0;
    this->contacts = vector<Contact>();
    this->contactIdCounter = 1;
}

User::User(const string& username, int userPhoneNumber) {
    this->userId = userIdCounter++;
    this->name = username;
    this->phoneNumber = userPhoneNumber;
    this->loginState = 0;  // Default login state
    this->contacts = vector<Contact>();
    this->contactIdCounter = 1;
}


bool checkingValidationContact(const vector<Contact>& contacts, string query) {
    for (const auto& contact : contacts) {
        if (contact.name == query || to_string(contact.phoneNumber) == query) {
            return true; // Contact found
        }
    }
    return false; // Contact not found
}

bool User::addContact(string name, int phoneNumber) {
    // Validasi

    Contact newContact(this->userId, name, phoneNumber);

    if (checkingValidationContact(this->contacts, name) ||
        checkingValidationContact(this->contacts, to_string(phoneNumber))) {
        cout << "Contact with the same name or phone number already exists." << endl;
        return false;
    }

    if (name.empty() || phoneNumber <= 0) {
        cout << "Invalid contact details." << endl;
        return false;
    }

    newContact.contactId = this->contactIdCounter++;

    this->contacts.push_back(newContact);
    cout << "Contact added successfully: " << name << ", " << phoneNumber << endl;
    return true;
}

void User::printContacts() const {
    cout << "Contact List for User: " << this->name << endl;
    if (this->contacts.empty()) {
        cout << "No contacts found." << endl;
        return;
    }
    for (const auto& contact : this->contacts) {
        cout << "ID: " << contact.contactId
            << ", Name: " << contact.name
            << ", Phone Number: " << contact.phoneNumber << endl;
    }
}
