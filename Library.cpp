#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include "BookMenuApplication.cpp"
#include "MemberMenuApplication.cpp"
#include "DataValidInput.cpp"
#include "Login.cpp"

using namespace std;
class Library : public Login{
private: 
    Display display;
public:
    void run()
    {
        // check if wrong usename and password 3 times, then exiting
        if (!login())
        {
            cout << "Maximum login attempts reached. Exiting...\n";
            return;
        }

        int choice;
        cout.setf(ios::fixed | ios::showpoint);
        cout << setprecision(2);

        do
        {
            display.displayMainMenu();
            cout << endl;
            choice = DataValidInput::getIntInput("Enter your choice(0-2): ");
            cout << endl;
            
            enum {
                EXIT, BOOK, MEMBER
            };
            switch (choice)
            {
            case BOOK:
                    BookMenuApplication bookApp;
                    bookApp.run();
                break;

            case MEMBER:
                    MemberMenuApplication memberApp;
                    memberApp.run();
                break;

            case EXIT:
                    cout << "Thanks for using my program.\n";
                break;

            default:
                    cout << "\aInvalid choice. Please try again.\n";
            }
        } while (choice != 0);
    }
};