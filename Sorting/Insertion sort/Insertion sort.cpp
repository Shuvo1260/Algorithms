#include<iostream>
using namespace std;

void insertion_sort(int data_list[], int element_number)
{
    for(int item_index = 1; item_index < element_number; item_index++)
    {
        int item = data_list[item_index];
        int index;
        for( index = item_index-1; index >= 0 && item < data_list[index]; index--)
        {
            data_list[index+1] = data_list[index];
        }
        data_list[index+1] = item;
    }
}
int main()
{
    int element_number;

    cout << "Enter number of elements : " ;
    cin >> element_number;

    int data_list[element_number];

    cout << "Enter your elements : " << endl;
    for(int index = 0; index < element_number ; index++)
    {
        cin >> data_list[index];
    }

    insertion_sort(data_list, element_number);

    cout << "Sorted data are : ";
    for(int index = 0; index < element_number ; index++)
    {
        cout << data_list[index] << " ";
    }
    cout << endl;
    return 0;
}
