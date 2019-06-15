#include<cstdio>
#include<iostream>

using namespace std;

void bubble_sort(int Array[], int Elements_number)
{
    for(int line_counter = 0; line_counter < Elements_number - 1; line_counter++)
    {
        for(int index = 0; index < Elements_number-line_counter-1; index++)
        {
            if(Array[index] > Array[index+1])
            {

                int temporary_variable = Array[index];
                Array[index] = Array[index+1];
                Array[index+1] = temporary_variable;
            }
        }
    }
}


int main()
{
    int Elements_number;

    cout << "Enter Elements number : ";
    cin >> Elements_number;

    int Array[Elements_number];

    cout << "Enter Elements: " << endl;
    for(int index = 0; index < Elements_number ; index++)
        cin >> Array[index];

    bubble_sort(Array, Elements_number);

    cout << "Sorted Elements: ";
    for(int index = 0; index < Elements_number ; index++)
        cout << Array[index] << " ";
    cout << endl;



    return 0;
}
