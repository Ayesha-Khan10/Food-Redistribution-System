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
    vector<T> data; 

public:
    void enqueue(const T& value);
    void dequeue();
    T front();
    bool isEmpty();
    size_t size();
    void display();
    void clear();
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
