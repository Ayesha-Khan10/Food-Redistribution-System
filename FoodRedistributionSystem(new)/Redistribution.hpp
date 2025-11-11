#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>


using namespace std;

//Stack Template
template <typename T>
class Stack {
private:
    vector<T> data;

public:
    void push(const T& value);
    void pop();
    T top();
    bool isEmpty();
    size_t size();
    void display();
    void clear();
};

//Queue Template
template <typename T>
class Queue {
private:
    T arr[100];     
    int front, rear;

public:
    Queue();     
    void enqueue(const T& value);
    void dequeue();
    T frontItem();
    bool isEmpty();
    size_t size();
    void display();
    void clear();
};
//Request Class
class Request {
public:
    string recipientName;
    string foodType;
    int quantity;
    bool isUrgent;
    bool isFulfilled;
    string organizationType;  
    string organizationName;  
    string location;          
    int priorityLevel;        


    Request(); // default constructor
    Request(string name, string food, int qty, string orgType, string orgName, string loc);
    bool operator<(const Request& other) const; // for priority queue
};


//Priority Queue
template <typename T>
class PriorityQueue {
private:
    priority_queue<T> pq;

public:
    void push(const T& value);
    void pop();
    T top();
    bool isEmpty();
    size_t size();
    void display();
};

//Graph 
template <typename T>
class Graph {
private:
    unordered_map<T, vector<pair<T, int>>> adj; // node -> [(neighbor, weight)]

public:
	void addNode(T node);
    void addEdge(T u, T v, int w);
    void display();
};

//Include so compiler can see it at compile time (code above this, dont code after it)
#include "redistribution.cpp"
