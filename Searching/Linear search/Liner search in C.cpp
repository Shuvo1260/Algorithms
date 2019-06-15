#include<cstdio>
/** Here you can use #include<stdio.h> those are same
one use in cstdio use in .cpp file and stdio.h use in
.c file **/

#include<cstring>
/** same as string.h **/

void display(int location[], int location_size)
{
    if(location_size == 0)
        printf("\nItem not found!!\n");
    else
        printf("\nItem locations : ");
    for(int index = 0; index < location_size; index++)
    {
        printf("%d",location[index]);

        if(index < location_size - 2)
            printf(", ");
        else if(index == location_size-2)
            printf(" and ");
        else
            printf("\n");
    }
}

void linear_search(char Data_list[], int list_size, char item)
{
    int location[list_size];
    int location_index = 0;
    for(int index = 0; index < list_size; index++)
    {
        if(Data_list[index] == item)
            location[location_index++] = index+1;
    }
    display(location, location_index);
}

int main()
{
    char Data_list[] = {'s','h','o','v','o','h','a','s','i','s'};

    printf("Data list : ");
    for(int index = 0; index < 10; index++)
        printf("%c ", Data_list[index]);
    printf("\n");

    char item;
    printf("\nEnter your item : ");
    scanf("%c",&item);

    linear_search(Data_list,10,item);
    /** calling linear_search function for searching the given item **/


    return 0;
}
