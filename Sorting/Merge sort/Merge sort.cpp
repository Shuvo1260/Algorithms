#include<iostream>
#include<cstdio>
using namespace std;

void merging(int data_list[], int Begin, int mid, int End)
{
    int left_list_size = mid - Begin +1;
    int right_list_size = End - mid;

    int left_list[left_list_size];
    int right_list[right_list_size];

    for(int index = 0; index < left_list_size; index++)
        left_list[index] = data_list[Begin + index];

    for(int index = 0; index < right_list_size; index++)
        right_list[index] = data_list[mid +1 + index];


    int left_index = 0;
    int right_index = 0;
    int main_list_index = Begin;

    while( left_index < left_list_size && right_index < right_list_size)
    {
        if(left_list[left_index] <= right_list[right_index])
            data_list[main_list_index++] = left_list[left_index++];
        else
            data_list[main_list_index++] = right_list[right_index++];
    }

    while(left_index < left_list_size)
    {
        data_list[main_list_index++] = left_list[left_index++];
    }

    while(right_index < right_list_size)
    {
        data_list[main_list_index++] = right_list[right_index++];
    }
}

void merge_sort(int data_list[], int Begin, int End)
{
    if(Begin < End)
    {

        int mid = ( Begin + End -1) / 2;

        merge_sort(data_list, Begin, mid);
        merge_sort(data_list, mid+1, End);

        merging(data_list, Begin, mid, End);
    }
}

void display(int data_list[], int element_number)
{
    cout << "Sorted elements are : ";
    for(int index = 0; index < element_number; index++)
        cout << data_list[index] << " ";
    cout << endl;
}

int main()
{
    int element_number;

    cout << "Enter elements number : ";
    cin >> element_number;

    int data_list[element_number];

    cout << "Enter elements : " << endl;
    for(int index = 0; index < element_number; index++)
        cin >> data_list[index];

    merge_sort(data_list, 0, element_number);

    display(data_list, element_number);

    return 0;
}
