#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include "DataValidInput.cpp"
#include "Display.cpp"

using namespace std;
class Login{
private:
    Display display;
protected:
    // only this username and password correct 
    bool login(){
        const string correctUsername = "kruy";
        const string correctPassword = "2024";
        const int maxAttempts = 3;
        int attempts = 0;

        string username;
        string password;

        // check if the user input 3 times yet
        while (attempts < maxAttempts){
            cout << endl;
            display.LoginDisplay();
    
            cout << "Enter username: ";
            getline(cin, username);
            cout << "Enter password: ";
            getline(cin, password);
            cout << endl;

            if (username == correctUsername && password == correctPassword){
                cout << "You have login successfully.\n " << endl;

                return true;
            }else{
                attempts++;
                cout << "Invalid username or passeord. Attempt " << attempts << " of " << maxAttempts << ".\n";
            }
        }

        return false;
    }
};