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
    return 0;
}
