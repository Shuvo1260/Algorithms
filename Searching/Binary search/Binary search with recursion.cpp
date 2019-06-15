/**This is a searching algorithm. It works in a sorted list to search an element quickly.
This is to much fast algorithm. The time complexity of the algorithm is O(log n).
The procedure of the algorithm is : it determine the middle value of the data list and compare
with item if it doesn't match then it determine that where could be the item from the middle left or right.**/

#include<iostream>
#include<string.h>
using namespace std;
int Binary_search(char Data[], char Item, int Begin, int End)
{
    int Middle=( Begin + End ) /2 ;  // Determining the middle of the data list

    /** Now it will determine the possible position direction of the item**/

    if(Begin<=End && Item != Data[Middle])
    {
        if(Item<Data[Middle])
            Binary_search(Data,Item,Begin,Middle-1);
        else
            Binary_search(Data,Item,Middle+1,End);
    }
    else if(Item == Data[Middle])
        return Middle+1;
    else if(Item != Data[Middle])
        return 0;

}

int main()
{
    char Data[10]={'1','2','3','5','6','7','8','9'};
    int Begin=0;
    int End=8;
    int Middle;
    int Location=0;
    char Item;

    cout<<"Data :";
    for(int index=0; index<8 ; index++)
        cout<<Data[index]<<" ";
    cout<<endl;

     cout<<"Enter your item : ";
    cin>>Item;

    Location=Binary_search(Data,Item,Begin,End);

    if(!Location)
        cout<<"Invalid Item"<<endl;
    else
        cout<<"The location of the item is "<<Location<<endl;

    return 0;
}
