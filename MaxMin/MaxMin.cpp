#include<iostream>
using namespace std;


void MaxMin(int data_list[], int Begin, int End, int &Max, int &Min);

int main()
{
    int Elements_number;
    int Max, Min;

    cout << "Enter Elements number : ";
    cin >> Elements_number;

    int data_list[Elements_number];

    cout << "Enter Elements: " << endl;
    for(int index = 0; index < Elements_number ; index++)
        cin >> data_list[index];


    MaxMin(data_list, 0, Elements_number-1, Max, Min);

    cout << "Max = " << Max<< endl;
    cout << "Min = " << Min << endl;


    return 0;
}
void MaxMin(int data_list[], int Begin, int End, int &Max, int &Min)
{
    int temp_max, temp_min;

    if(Begin == End)
    {
        Max = data_list[Begin];
        Min = data_list[Begin];
    }
    else if(Begin == End-1)
    {
        if(data_list[Begin] > data_list[End])
        {
            Max = data_list[Begin];
            Min = data_list[End];
        }
        else
        {
            Max = data_list[End];
            Min = data_list[Begin];
        }
    }
    else
    {
        int mid = (Begin + End)/2;

        MaxMin(data_list, Begin, mid, Max, Min);
        MaxMin(data_list, mid+1, End, temp_max, temp_min);

        if(temp_max > Max)
            Max = temp_max;
        if(temp_min < Min)
            Min = temp_min;
    }
}
