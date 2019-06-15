#include<iostream>
using namespace std;


void interchange(int &first_element, int &second_element)
{
    int temporary_element = first_element;
    first_element = second_element;
    second_element = temporary_element;
}

int Partition(int data_list[],int Begin,int End)
{
    int pivot = data_list[Begin];
    int first_index = Begin;
    int second_index = End;

    while(first_index < second_index)
    {
        while(data_list[first_index] <= pivot && first_index <= End)
            first_index++;
        while(data_list[second_index] > pivot && second_index >= Begin)
            second_index--;
        if(first_index < second_index)
        {
            interchange(data_list[first_index] , data_list[second_index]);
        }
    }
    data_list[Begin] = data_list[second_index];
    data_list[second_index] = pivot;

    return second_index;
}

void quick_sort(int data_list[], int Begin, int End)
{
    if(Begin < End)
    {
        int pivot_index = Partition(data_list, Begin, End);

        quick_sort(data_list, Begin, pivot_index-1);
        quick_sort(data_list, pivot_index+1, End);
    }
}
int main()
{
    int Elements_number;

    cout << "Enter Elements number : ";
    cin >> Elements_number;

    int data_list[Elements_number];

    cout << "Enter Elements: " << endl;
    for(int index = 0; index < Elements_number ; index++)
        cin >> data_list[index];

    quick_sort(data_list, 0, Elements_number);

    cout << "Sorted Elements: ";
    for(int index = 0; index < Elements_number ; index++)
        cout << data_list[index] << " ";
    cout << endl;


    return 0;
}
