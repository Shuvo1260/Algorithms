#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<cstring>
#include<conio.h>
#include<windows.h>
using namespace std;

/// Node with header and leaf
struct node
{
    int data;
    node *next;
};
node *head = NULL, *last = NULL;

void create();
void display();
void insert_at_first(int element);
void insert_at_last(int element);
void insert_into_list(int element, int position_element);
void delete_element(int element);
void Search(int element);

int main()
{
    create();
    display();
    getch();

    while(1)
    {
        /// Input portion
        system("cls");
        cout << "For insert first press 'F'" << endl;
        cout << "For insert last press 'L'" << endl;
        cout << "For insert into list press 'M'" << endl;
        cout << "For delete item press 'D'" << endl;
        cout << "For search item press 'S'" << endl;
        cout << "For display list press 'E'" << endl;
        char key = getch();
        int element;
        int position_element;

        if(key == 'f' || key == 'F')
        {
            cout << "Enter your element to insert : " << endl;
            cin >> element;
            insert_at_first(element);
            cout << endl << endl;
            cout << "Insertion successful.." << endl;
        }
        else if(key == 'L' || key == 'l')
        {
            cout << "Enter your element to insert : " << endl;
            cin >> element;
            insert_at_last(element);
            cout << endl << endl;
            cout << "Insertion successful.." << endl;
        }
        else if(key == 'M' || key == 'm')
        {
            cout << "Enter your element to insert : " << endl;
            cin >> element;
            cout << "Enter the position item : " << endl;
            cin >> position_element;
            insert_into_list(element , position_element);
            cout << endl << endl;
            cout << "Insertion successful.." << endl;
        }
        else if(key == 'D' || key == 'd')
        {
            cout << "Enter your item to delete : " << endl;
            cin >> element;
            cout << endl << endl;
            delete_element(element);
        }
        else if(key == 'S' || key == 's')
        {
            cout << "Enter your element to search : " << endl;
            cin >> element;
            cout << endl << endl;
            Search(element);
        }
        else if(key == 'E' || key == 'e')
        {
            cout << endl << endl;
            display();
        }
        getch();
    }

    return 0;
}
void create()
{
    int element;
    int number;
    cout << "Enter number of elements : ";
    cin >> number;
    cout << "Enter your elements : " << endl;
    for(int counter = 0; counter < number; counter++)
    {
        cin >> element;
        insert_at_last(element);
    }
}

/// Inserting the element at the first position of the list
void insert_at_first(int element)
{
    node *temporary_linked_list;
    temporary_linked_list = (node *) malloc(sizeof(node));

    temporary_linked_list->data = element;
    temporary_linked_list->next = head;

    head = temporary_linked_list;
}

/// Inserting the element at the last position of the list
void insert_at_last(int element)
{
    node *temporary_linked_list;
    temporary_linked_list = (node *) malloc(sizeof(node));

    temporary_linked_list->data = element;
    temporary_linked_list->next = NULL;

    if(head == NULL)
    {
        head = temporary_linked_list;
        last = temporary_linked_list;
    }
    else
    {
        last->next = temporary_linked_list;
        last = temporary_linked_list;
    }
}

/// Inserting the element at the i th position of the list
void insert_into_list(int element, int position_element)
{
    node *my_list;
    my_list = head;
    bool flag = true;

    while(my_list != NULL)
    {
        if(my_list->data == position_element)
        {
            node *temporary_linked_list;
            temporary_linked_list = (node *) malloc(sizeof(node));

            temporary_linked_list->data = element;
            temporary_linked_list->next = my_list->next;
            my_list->next = temporary_linked_list;
            flag = false;
            break;
        }
        else
            my_list = my_list->next;
    }
    if(flag)
        cout << "You give wrong address" << endl;
}

/// Deleting an element from the list
void delete_element(int element)
{
    node *my_list, *previous_node = NULL;
    my_list = head;

    bool flag = false;

    while(my_list != NULL)
    {
        if(my_list->data == element)
        {
            if(previous_node == NULL)
                head = my_list->next;
            else
                previous_node->next = my_list->next;
            cout << "Deleted successfully!!" << endl;
            flag = true;
            break;
        }
        previous_node = my_list;
        my_list = my_list->next;
    }
    if(!flag)
        cout << "Item not found" << endl;

}

/// Searching an element from the list
void Search(int element)
{
    node *my_list;
    my_list = head;
    bool flag = false;
    int counter = 1;
    while(my_list != NULL)
    {
        if(my_list->data == element)
        {
            cout << "Item position is : " << counter << endl;
            flag = true;
            break;
        }
        else
        {
            my_list = my_list->next;
        }
        counter++;
    }
    if(!flag)
        cout << "Item not found!!" << endl;
}

/// List displaying function
void display()
{
    cout << "Your list elements : ";
    node *data_list;
    data_list = head;

    while(data_list)
    {
        cout << data_list->data << " ";
        data_list = data_list-> next;
    }
    cout << endl;
}
