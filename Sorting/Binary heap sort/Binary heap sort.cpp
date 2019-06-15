#include<iostream>
#include<cstdio>

using namespace std;

void heap(int data[], int number, int index)
{
    int largest = index;
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    if( left < number && data[largest] < data[left])
        largest = left;
    if(right < number && data[largest] < data[right])
        largest = right;

    if( largest != index)
    {
        swap(data[largest], data[index]);

        heap(data, number, largest);
    }
}

void heap_sort(int data[], int number)
{
    for(int index = number/2-1; index >= 0; index--)
        heap(data,number,index);

    for(int index = number-1; index >= 0; index--)
    {
        swap(data[0], data[index]);

        heap(data, index, 0);
    }
}

int main()
{
    int number;

    cout << "Enter Elements number : ";
    cin >> number;

    int data[number];

    cout << "Enter Elements: " << endl;
    for(int index = 0; index < number ; index++)
        cin >> data[index];

    heap_sort(data, number);

    cout << "Sorted Elements: ";
    for(int index = 0; index < number ; index++)
        cout << data[index] << " ";
    cout << endl;

    return 0;
}
