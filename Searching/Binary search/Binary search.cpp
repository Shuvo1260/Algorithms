/**This is a searching algorithm. It works in a sorted list to search an element quickly.
This is to much fast algorithm. The time complexity of the algorithm is O(log n).
The procedure of the algorithm is : it determine the middle value of the data list and compare
with item if it doesn't match then it determine that where could be the item from the middle left or right.**/

#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    char Data[10]={'1','2','3','5','6','7','8','9'};
    int Begin;
    int End;
    int Middle;
    int Location=0;
    char Item;

    cout<<"Data : ";
    for(int index=0; index<8 ; index++)
        cout<<Data[index]<<" ";
    cout<<endl;

    cout<<"Enter your item : ";
    cin>>Item;

    Begin=0;
    End=8;
    Middle=(Begin+End)/2;

     /** Now it will determine the possible position direction of the item**/

    while( Begin<=End && Item!=Data[Middle] )
    {
        if(Item<Data[Middle])
            End=Middle-1;
        else
            Begin=Middle+1;
        Middle=(Begin+End)/2;
    }

    if(Item==Data[Middle])
        cout<<"The location of the item is "<<Middle+1<<endl;
    else
        cout<<"Invalid data"<<endl;

    return 0;
}
