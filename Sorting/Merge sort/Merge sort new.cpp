#include<iostream>
using namespace std;

void Merge(int data_list[], int Begin, int mid, int End)
{
    int left_data_list[End];
    int right_data_list[End];
    int left_index = 0;
    int right_index = 0;

    for(int index = Begin; index <= mid; index++)
    {
        left_data_list[left_index++] = data_list[index];
    }

    for(int index = mid+1; index <= End; index++)
    {
        right_data_list[right_index++] = data_list[index];
    }
    int left_index_size = left_index;
    int right_index_size = right_index;
    left_index = 0;
    right_index = 0;
    int index = Begin;

    while(index <= End && left_index < left_index_size && right_index < right_index_size)
    {
        if(left_data_list[left_index] < right_data_list[right_index])
            data_list[index++] = left_data_list[left_index++];
        else
            data_list[index++] = right_data_list[right_index++];
    }

    while(left_index < left_index_size)
        data_list[index++] = left_data_list[left_index++];

    while(right_index < right_index_size)
        data_list[index++] = right_data_list[right_index++];

}

void merge_sort(int data_list[], int Begin, int End)
{
    if(Begin < End)
    {
        int mid = (Begin + End) / 2;

        merge_sort(data_list, Begin, mid);
        merge_sort(data_list, mid+1, End);

        Merge(data_list,Begin, mid, End);
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

    merge_sort(data_list, 0, Elements_number-1);

    cout << "Sorted Elements: ";
    for(int index = 0; index < Elements_number ; index++)
        cout << data_list[index] << " ";
    cout << endl;


    return 0;
}
