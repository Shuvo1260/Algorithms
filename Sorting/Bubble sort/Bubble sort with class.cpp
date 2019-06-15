/***This is a sorting algorithm. It will help to sort any kind off data in a sequence.
The time complexity of the code is O(n^2).This is too much slow algorithm for sorting**/


#include<cstdio>
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<string>
#include<vector>
#define Max 99999
using namespace std;

/**Now i am creating a class which contain friend function of bubble sorting
for sorting any kind of data type**/

class Sort
{
    /**We are making some friend function in public**/

public:
    template <typename T>           //using template for work with any kind of data type easily
    friend void bubble_sort(T (&Data)[Max],int Element_number);
    friend void bubble_sort(vector < string > &Data,int Element_number);
    template <typename T>
    friend void Swap(T &a,T &b);
    template <typename T>
    friend void show(T (&Data)[Max],int Element_number);
    friend void show(vector < string > &Data,int Element_number);

};


/**This is the body of the function of swapping data **/

template < typename T>
void Swap(T &first, T &second)
{
    T temporary;
    temporary=first;
    first=second;
    second=temporary;
}

/**This is the body of the bubble sort algorithm**/

template < typename T>
void bubble_sort(T (&Data)[Max],int Element_number)
{
    for(int counter=0; counter<Element_number; counter++)
    {
        for(int index=0; index<Element_number-counter-1; index++)
        {
            if(Data[index]>Data[index+1])
                Swap(Data[index],Data[index+1]);
        }
    }
}
void bubble_sort(vector < string > &Data, int Element_number)
{
    for(int counter=0; counter<Element_number; counter++)
    {
        for(int index=0; index<Element_number-counter-1; index++)
        {
            if(Data[index]>Data[index+1])
                Swap(Data[index],Data[index+1]);
        }
    }
}

/**This part for the string sorting part where string will be sorted**/


template <typename T>
void show(T (&Data)[Max],int Element_number)
{
    cout<<endl<<endl<<"Sorted data : ";
    for(int index=0; index<Element_number; index++)
    {
        if(index==Element_number-1)
            cout<<Data[index]<<endl;
        else
            cout<<Data[index]<<" ";
    }
}
void show(vector <string > &Data,int Element_number)
{
    cout<<endl<<endl<<"Sorted data : ";
    for(int index=0; index<Element_number; index++)
    {
        if(index==Element_number-1)
            cout<<Data[index]<<endl;
        else
            cout<<Data[index]<<" ";
    }
}

int main()
{
    int Integer_data[Max];
    float Float_data[Max];
    char Character_data[Max];
    string String_data;
    vector <string> String_vector_data;
    int Element_number;
    char Key;

    for(;;)
    {
        system("cls");
        cout<<"Sorting integer data 'I'"<<endl;
        cout<<"Sorting floating data 'F'"<<endl;
        cout<<"Sorting character data 'C'"<<endl;
        cout<<"Sorting string data 'S'"<<endl;

        Key=getch();
        cout<<endl<<endl;

        if(Key=='I'||Key=='i')
        {
            cout<<"Enter the number of element"<<endl;
            cin>>Element_number;
            cout<<"Enter your integer elements"<<endl;
            for(int Index=0; Index<Element_number; Index++)
                cin>>Integer_data[Index];
            bubble_sort(Integer_data,Element_number);
            show(Integer_data,Element_number);
        }
        else if(Key=='F'||Key=='f')
        {
            cout<<"Enter the number of element"<<endl;
            cin>>Element_number;
            cout<<"Enter your floating elements"<<endl;
            for(int Index=0; Index<Element_number; Index++)
                cin>>Float_data[Index];
            bubble_sort(Float_data,Element_number);
            show(Float_data,Element_number);
        }
        else if(Key=='C'||Key=='c')
        {
            cout<<"Enter the number of element"<<endl;
            cin>>Element_number;
            cout<<"Enter your character elements"<<endl;
            for(int Index=0; Index<Element_number; Index++)
                cin>>Character_data[Index];
            bubble_sort(Character_data,Element_number);
            show(Character_data,Element_number);
        }
        else if(Key=='S'||Key=='s')
        {
            cout<<"Enter the number of element"<<endl;
            cin>>Element_number;
            cout<<"Enter your string elements"<<endl;
            for(int Index=0; Index<Element_number; Index++)
            {
                cin>>String_data;
                String_vector_data.push_back(String_data);
            }
            bubble_sort(String_vector_data,Element_number);
            show(String_vector_data,Element_number);
            String_vector_data.clear();
        }
        else if(Key==27)
            exit(0);

        getch();
    }
    return 0;
}
