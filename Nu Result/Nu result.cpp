#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

int main()
{
    ifstream result_file;

    result_file.open("Result.txt");

    string value;
    while(result_file >> value)
    {
        if(value == "15502000440")
            cout << "Shovo" << endl;
        else if(value == "15502000535")
            cout << "Habiba" << endl;

    }

    return 0;
}
