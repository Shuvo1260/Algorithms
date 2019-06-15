#include<iostream>
using namespace std;
void interchange(int *first_element, int *second_element)
{
    int temporary_variable;
    temporary_variable = *first_element;
    *first_element = *second_element;
    *second_element = temporary_variable;
}
void selection_sort(int data_list[], int element_number)
{
    int minimum_element_index;
    for(int step_counter = 0; step_counter < element_number-1; step_counter++)
    {
        minimum_element_index = step_counter;
        for(int index = step_counter+1; index < element_number; index++)
        {
            if(data_list[minimum_element_index] > data_list[index])
                minimum_element_index = index;
        }
        if(step_counter != minimum_element_index)
            interchange( &data_list[step_counter], &data_list[minimum_element_index]);
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

    selection_sort(data_list, element_number);

    cout << "Sorted data are : ";
    for(int index = 0; index < element_number ; index++)
    {
        cout << data_list[index] << " ";
    }
    cout << endl;
    return 0;
}
