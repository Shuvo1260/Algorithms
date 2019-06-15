#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    int elements[100] = {21, 564, 546, 987, 31, 968, 12};

    cout << "Elements : ";

    for(int index = 0; index < 7; index++)
        printf("%d ", elements[index]);
    cout << endl;


    sort(elements, elements+7);


    cout << "Sorted at ascending order : ";
    for(int index = 0; index < 7; index++)
        printf("%d ", elements[index]);
    cout << endl;

    sort(elements, elements+7, cmp);

    cout << "Sorted at descending order : ";
    for(int index = 0; index < 7; index++)
        printf("%d ", elements[index]);
    cout << endl;

    return 0;
}
