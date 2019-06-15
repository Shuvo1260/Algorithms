/** This is a searching algorithm. It will search your element in linear way
by comparing each element of data. The time complexity of the algorithm is
O(n)**/

#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main()
{
    char Data[10]= {'s','h','o','v','o','h','a','s','i','s'};
    cout<<"Data list : ";
    for(int index=0; index<10; index++)
    {
        cout <<Data[index]<<" ";
    }
    cout << endl <<endl;

    char Item;
    cout<<"Enter your Item : ";
    cin>>Item;

    int Location=0;
    vector< int > Location_number;

    /**This is linear search code. here i am detecting where are the location
    of given item. if i get the location then i just through it in Location_number
    because there could be more then one location for the item**/

    for(int index=0; index<10; index++)
    {
        if(Data[index] == Item)
        {
            Location++;
            Location_number.push_back(index+1);
        }
    }


    if(!Location)
        cout<<"Invalid item"<<endl;
    else if(Location==1)
        cout<<"The location of item is "<<Location_number[0]<<endl;
    else
    {
        cout<<"The location of the item is ";
        for(int index=0; index<Location_number.size(); index++)
        {
            cout<<Location_number[index];
            if(index==Location_number.size()-2)
                cout<<" and ";
            else
            {
                if(index!=Location_number.size()-1)
                    cout<<", ";
            }

        }
        cout<<endl;
    }

    return 0;
}
