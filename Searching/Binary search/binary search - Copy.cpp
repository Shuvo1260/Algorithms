#include<cstdio>
#include<iostream>

using namespace std;

int Binary_search(int Array[], int Front_index, int Rear_index , int item)
{
    if(Front_index > Rear_index)
        return 0;
    else
    {
        int middle_index = (Front_index + Rear_index) / 2;

        if(Array[middle_index] == item)
            return middle_index+1;
        else
        {
            if(item < Array[middle_index])
                Binary_search(Array, Front_index, middle_index-1 , item);
            else
                Binary_search(Array, middle_index+1, Rear_index , item);
        }
    }

}

int main()
{

    int Array[15] = { 5, 7, 12, 45, 99, 127, 200, 564, 789, 987};

    int item;
    cout << "Elements : ";

    for(int index = 0; index < 10; index++)
        printf("%d ", Array[index]);
    cout << endl;

    cout << "Enter your item : ";
    cin >> item;

    int location = Binary_search(Array,0,10 , item);

    if(location == 0)
        cout << "Item not found!!" << endl;
    else
        cout << "Item position is : " << location << endl;

    return 0;
}
