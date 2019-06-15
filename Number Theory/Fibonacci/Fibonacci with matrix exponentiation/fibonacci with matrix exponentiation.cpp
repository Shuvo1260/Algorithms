#include<bits/stdc++.h>

using namespace std;


void multiply(int f[2][2], int m[2][2])
{
    int temp[4];
    temp[0] = f[0][0] * m[0][0] + f[0][1] * m[1][0];
    temp[1] = f[0][0] * m[0][1] + f[0][1] * m[1][1];
    temp[2] = f[1][0] * m[0][0] + f[1][1] * m[1][0];
    temp[3] = f[1][0] * m[0][1] + f[1][1] * m[1][1];

    f[0][0] = temp[0];
    f[0][1] = temp[1];
    f[1][0] = temp[2];
    f[1][1] = temp[3];
}

void power(int f[2][2], int n)
{
    if(n == 0 || n == 1)
        return ;
    else
    {
        int m[2][2] = {{1, 1},{1, 0}};

        power(f, n/2);

        multiply(f, f);

        if(n & 1)
            multiply(f, m);
    }
}



int fibonacci(int n)
{
    if(n == 0)
        return 0;
    else
    {
        int f[2][2] = {{1, 1},{1, 0}};

        power(f, n-1);

        return f[0][0];
    }
}



int main()
{
    int n;

    cout << "Enter the term = ";
    cin >> n;

    cout << fibonacci(n) << endl;
    return 0;
}
