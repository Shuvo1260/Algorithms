#include<cstdio>
#include<cstring>

void display(int location)
{
    if(!location)
        printf("\nItem not found!\n");
    else
        printf("\nItem location is : %d\n",location);
}

int Binary_search(char Data_list[], char item, int Begin, int End)
{
    if(Begin > End)
        return 0;
    else
    {
        int mid = (Begin + End) / 2;

        if(Data_list[mid] == item)
            return mid+1;
        else if (Data_list[mid] < item)
            Binary_search(Data_list, item, mid+1, End);
        else
            Binary_search(Data_list, item, Begin, mid-1);
    }
}

int main()
{
    char Data_list[] = {'a','d','g','h','j','l','p','q','s','t'};

    printf("Data list : ");
    for(int index = 0; index < 10; index++)
        printf("%c ", Data_list[index]);
    printf("\n");

    char item;
    printf("\nEnter your item : ");
    scanf("%c",&item);

    int location = Binary_search(Data_list,item,0,10);

    display(location);

    return 0;
}
