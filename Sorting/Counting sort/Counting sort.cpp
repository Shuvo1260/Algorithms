/**This is counting sort. This is a sorting algorithm code. We can sort positive integer
by this algorithm. It will work in only positive integer which range is maximum array size.
The time complexity of the program is O(m*n).**/

#include<iostream>

using namespace std;

int main()
{
    long long int Data[99999]={0};
    long long int Element_number;
    long long int Max_element=0;
    long long int Element;

    cout<<"Enter the number of element : "<<endl;
    cin>>Element_number;
    cout<<"Enter Elements : ";

    for(int Counter=0; Counter<Element_number; Counter++)
    {
        cin>>Element;
        Data[Element]++;
        Max_element=max(Max_element,Element); //This will detect the largest element of the data
    }

    /**Here we will print the Data in a sequence otherwise
    we have to do nothing **/

    cout<<"Sorted Elements : ";

    for(int Index=0; Index<=Max_element; Index++)
    {
        for(int Counter=0; Counter<Data[Index]; Counter++)
            cout<<Index<<" ";
    }
    cout<<endl;

    return 0;
}
