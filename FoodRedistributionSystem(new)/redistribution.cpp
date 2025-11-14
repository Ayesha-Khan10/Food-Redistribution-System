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
Queue<T>::Queue() {
    front = 0;
    rear = 0;
}

template <typename T>
void Queue<T>::enqueue(const T& value) {
    if (rear < 100) {
        arr[rear++] = value;
    }
    else {
        cout << "Queue is full.\n";
    }
}

template <typename T>
void Queue<T>::dequeue() {
    if (!isEmpty()) {
        front++;
    }
    else {
        cout << "Queue is empty.\n";
    }
}

template <typename T>
T Queue<T>::frontItem() {
    if (!isEmpty()) {
        return arr[front];
    }
    else {
        throw out_of_range("Queue is empty");
    }
}

template <typename T>
bool Queue<T>::isEmpty() {
    return front == rear;
}

template <typename T>
size_t Queue<T>::size() {
    return rear - front;
}

template <typename T>
void Queue<T>::display() {
    for (int i = front; i < rear; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void Queue<T>::clear() {
    front = 0;
    rear = 0;
}

Request::Request() {
    recipientName = "";
    foodType = "";
    quantity = 0;
    organizationType = "";
    organizationName = "";
    location = "";
    priorityLevel = 3;
    isFulfilled = false;
}

Request::Request(string name, string food, int qty, string orgType, string orgName, string loc) {
    recipientName = name;
    foodType = food;
    quantity = qty;
    organizationType = orgType;
    organizationName = orgName;
    location = loc;
    isFulfilled = false;

    if (orgType == "Hospital") priorityLevel = 1;
    else if (orgType == "OldAgeHome") priorityLevel = 2;
    else priorityLevel = 3;
}

bool Request::operator<(const Request& other) const {
    return priorityLevel > other.priorityLevel;
}

template <>
void Queue<Request>::display() {
    for (int i = front; i < rear; i++) {
        cout << i << ". " << arr[i].recipientName << " wants "
            << arr[i].quantity << " of " << arr[i].foodType
            << (arr[i].isUrgent ? " [URGENT]" : "")
            << (arr[i].isFulfilled ? " [FULFILLED]" : " [PENDING]")
            << endl;
    }
}


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
bool PriorityQueue<T>::isEmpty() { 
    return pq.empty(); 
}

template <typename T>
size_t PriorityQueue<T>::size() { return pq.size(); }

template <>
void PriorityQueue<Request>::display() {
    if (pq.empty()) {
        cout << "No requests available.\n";
        return;
    }

    priority_queue<Request> temp = pq;
    int i = 0;
    while (!temp.empty()) {
        Request r = temp.top();
        cout << i++ << ". " << r.recipientName << " from " << r.organizationName
            << " (" << r.organizationType << ", " << r.location << ") wants "
            << r.quantity << " of " << r.foodType
            << " [Priority: " << r.priorityLevel << "] "
            << (r.isFulfilled ? "[FULFILLED]" : "[PENDING]") << endl;
        temp.pop();
    }
}
//display fullfiled stack 
template <>
void Stack<Request>::display() {
    for (const auto& r : data) {
        cout << r.recipientName << " from " << r.organizationName
            << " (" << r.organizationType << ", " << r.location << ") received "
            << r.quantity << " of " << r.foodType
            << " [Priority: " << r.priorityLevel << "]\n";
    }
}


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


// ---------------- Donor Implementation ----------------
Donor::Donor(int id, string name, string contact, string type, string addr)
{
    donorId = id;
    donorName = name;
    contactInfo = contact;
    donorType = type;
    address = addr;
}

int Donor::getDonorId() const
{
    return donorId;
}

string Donor::getDonorName() const
{
    return donorName;
}

string Donor::getContactInfo() const
{
    return contactInfo;
}

string Donor::getDonorType() const
{
    return donorType;
}

string Donor::getAddress() const
{
    return address;
}

void Donor::displayDonor() const
{
    cout << "Donor ID: " << donorId
        << ", Name: " << donorName
        << ", Type: " << donorType
        << ", Contact: " << contactInfo
        << ", Address: " << address
        << endl;
}

// ---------------- DonorNode ----------------
DonorNode::DonorNode(Donor d)
{
    data = d;
    next = nullptr;
}

// ---------------- DonorLinkedList ----------------
DonorLinkedList::DonorLinkedList()
{
    head = nullptr;
}

void DonorLinkedList::addDonor(Donor d)
{
    DonorNode* newNode = new DonorNode(d);

    if (!head)
    {
        head = newNode;
        return;
    }

    DonorNode* temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

Donor* DonorLinkedList::searchDonor(int id)
{
    DonorNode* temp = head;
    while (temp)
    {
        if (temp->data.getDonorId() == id)
            return &(temp->data);

        temp = temp->next;
    }
    return nullptr;
}

bool DonorLinkedList::removeDonor(int id)
{
    if (!head)
        return false;
    if (head->data.getDonorId() == id)
    {
        DonorNode* toDelete = head;
        head = head->next;
        delete toDelete;
        return true;
    }
    DonorNode* temp = head;
    while (temp->next && temp->next->data.getDonorId() != id)
    {
        temp = temp->next;
    }
    if (!temp->next)
        return false;

    DonorNode* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    return true;
}

void DonorLinkedList::displayDonors() const
{
    if (head == nullptr) {
        cout << "\nNo donors to display." << endl;
    }
    DonorNode* temp = head;
    while (temp)
    {
        temp->data.displayDonor();
        temp = temp->next;
    }
}

// ---------------- FoodDonation ----------------
FoodDonation::FoodDonation(int dId, int drId, string type, int qty, string date, string stat)
{
    donationId = dId;
    donorId = drId;
    foodType = type;
    quantity = qty;
    expiryDate = date;
    status = stat;
}

int FoodDonation::getDonationId() const
{
    return donationId;
}
int FoodDonation::getDonorId() const
{
    return donorId;
}
string FoodDonation::getFoodType() const
{
    return foodType;
}
int FoodDonation::getQuantity() const
{
    return quantity;
}
string FoodDonation::getExpiryDate() const
{
    return expiryDate;
}
string FoodDonation::getStatus() const
{
    return status;
}
void FoodDonation::setStatus(string newStatus)
{
    status = newStatus;
}

void FoodDonation::displayDonation() const
{
    cout << "Donation ID: " << donationId
        << ", Donor ID: " << donorId
        << ", Food: " << foodType
        << ", Quantity: " << quantity
        << ", Expiry: " << expiryDate
        << ", Status: " << status
        << endl;
}

// ---------------- DonationNode ----------------
DonationNode::DonationNode(FoodDonation d)
{
    data = d;
    next = nullptr;
}
// ---------------- DonationLinkedList ----------------
DonationLinkedList::DonationLinkedList()
{
    head = nullptr;
}

void DonationLinkedList::addDonation(FoodDonation d)
{
    DonationNode* newNode = new DonationNode(d);
    if (!head)
    {
        head = newNode;
        return;
    }
    DonationNode* temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

FoodDonation* DonationLinkedList::searchDonation(int donationId)
{
    DonationNode* temp = head;
    while (temp)
    {
        if (temp->data.getDonationId() == donationId)
            return &(temp->data);
        temp = temp->next;
    }
    return nullptr;
}

bool DonationLinkedList::removeDonation(int donationId)
{
    if (!head)
        return false;
    if (head->data.getDonationId() == donationId)
    {
        DonationNode* toDelete = head;
        head = head->next;
        delete toDelete;
        return true;
    }
    DonationNode* temp = head;
    while (temp->next && temp->next->data.getDonationId() != donationId)
    {
        temp = temp->next;
    }
    if (!temp->next)
        return false;

    DonationNode* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    return true;
}

void DonationLinkedList::displayDonations() const
{
    if (head == nullptr) {
        cout << "\nNo donations to display." << endl;
    }
    DonationNode* temp = head;
    while (temp)
    {
        temp->data.displayDonation();
        temp = temp->next;
    }
}

void DonationLinkedList::displayDonationsByDonor(int donorId) const
{
    DonationNode* temp = head;
    bool found = false;
    while (temp)
    {
        if (temp->data.getDonorId() == donorId)
        {
            temp->data.displayDonation();
            found = true;
        }
        temp = temp->next;
    }
    if (!found)
        cout << "No donations found for donor ID: " << donorId << endl;
}