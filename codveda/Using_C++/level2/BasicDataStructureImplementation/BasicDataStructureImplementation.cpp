#include<iostream>
using namespace std;

struct Node
{
    int value;
    struct Node* next;
    struct Node* prev;
};

Node* top = nullptr;

Node* createNode(int data)
{
    Node* newNode = new Node;
    if (newNode == nullptr)
        return nullptr;
    newNode->value = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void push(int data)
{
    Node* newNode = createNode(data);

    if (newNode == nullptr) return;

    if (top == nullptr)
    {
        top = newNode;
    }
    else
    {
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
    }
}

void pop()
{
    if (top == nullptr)
        return;
    Node* temp = top;
    top = top->prev;
    if (top != nullptr)
        top->next = nullptr;
    delete temp;
}

void printStack()
{
    Node* temp = top;
    while (temp != nullptr)
    {
        cout << temp->value << " <-> ";
        temp = temp->prev;
    }
    cout << "nullptr\n";
}

Node* tail = nullptr;
Node* head = nullptr;
void enqueue(int data)
{
    Node* newNode = createNode(data);
    if (newNode == nullptr)
        return;
    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
void dequeue()
{
    if (head == nullptr)
    {
        return;
    }
    if (head == tail)
    {
        head = tail = nullptr;
    }
    else
    {
        Node* temp = head;
        head->next->prev = nullptr;
        head = head->next;
        delete temp;
    }
}
void printQueue()
{
    Node* temp = head;
    while (temp != nullptr)
    {
        cout << temp->value << " <-> ";
        temp = temp->next;
    }
    cout << "nullptr\n";
}


int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    cout << "Using Stack\n";
    cout << "Original: ";
    printStack();

    pop();
    cout << "After one pop: ";
    printStack();

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    cout << "\nUsing Queue\n";
    cout << "Original: ";
    printQueue();

    dequeue();
    cout << "After one dequeue: ";
    printQueue();



    return 0;
}



