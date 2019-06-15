#include<cstdio>
#include<iostream>

using namespace std;

int linear_search(int Array[],int element_number , int item)
{
    for(int index = 0; index < element_number; index++)
        if(Array[index] == item)
            return index+1;
    return 0;
}

int main()
{
    int Array[15] = { 231, 78, 98, 15, 456, 1234, 789, 786, 124, 258};

    int item;

    cout << "Elements : ";

    for(int index = 0; index < 10; index++)
        printf("%d ", Array[index]);
    cout << endl;

    cout << "Enter your item : ";
    cin >> item;


    int location = linear_search(Array, 10, item);

    if(location == 0)
        cout << "Item not found!!" << endl;
    else
        cout << "Item position is : " << location << endl;

    return 0;
}
