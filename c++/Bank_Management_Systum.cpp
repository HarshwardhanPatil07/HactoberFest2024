// Name - Naman bagdiya
// Github - github.com/NamanOG
// Aim - FullStack Developer
// Date - 11-10-2023

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <limits>
#include <cstring>
#include <iomanip>

using namespace std;

// Structure to represent a transaction
struct Transaction {
    string type;
    int amount;
    string timestamp;
};

class Bank {
private:
    string client_id;
    string client_name;
    string client_city;
    double client_balance = 0.0;
    double client_donation = 0.0;

    static double total_donation;

    vector<Transaction> transactionHistory;

public:
    // Member function to set client details
    void setDetails() {
        cout << "\nClient Id: ";
        cin >> client_id;

        cout << "Client Name: ";
        cin.ignore();
        getline(cin, client_name);

        cout << "Client City: ";
        getline(cin, client_city);
    }

    // Member function for debit operation
    void debit(double amt) {
        client_balance -= amt;
        recordTransaction("Debit", amt);
    }

    // Member function for credit operation
    void credit(double amt) {
        client_balance += amt;
        recordTransaction("Credit", amt);
    }

    // Member function for donation operation
    void donate(double amt) {
        client_donation += amt;
        total_donation += amt;
        client_balance -= amt;
        recordTransaction("Donation", amt);
    }

    // Getter functions
    double getTotalDonation() const { return total_donation; }
    string getname() const { return client_name; }
    string getid() const { return client_id; }
    string getcity() const { return client_city; }
    double getbalance() const { return client_balance; }
    double getdonation() const { return client_donation; }
    static double gettotaldonation() { return total_donation; }

    // Member function to display transaction history
    void displayTransactionHistory() const {
        cout << "\nTransaction History for " << client_name << " (ID: " << client_id << ")\n";
        cout << "---------------------------------------\n";
        cout << "Type\tAmount\tTimestamp\n";
        for (const Transaction &transaction : transactionHistory) {
            cout << transaction.type << "\t" << transaction.amount << "\t" << transaction.timestamp << endl;
        }
    }

private:
    // Member function to record a transaction
    void recordTransaction(const string &type, double amount) {
        time_t now = time(0);
        char *timestamp = ctime(&now);
        timestamp[strlen(timestamp) - 1] = '\0';
        Transaction transaction;
        transaction.type = type;
        transaction.amount = amount;
        transaction.timestamp = timestamp;
        transactionHistory.push_back(transaction);
    }
};

double Bank::total_donation = 0.0;

