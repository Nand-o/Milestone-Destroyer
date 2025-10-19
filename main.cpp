#include <iostream>
#include <string>
#include "user.h"
#include "handlers.h"

using namespace std;

enum MainMenuOptions
{
    LOGIN,
    REGISTER,
    EXIT
};

int main()
{
    vector<User> users; // Store registered users
    // User currentUser;

    // Create a new user
    User user1(1, "Alice", 123);

    // Add contacts to the user
    user1.addContact("Bob", 9876);
    user1.addContact("CarLi", 5555);
    user1.printContacts();

    users.push_back(user1);

    bool running = true;
    while (running)
    {
        cout << "Main Menu:" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";
        int choice;
        cin >> choice;

        MainMenuOptions option = static_cast<MainMenuOptions>(choice - 1);

        switch (option)
        {
        case LOGIN:
        {
            string name;
            int phone;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter phone number: ";
            cin >> phone;

            // Simple login validation
            bool found = false;
            for (auto &user : users)
            {
                if (user.getName() == name && user.getPhoneNumber() == phone)
                {
                    cout << "Login successful!" << endl;
                    // currentUser = user;
                    user.printContacts();
                    found = true;
                    showUserMenu(user); // Call the login handler
                    break;
                }
            }
            if (!found)
            {
                cout << "User not found. Please register." << endl;
            }
            break;
        }
        case REGISTER:
        {
            string name;
            int phone;
            cout << "Enter name for registration: ";
            cin >> name;
            cout << "Enter phone number for registration: ";
            cin >> phone;

            User newUser(users.size() + 1, name, phone);
            users.push_back(newUser);
            cout << "Registration successful!" << endl;
            break;
        }
        case EXIT:
            running = false;
            cout << "Exiting the program." << endl;
            break;
        }
    }
}
