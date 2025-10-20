#include <iostream>
#include <string>
#include "user.h"
#include "handlers.h"
#include "serialization_utils.h"

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

    // // Create a new user
    // User user1(1, "Alice", 123);

    // // Add contacts to the user
    // user1.addContact("Bob", 9876);
    // user1.addContact("CarLi", 5555);
    // user1.printContacts();

    // users.push_back(user1);

    cout << "Loading users data..." << endl;
    loadData(users, "users_data.bin");
    cout << "Users data loaded successfully." << endl;

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
            getline(cin, name); // To handle spaces in name
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
                    showUserMenu(user); // Call the User Menu Handler
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
            getline(cin, name); // To handle spaces in name
            cout << "Enter phone number for registration: ";
            cin >> phone;

            User newUser(name, phone);
            users.push_back(newUser);
            cout << "Registration successful!" << endl;
            break;
        }
        case EXIT:
            saveData(users, "users_data.bin");
            running = false;
            cout << "Exiting the program." << endl;
            break;
        }
    }
}
