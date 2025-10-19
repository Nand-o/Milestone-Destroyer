#include <iostream>
#include <string>
#include "user.h"

using namespace std;

bool checkingValidationContact(const vector<Contact>& contacts, string query) {
    for (const auto& contact : contacts) {
        if (contact.name == query || to_string(contact.phoneNumber) == query) {
            return true; // Contact found
        }
    }
    return false; // Contact not found
}

void User::addContact(string name, int phoneNumber) {
    // Validasi

    if (checkingValidationContact(this->contacts, name) ||
        checkingValidationContact(this->contacts, to_string(phoneNumber))) {
        cout << "Contact with the same name or phone number already exists." << endl;
        return;
    }

    if (name.empty() || phoneNumber <= 0) {
        cout << "Invalid contact details." << endl;
        return;
    }

    this->contacts.push_back({name, phoneNumber});
    cout << "Contact added successfully: " << name << ", " << phoneNumber << endl;
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
