#include<bits/stdc++.h>

using namespace std;


class Node
{
public:
    int data;
    Node *next;
};

// Passing list address and the new value
void push(Node** head, int value)
{
    Node *node = new Node();

    node->data = value;
    node->next = *head;

    *head = node;
}

// Passing list address, which next to insert and the new value
bool insertAfter(Node** head, int At, int value)
{
    Node* tempNode = *head;
    // Creating new node
    Node* newNode = new Node();
    newNode->data = value;

    while(tempNode->data != At)
    {
        if(tempNode->next == NULL)
            return false;
        else
        {
            tempNode = tempNode->next;
        }
    }

    newNode->next = tempNode->next;
    tempNode->next = newNode;

    *head = tempNode;

    return true;

}

// Passing list address and the new value
void append(Node** head, int value)
{
    Node *node = new Node();
    Node *lastNode = *head;

    // Inserting data into a new node
    node->data = value;
    node->next = NULL;

    // If the list is already empty
    if(*head == NULL)
    {
        // Linking new node into head
        *head = node;
    }
    else
    {
        // Finding the last node
        while(lastNode->next != NULL)
            lastNode = lastNode->next;

        // Linking new node with last node
        lastNode->next = node;
    }
}

// Passing list and a value to delete
bool deleteItem(Node** head, int value)
{
    // Initializing tempNode
    Node* tempNode = *head;
    Node* newNodeList = new Node();

    // Searching value
    while(tempNode->data != value)
    {
        // If item isn't found yet return false
        if(tempNode->next == NULL)
            return false;
        else
        {
            newNodeList = tempNode;
            tempNode = tempNode->next;
        }
    }

    newNodeList->next = tempNode->next;
    *head = newNodeList;
    free(newNodeList);
    free(tempNode);
    return true;
}
// Passing list and position to delete the position item
bool deleteAt(Node** head, int position)
{
    // Initializing tempNode
    Node* tempNode = *head;
    Node* newNodeList = new Node();

    // Searching value
    for(int index = 0; index < position; index++)
    {
        // If item isn't found yet return false
        if(tempNode->next == NULL)
            return false;
        else
        {
            newNodeList = tempNode;
            tempNode = tempNode->next;
        }
    }

    newNodeList->next = tempNode->next;
    *head = newNodeList;
    free(newNodeList);
    free(tempNode);
    return true;
}

// passing just list reference
void display(Node* head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

bool detectLoop(Node* head)
{
    unordered_set<Node*> table;

    while(head != NULL)
    {
        if(table.find(head) != table.end())
            return true;
        table.insert(head);
        head = head->next;
    }

    return false;
}
bool FloydsCycleDetectLoop(Node* head)
{
    Node *slowNode = head, *fastNode = head;
    while(slowNode != NULL && fastNode != NULL && fastNode->next != NULL)
    {
        slowNode = slowNode->next;
        fastNode = fastNode->next->next;
        if(slowNode == fastNode)
            return true;
    }

    return false;
}


// passing just list reference
bool Search(Node* head, int key)
{
    while(head != NULL)
    {
        if(head->data == key)
            return true;
        head = head->next;
    }

    return false;
}

int main()
{

    Node* head = NULL;

    append(&head, 6);

    display(head);
    push(&head, 7);
    display(head);
    if(insertAfter(&head,7, 10))
        display(head);
    else
        printf("At value isn't found!\n");

    if(deleteItem(&head, 10))
    {
        display(head);
    }
    else
    {
        printf("The value isn't found!\n");
    }

    if(deleteAt(&head, 4))
        display(head);
    else
        printf("Position extend the list size!\n");

    if(Search(head, 10))
        printf("Got it!\n");
    else
        printf("Not found!\n");

        push(&head, 10);
        push(&head, 11);
    head->next->next->next = head->next;
    if(detectLoop(head))
        printf("Loop exist!\n");
    else
        printf("Loop doesn't exist\n");
    if(FloydsCycleDetectLoop(head))
        printf("Loop exist!\n");
    else
        printf("Loop doesn't exist\n");
    return 0;
}
