//#include<cstdio>
//#include<iostream>
//#include<vector>
//#include<algorithm>

#include<bits/stdc++.h>

using namespace std;


int main()
{

    vector <int> myvector;

    int n;
    int value;

    cin >> n;

    for(int index = 0; index < n; index++)
    {
        cin >> value;
        myvector.push_back(value); // inserting into vector variable
    }

    cout << "Last element : " << myvector.back() << endl; // last element
    cout << "First element : " << myvector.front() << endl; // first element
    cout << "2 number indexed element : " << myvector.at(2) << endl; // printing 2 number indexed element

    vector <int> :: iterator it; /// pointer setting from begin to end
    myvector[1] = 0; // changing 1th element
    cout << myvector[1] << endl; // printing 1th element

    /// printing elements begin to end

    cout << "Elements : " ;
    for(it = myvector.begin(); it != myvector.end(); it++)
        printf("%d ", *it);
    cout << endl;

    vector <int> :: reverse_iterator ite; /// pointer setting from end to begin

    /// printing reverse order
    cout << "Reverse order : ";
    for(ite = myvector.rbegin(); ite != myvector.rend(); ++ite)
        printf("%d ", *ite);
    cout << endl;

    sort(myvector.begin(), myvector.end()); // sorting elements

    cout << "Sorted elements : ";
    ///printing sorting elements
    for(it = myvector.begin(); it != myvector.end(); it++)
        printf("%d ", *it);
    cout << endl;

    it = myvector.begin();

    myvector.erase(it+1); // removing the 1th indexed element
    myvector.erase(it+2,it+4); // removing the 2 to 4th indexed elements
    myvector.insert(myvector.begin()+1, 7); // inserting element at a position

    cout << "Modified elements : ";
    for(it = myvector.begin(); it != myvector.end(); it++)
        printf("%d ", *it);
    cout << endl;


    myvector.clear(); // clearing full vector

    return 0;
}
