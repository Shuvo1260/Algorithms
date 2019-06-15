#include<cstdio>
#include<iostream>
#include<map>
#include<string>

using namespace std;


int main()
{
    string name;
    int value;

    int n;
    cin >> n;

    map <string, int> myMap; /// Declaring map
    for(int counter = 0; counter < n; counter++)
    {
        cin >> name >> value;
        myMap[name] = value; /// Inserting value
    }

    map <string, int> :: iterator it; /// Map iteration declare

    /// Printing map
    for(it = myMap.begin(); it != myMap.end(); it++)
        cout << it->first << " " << it->second << endl;

    myMap.erase("yo"); /// erasing yo indexed value

    for(it = myMap.begin(); it != myMap.end(); it++)
        cout << it->first << " " << it->second << endl;

    cout << myMap.at("shovo") << endl;
    cout << myMap["shovo"] << endl;

    myMap.clear(); // map clear


    return 0;
}
