#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

// Structure to represent a bank account
struct BankAccount
{
    int accountNumber;                    // Account number
    string customerName, customerAddress; // Account holder's name and address
    char accountType;                     // Account type (savings or current)
    float balance;                        // Account balance

    // Constructor to initialize account attributes
    BankAccount()
    {
        accountNumber = 0;
        customerName = "";
        customerAddress = "";
        accountType = '\0';
        balance = 0.0;
    }

    // Function declarations for various operations on bank accounts
    void createAccount();         // Create a new bank account
    void addFunds();              // Deposit money into an account
    void withdrawFunds();         // Withdraw money from an account
    void displayAccountDetails() const; // Display account details
    void updateAccount();         // Modify account information
    void removeAccount();         // Delete an account
};

// Function to create a new account
// Function to create a new account
void BankAccount::createAccount()
{
    cout << "Enter your account number: ";
    cin >> accountNumber;

    cout << "Enter your full name: ";
    cin.ignore(); // To ignore the newline character left in the input buffer
    getline(cin, customerName);

    cout << "Enter your address: ";
    getline(cin, customerAddress);

    cout << "Choose account type: Savings (s) or Current (c): ";
    cin >> accountType;

    cout << "Enter initial deposit amount: ";
    cin >> balance; // Ensure that the deposit amount is read before proceeding

    cout << "Account created successfully!\n";
}


// Function to deposit money into an account
void BankAccount::addFunds()
{
    float depositAmount;
    cout << "\nEnter deposit amount: ";
    cin >> depositAmount;
    balance += depositAmount;
    cout << "Deposit successful. Updated balance: " << balance << endl;
}

// Function to withdraw money from an account
void BankAccount::withdrawFunds()
{
    float withdrawalAmount;
    cout << "\nEnter withdrawal amount: ";
    cin >> withdrawalAmount;
    if (withdrawalAmount <= balance)
    {
        balance -= withdrawalAmount;
        cout << "Withdrawal successful.\n";
    }
    else
    {
        cout << "Insufficient funds.\n";
    }
    cout << "Remaining balance: " << balance << endl;
}

// Function to display account details
void BankAccount::displayAccountDetails() const
{
    cout << "\nAccount Holder Name: " << customerName;
    cout << "\nAddress: " << customerAddress;
    cout << "\nAccount Type: " << accountType;
    cout << "\nBalance: " << balance << endl;
}

// Function to modify account information
void BankAccount::updateAccount()
{
    cout << "\nCurrent Account Holder Name: " << customerName;
    cout << "\nCurrent Address: " << customerAddress;
    cout << "\nCurrent Account Type: " << accountType;

    cout << "\n\nEnter new account holder's name: ";
    cin.ignore();
    getline(cin, customerName);

    cout << "Enter new address: ";
    getline(cin, customerAddress);

    cout << "Choose new account type: Savings (s) or Current (c): ";
    cin >> accountType;

    cout << "\nAccount details updated successfully!\n";
}

// Function to delete an account
void BankAccount::removeAccount()
{
    cout << "\nAccount number " << accountNumber << " is being deleted.";
    accountNumber = 0;
    customerName = "";
    customerAddress = "";
    accountType = '\0';
    balance = 0.0;
    cout << "\nAccount deleted successfully!\n";
}

// Main function
int main()
{
    vector<BankAccount> accounts; // Vector to store bank accounts

    int choice, enteredAccountNumber;
    bool accountExists;
    string userType;

    cout << "Enter user type (admin/user): ";
    cin >> userType;

    while (1)
    {
        system("CLS"); // Clear the screen
        cout << "==============================\n";
        cout << "|       Banking Menu         |\n";
        cout << "==============================\n";
        
        if (userType == "admin")
        {
            cout << " 5. Edit account details\n 6. Delete an account\n 7. Show all accounts\n 8. Exit\n";
        }
        else
        {
            cout << " 1. Open a new account\n 2. Deposit funds\n 3. Withdraw funds\n 4. View account details\n 8. Exit\n";
        }
        
        cout << "==============================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Create a new account
        {
            if (userType != "admin")
            {
                BankAccount newAccount;
                newAccount.createAccount();
                accounts.push_back(newAccount);
            }
            else
            {
                cout << "Invalid option for admin.\n";
            }
            break;
        }
        case 2: // Deposit money into an account
        {
            if (userType != "admin")
            {
                accountExists = false;
                cout << "Enter account number: ";
                cin >> enteredAccountNumber;

                for (auto &account : accounts)
                {
                    if (account.accountNumber == enteredAccountNumber)
                    {
                        account.addFunds();
                        accountExists = true;
                        break;
                    }
                }

                if (!accountExists)
                    cout << "No account found with the entered number.\n";
            }
            else
            {
                cout << "Invalid option for admin.\n";
            }
            break;
        }
        case 3: // Withdraw money from an account
        {
            if (userType != "admin")
            {
                accountExists = false;
                cout << "Enter account number: ";
                cin >> enteredAccountNumber;

                for (auto &account : accounts)
                {
                    if (account.accountNumber == enteredAccountNumber)
                    {
                        account.withdrawFunds();
                        accountExists = true;
                        break;
                    }
                }

                if (!accountExists)
                    cout << "No account found with the entered number.\n";
            }
            else
            {
                cout << "Invalid option for admin.\n";
            }
            break;
        }
        case 4: // View account details
        {
            if (userType != "admin")
            {
                accountExists = false;
                cout << "Enter account number: ";
                cin >> enteredAccountNumber;

                for (auto &account : accounts)
                {
                    if (account.accountNumber == enteredAccountNumber)
                    {
                        account.displayAccountDetails();
                        accountExists = true;
                        break;
                    }
                }

                if (!accountExists)
                    cout << "No account found with the entered number.\n";
            }
            else
            {
                cout << "Invalid option for admin.\n";
            }
            break;
        }
        case 5: // Edit account details
        {
            if (userType == "admin")
            {
                accountExists = false;
                cout << "Enter account number: ";
                cin >> enteredAccountNumber;

                for (auto &account : accounts)
                {
                    if (account.accountNumber == enteredAccountNumber)
                    {
                        account.updateAccount();
                        accountExists = true;
                        break;
                    }
                }

                if (!accountExists)
                    cout << "No account found with the entered number.\n";
            }
            else
            {
                cout << "Invalid option for user.\n";
            }
            break;
        }
        case 6: // Delete an account
        {
            if (userType == "admin")
            {
                accountExists = false;
                cout << "Enter account number: ";
                cin >> enteredAccountNumber;

                for (auto it = accounts.begin(); it != accounts.end(); ++it)
                {
                    if (it->accountNumber == enteredAccountNumber)
                    {
                        it->removeAccount();
                        accounts.erase(it);
                        accountExists = true;
                        break;
                    }
                }

                if (!accountExists)
                    cout << "No account found with the entered number.\n";
            }
            else
            {
                cout << "Invalid option for user.\n";
            }
            break;
        }
        case 7: // Show all accounts
        {
            if (userType == "admin")
            {
                if (accounts.empty())
                {
                    cout << "No accounts found.\n";
                }
                else
                {
                    for (const auto &account : accounts)
                    {
                        account.displayAccountDetails();
                        cout << "-------------------------\n";
                    }
                }
            }
            else
            {
                cout << "Invalid option for user.\n";
            }
            break;
        }
        case 8: // Exit
        {
            exit(0);
        }
        default:
            cout << "Invalid choice. Please try again.\n";
        }

        getch(); // Pause the screen
    }

    return 0;
}
