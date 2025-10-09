#include "redistribution.hpp"
#include <stdexcept>

using namespace std;

//Stack
template <typename T>
void Stack<T>::push(const T& value) { data.push_back(value); }

template <typename T>
void Stack<T>::pop() {
    if (data.empty()) throw out_of_range("Stack is empty");
    data.pop_back();
}

template <typename T>
T Stack<T>::top() {
    if (data.empty()) throw out_of_range("Stack is empty");
    return data.back();
}

template <typename T>
bool Stack<T>::isEmpty() { return data.empty(); }

template <typename T>
size_t Stack<T>::size() { return data.size(); }

template <typename T>
void Stack<T>::display() {
    for (const auto& item : data) cout << item << " ";
    cout << endl;
}

template <typename T>
void Stack<T>::clear() { data.clear(); }


//Queue
template <typename T>
void Queue<T>::enqueue(const T& value) { data.push_back(value); }

template <typename T>
void Queue<T>::dequeue() {
    if (data.empty()) throw out_of_range("Queue is empty");
    data.erase(data.begin()); // remove from front
}

template <typename T>
T Queue<T>::front() {
    if (data.empty()) throw out_of_range("Queue is empty");
    return data.front();
}

template <typename T>
bool Queue<T>::isEmpty() { return data.empty(); }

template <typename T>
size_t Queue<T>::size() { return data.size(); }

template <typename T>
void Queue<T>::display() {
    for (const auto& item : data) cout << item << " ";
    cout << endl;
}

template <typename T>
void Queue<T>::clear() { data.clear(); }


//PriorityQueue
template <typename T>
void PriorityQueue<T>::push(const T& value) { pq.push(value); }

template <typename T>
void PriorityQueue<T>::pop() {
    if (pq.empty()) throw out_of_range("Priority queue is empty");
    pq.pop();
}

template <typename T>
T PriorityQueue<T>::top() {
    if (pq.empty()) throw out_of_range("Priority queue is empty");
    return pq.top();
}

template <typename T>
bool PriorityQueue<T>::isEmpty() { return pq.empty(); }

template <typename T>
size_t PriorityQueue<T>::size() { return pq.size(); }


//Graph
template <typename T>
void Graph<T>::addEdge(T u, T v, int w) {
    adj[u].push_back({ v, w });
    adj[v].push_back({ u, w });
}
template <typename T>
void Graph<T>::addNode(T node) {
    // Only add the node if it doesn't already exist
    if (adj.find(node) == adj.end()) {
        adj[node] = {}; // create empty adjacency list
        cout << "Node added: " << node << endl;
    }
    else {
        cout << "Node already exists: " << node << endl;
    }
}
template <typename T>
void Graph<T>::display() {
    for (auto& node : adj) {
        cout << node.first << " -> ";
        for (auto& edge : node.second)
            cout << "(" << edge.first << ", " << edge.second << ") ";
        cout << endl;
    }
}
