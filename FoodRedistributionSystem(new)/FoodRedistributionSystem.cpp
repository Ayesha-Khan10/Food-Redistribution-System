#include "redistribution.hpp"
#include <string>

using namespace std;

int main() {
    cout << "TESTING STACK" << endl;
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Stack contents: ";
    s.display();
    cout << "Top element: " << s.top() << endl;
    s.pop();
    cout << "After pop: ";
    s.display();
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    cout << endl;

    cout << "TESTING QUEUE" << endl;
    Queue<string> q;
    q.enqueue("Ali");
    q.enqueue("Shaheer");
    q.enqueue("Yariq");
    cout << "Queue contents: ";
    q.display();
    cout << "Front element: " << q.frontItem() << endl;
    q.dequeue();
    cout << "After dequeue: ";
    q.display();
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << endl;

    PriorityQueue<Request> requestPQ;
    Stack<Request> fulfilledRequests;

    int choice;

   do {
        cout << "\n--- REQUEST MANAGEMENT MENU ---\n";
        cout << "1. Add new request\n";
        cout << "2. View all requests\n";
        cout << "3. View fulfilled requests\n";
        cout << "4. Exit\n";
        cin >> choice;

        if (choice == 1) {
            string name, food, orgType, orgName, loc;
            int qty;
            cin.ignore(); 
            cout << "Enter recipient name: ";
            std::getline(std::cin, name);
            cout << "Enter food type: ";
            std::getline(std::cin, food);
            cout << "Enter quantity: ";
            cin >> qty;
            cin.ignore();
            cout << "Enter organization type (Hospital / OldAgeHome / Charity): ";
            std::getline(std::cin, orgType);
            cout << "Enter organization name: ";
            std::getline(std::cin, orgName);
            cout << "Enter location: ";
            std::getline(std::cin, loc);

            Request r(name, food, qty, orgType, orgName, loc);
            requestPQ.push(r);
            cout << "Request added successfully.\n";

        }
        else if (choice == 2) {
            cout << "\nAll Requests (Urgent First):\n";
            requestPQ.display();
        }
        else if (choice == 3) {
            cout << "\nFulfilled Requests:\n";
            if (fulfilledRequests.isEmpty()) {
                cout << "No fulfilled requests yet.\n";
            }
            else {
                fulfilledRequests.display();
            }
        }

   } while (choice != 3);


    cout << "TESTING PRIORITY QUEUE" << endl;
    PriorityQueue<int> pq;
    pq.push(5);
    pq.push(15);
    pq.push(10);
    cout << "Priority queue top: " << pq.top() << endl;
    pq.pop();
    cout << "After pop, new top: " << pq.top() << endl;
    cout << "Is priority queue empty? " << (pq.isEmpty() ? "Yes" : "No") << endl;
    cout << endl;

    cout << "TESTING GRAPH" << endl;
    Graph<string> g;
    g.addNode("Donor");
    g.addNode("FoodBank");
    g.addNode("Recipient");

    g.addEdge("Donor", "FoodBank", 10);
    g.addEdge("FoodBank", "Recipient", 15);

    cout << "\nGraph connections:\n";
    g.display();

    cout << endl << "ALL TESTS COMPLETE" << endl;

    DonorLinkedList donors;
    DonationLinkedList donations;

    int choice2;

    do {
        cout << "\n==== Food Donation System ====\n";
        cout << "1. Add Donor\n";
        cout << "2. Add Donation\n";
        cout << "3. Display All Donors\n";
        cout << "4. Display All Donations\n";
        cout << "5. Display Donations by Donor\n";
        cout << "6. Remove Donor\n";
        cout << "7. mark donation as completed\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice2;

        if (choice2 == 1) {
            int id;
            string name, contact, type, address;
            cout << "Enter Donor ID: "; cin >> id;
            cin.ignore(); // to ignore leftover newline
            cout << "Enter Donor Name: "; getline(cin, name);
            cout << "Enter Contact Info: "; getline(cin, contact);
            cout << "Enter Donor Type (Individual/Organization): "; getline(cin, type);
            cout << "Enter Address: "; getline(cin, address);

            Donor d(id, name, contact, type, address);
            donors.addDonor(d);
            cout << "Donor added successfully.\n";
        }
        else if (choice2 == 2) {
            int donationId, donorId, quantity;
            string foodType, expiry;
            cout << "Enter Donation ID: "; cin >> donationId;
            cout << "Enter Donor ID: "; cin >> donorId;

            // Check if donor exists
            if (!donors.searchDonor(donorId)) {
                cout << "Donor not found! Please add donor first.\n";
                continue;
            }

            cin.ignore();
            cout << "Enter Food Type: "; getline(cin, foodType);
            cout << "Enter Quantity: "; cin >> quantity;
            cin.ignore();
            cout << "Enter Expiry Date: "; getline(cin, expiry);

            FoodDonation f(donationId, donorId, foodType, quantity, expiry);
            donations.addDonation(f);
            cout << "Donation added successfully.\n";
        }
        else if (choice2 == 3) {
            cout << "\n--- All Donors ---\n";
            donors.displayDonors();
        }
        else if (choice2 == 4) {
            cout << "\n--- All Donations ---\n";
            donations.displayDonations();
        }
        else if (choice2 == 5) {
            int donorId;
            cout << "Enter Donor ID: "; cin >> donorId;
            cout << "\n--- Donations by Donor " << donorId << " ---\n";
            donations.displayDonationsByDonor(donorId);
        }
        else if (choice2 == 6) {
            int donorId;
            cout << "Enter Donor ID to remove: "; cin >> donorId;
            if (donors.removeDonor(donorId))
                cout << "Donor removed successfully.\n";
            else
                cout << "Donor not found!\n";
        }
        else if (choice2 == 7) {
            int donationId;
            cout << "Enter Donation ID to mark as completed: ";
            cin >> donationId;

            FoodDonation* donation = donations.searchDonation(donationId);
            if (donation) {
                donation->setStatus("Completed");
                cout << "Donation marked as completed successfully!\n";
            }
            else {
                cout << "Donation not found!\n";
            }
        }
        else if (choice2 == 8) {
            cout << "Exiting system...\n";
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice2 != 8);
    return 0;

}
