#include<iostream>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
void bubble(int a[],int n)
{
    int k,i,j,temp;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
}

void Merge(int data_list[], int Begin, int mid, int End)
{
    int left_data_list[End];
    int right_data_list[End];
    int left_index = 0;
    int right_index = 0;

    for(int index = Begin; index <= mid; index++)
    {
        left_data_list[left_index++] = data_list[index];
    }

    for(int index = mid+1; index <= End; index++)
    {
        right_data_list[right_index++] = data_list[index];
    }
    int left_index_size = left_index;
    int right_index_size = right_index;
    left_index = 0;
    right_index = 0;
    int index = Begin;

    while(index <= End && left_index < left_index_size && right_index < right_index_size)
    {
        if(left_data_list[left_index] < right_data_list[right_index])
            data_list[index++] = left_data_list[left_index++];
        else
            data_list[index++] = right_data_list[right_index++];
    }

    while(left_index < left_index_size)
        data_list[index++] = left_data_list[left_index++];

    while(right_index < right_index_size)
        data_list[index++] = right_data_list[right_index++];

}

void merge_sort(int data_list[], int Begin, int End)
{
    if(Begin < End)
    {
        int mid = (Begin + End) / 2;

        merge_sort(data_list, Begin, mid);
        merge_sort(data_list, mid+1, End);

        Merge(data_list,Begin, mid, End);
    }
}
int main()
{
    int i;
    int b[4500];
    time_t sb,eb,sq,eq;

    for(i=0; i<4500; i++)
    {
        b[i]=rand()%50;
    }


    cout << endl;
    sb=clock();
    bubble(b,4500);
    eb=clock();


    cout<<"Bubble "<<(double(eb-sb)/CLOCKS_PER_SEC)<<"\n";

    sq=clock();

    for(i=0; i<4500; i++)
    {
        b[i]=rand()%50;
    }

    merge_sort(b,1,4500);
    eq=clock();

    cout<<"Merge "<<(double(eq-sq)/CLOCKS_PER_SEC);
    getch();
    return 0;
}
