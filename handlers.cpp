#include <iostream>
#include <string>
#include "handlers.h"

using namespace std;

void showUserMenu(User &user)
{
    bool inMenu = true;
    while (inMenu)
    {
        cout << "User Menu for " << user.getName() << ":" << endl;
        cout << "1. View Contacts" << endl;
        cout << "2. Add Contact" << endl;
        cout << "3. Logout" << endl;
        cout << "Choose an option: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            user.printContacts();
            break;
        case 2:
        {
            string contactName;
            int contactPhone;
            cout << "Enter contact name: ";
            cin >> contactName;
            cout << "Enter contact phone number: ";
            cin >> contactPhone;
            user.addContact(contactName, contactPhone);
            cout << "Contact added!" << endl;
            break;
        }
        case 3:
            inMenu = false;
            cout << "Logging out..." << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }
}
