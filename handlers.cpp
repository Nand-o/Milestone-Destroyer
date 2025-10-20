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
            bool isFound = false;
            while (!isFound)
            {
                string contactName;
                int contactPhone;
                cout << "Enter contact name: ";
                cin >> contactName;
                cout << "Enter contact phone number: ";
                cin >> contactPhone;

                if(user.addContact(contactName, contactPhone)) {
                    isFound = true;
                    cout << "Contact added!" << endl;
                    break;
                } else {
                    cout << "Failed to add contact. Please try again." << endl;
                    cout << "------------------------" << endl;
                    // Loop again for valid input
                    cout << "Do you want to try again? (1 for Yes / 0 for No): ";
                    int retryChoice;
                    cin >> retryChoice;
                    if (retryChoice == 0) {
                        isFound = true;  // Exit the loop
                    }
                }
            }
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
