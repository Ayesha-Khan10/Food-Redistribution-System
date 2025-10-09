#include "redistribution.hpp"
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
    cout << "Front element: " << q.front() << endl;
    q.dequeue();
    cout << "After dequeue: ";
    q.display();
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << endl;

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
