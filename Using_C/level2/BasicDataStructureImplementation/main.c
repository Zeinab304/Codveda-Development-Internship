#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
    struct node* prev;
} Node;
//stack
Node *top=NULL;

Node* createNode(int data);

void push(int data);
void pop();
void printStack();

//queue
Node *end=NULL;
Node *start=NULL;

void enqueue(int data);
void dequeue();
void printQueue();


int main()
{
    printf("\nStack\n");
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    printf("Original ");
    printStack();

    pop();
    printf("After one pop, ");
    printStack();

    printf("\nQueue\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    printf("Original ");
    printQueue();

    dequeue();
    printf("After one dequeue, ");
    printQueue();


    return 0;
}
Node* createNode(int data)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL)
        return;
    newNode->value=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}
//stack
void push(int data)
{
    Node* newNode = createNode(data);

    if (newNode == NULL) return;

    if (top == NULL)
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
    if(top==NULL)
        return NULL;
    Node* temp;
    temp=top;
    top=top->prev;
    if(top!=NULL)
        top->next=NULL;
    free(temp);
}

void printStack()
{
    Node* temp=top;
    while(temp!=NULL)
    {
        printf("%d <-> ",temp->value);
        temp=temp->prev;
    }
    printf("NULL\n");
}

//queue
void enqueue(int data)
{
    Node* newNode=createNode(data);
    if(newNode==NULL)
        return;
    if(start==NULL)
    {
        start=end=newNode;
    }
    else
    {
        end->next=newNode;
        newNode->prev=end;
        end=newNode;
    }
}
void dequeue()
{
    if(start==NULL)
    {
        return;
    }
    if(start==end)
    {
        start=end=NULL;
    }
    else
    {
        Node* temp=start;
        start->next->prev=NULL;
        start=start->next;
        free(temp);
    }
}
void printQueue()
{
    Node* temp=start;
    while(temp!=NULL)
    {
        printf("%d <-> ",temp->value);
        temp=temp->next;
    }
    printf("NULL\n");
}
