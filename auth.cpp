#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Define a struct to represent a user account
struct Account {
    string username;
    string password;
    bool isAuthorized;
};

// Function to check if a given username and password match an account in the system
bool authorizeAccount(string username, string password, Account accounts[], int numAccounts) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].username == username && accounts[i].password == password) {
            accounts[i].isAuthorized = true;
            return true;
        }
    }
    return false;
}

// Function to read in account information from a file
void loadAccounts(Account accounts[], int& numAccounts) {
    ifstream inFile("accounts.txt");
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            string username, password;
            inFile >> username >> password;
            accounts[numAccounts] = { username, password, false };
            numAccounts++;
        }
        inFile.close();
    }
}

// Function to save account information to a file
void saveAccounts(Account accounts[], int numAccounts) {
    ofstream outFile("accounts.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < numAccounts; i++) {
            outFile << accounts[i].username << " " << accounts[i].password << endl;
        }
        outFile.close();
    }
}

int main() {
    Account accounts[100];
    int numAccounts = 0;

    // Load account information from file
    loadAccounts(accounts, numAccounts);

    // Prompt user for username and password
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    // Check if username and password are authorized
    if (authorizeAccount(username, password, accounts, numAccounts)) {
        cout << "You have been authorized." << endl;
    } else {
        cout << "Incorrect username or password." << endl;
    }

    // Save account information back to file
    saveAccounts(accounts, numAccounts);

    return 0;
}