int main() {
    vector<Bank> clients;

    int ch = 1;
    cout << "\n\n----------------| Welcome to Naman's Bank of India |----------------\n";
    int selectedClient = -1;
    int selectedClientInfo = -1;
    string city;

    do {
        cout << "\nPress 0. Exit\n";
        cout << "Press 1. Select Client\n";
        cout << "Press 2. View Max Donation\n";
        cout << "Press 3. Search By City\n";
        cout << "Press 4. Total Donation\n";
        cout << "Press 5. Display Info\n";
        cout << "Press 6. Create New Account\n";
        cout << "Press 7. Add Funds to Account\n";
        cout << "Press 8. Make a Donation\n";
        cout << "--> ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "\nSelect Client (1 to " << clients.size() << "): ";
            cin >> selectedClient;
            if (selectedClient >= 1 && static_cast<size_t>(selectedClient) <= clients.size()) {
                cout << "\nSelected client: " << clients[selectedClient - 1].getname() << " (ID: "
                     << clients[selectedClient - 1].getid() << ")\n";

                int clientOption = -1;
                while (clientOption != 2) {
                    cout << "Press 1 to Make a Donation\n";
                    cout << "Press 2 to Add Funds to Account\n";
                    cout << "Press 3 to Go Back\n";
                    cout << "--> ";
                    cin >> clientOption;

                    switch (clientOption) {
                    case 1:
                        double donationAmount;
                        cout << "\nEnter donation amount: ";
                        cin >> donationAmount;

                        if (donationAmount > 0) {
                            if (donationAmount <= clients[selectedClient - 1].getbalance()) {
                                clients[selectedClient - 1].donate(donationAmount);
                                cout << "Donation of Rs. " << donationAmount << " /- has been successfully made by " << clients[selectedClient - 1].getname() << "\nThanks for the Donation !" << endl;
                            } else {
                                cout << "Insufficient balance. Cannot make the donation.\n";
                            }
                        } else {
                            cout << "Invalid donation amount. Donation amount must be greater than 0.\n";
                        }
                        break;

                    case 2:
                        double creditAmount;
                        cout << "\nEnter the amount to add to the balance: ";
                        cin >> creditAmount;

                        if (creditAmount > 0) {
                            clients[selectedClient - 1].credit(creditAmount);
                            cout << "\nRs. " << creditAmount << " /- has been successfully added to the balance of " << clients[selectedClient - 1].getname() << endl;
                        } else {
                            cout << "Invalid credit amount. Amount must be greater than 0.\n";
                        }
                        break;

                    case 3:
                        // Go back to the main menu.
                        break;

                    default:
                        cout << "Invalid option. Please select 1 to make a donation, 2 to add funds, or 3 to go back.\n";
                    }
                }
            } else {
                cout << "\nInvalid client selection\n";
            }
            break;

        case 2:
            // Implement logic to find the client with the maximum donation and display their info.
            {
                Bank *clientWithMaxDonation = nullptr;
                double maxDonation = -1.0;
                for (Bank &client : clients) {
                    if (client.getdonation() > maxDonation) {
                        maxDonation = client.getdonation();
                        clientWithMaxDonation = &client;
                    }
                }
                if (clientWithMaxDonation) {
                    cout << "\nClient with Max Donation: " << clientWithMaxDonation->getname() << " (ID: "
                         << clientWithMaxDonation->getid() << ")\n";
                } else {
                    cout << "No clients with donations found.\n";
                }
            }
            break;

        case 3:
            // Implement logic to find the client with the maximum donation and display their info.
            {
                Bank *clientWithMaxDonation = nullptr;
                double maxDonation = -1.0;
                for (Bank &client : clients) {
                    if (client.getdonation() > maxDonation) {
                        maxDonation = client.getdonation();
                        clientWithMaxDonation = &client;
                    }
                }
                if (clientWithMaxDonation) {
                    cout << "\nClient with Max Donation: " << clientWithMaxDonation->getname() << " (ID: "
                         << clientWithMaxDonation->getid() << ")\n";
                } else {
                    cout << "No clients with donations found.\n";
                }
            }
            break;

        case 4:
            cout << "\nTotal Donations: " << Bank::gettotaldonation() << endl;
            break;

        case 5:
            cout << "\nSelect Client Info (1 to " << clients.size() << "): ";
            cin >> selectedClientInfo;
            if (selectedClientInfo >= 1 && static_cast<size_t>(selectedClientInfo) <= clients.size()) {
                clients[selectedClientInfo - 1].displayTransactionHistory();
            } else {
                cout << "\nInvalid client selection\n";
            }
            break;

        case 6:
            // Create a new account
            if (clients.size() < 10) {
                cout << "\nCreate a New Account\n";
                Bank newClient;
                newClient.setDetails();
                clients.push_back(newClient);
            } else {
                cout << "\nAccount limit reached. Cannot create more accounts." << endl;
            }
            break;

        case 7:
            // Adds Funds in the client's Account
            if (selectedClient != -1) {
                double creditAmount;
                cout << "\nEnter the amount to add to the balance: ";
                cin >> creditAmount;

                if (creditAmount > 0) {
                    clients[selectedClient - 1].credit(creditAmount);
                    cout << fixed << "\nRs. " << setprecision(2) << creditAmount << " /- has been successfully added to the balance of " << clients[selectedClient - 1].getname() << endl;
                } else {
                    cout << "Invalid credit amount. Amount must be greater than 0.\n";
                }
            } else {
                cout << "Please select a client before adding funds.\n";
            }
            break;

        case 8:
            // Adds Donations
            if (selectedClient != -1) {
                double donationAmount;
                cout << "Enter donation amount: ";
                cin >> donationAmount;

                if (donationAmount > 0) {
                    if (donationAmount <= clients[selectedClient - 1].getbalance()) {
                        clients[selectedClient - 1].donate(donationAmount);
                        cout << "Donation of Rs. " << donationAmount << " has been successfully made by " << clients[selectedClient - 1].getname() << endl;
                    } else {
                        cout << "Insufficient balance. Cannot make the donation.\n";
                    }
                } else {
                    cout << "Invalid donation amount. Donation amount must be greater than 0.\n";
                }
            } else {
                cout << "Please select a client before making a donation.\n";
            }
            break;

        default:
            cout << "\nThank you for using Naman's Bank of India\n";
            cout << "Do visit us Again !\n\n";
        }
    } while (ch != 0);

    system("pause");
    return 0;
}
