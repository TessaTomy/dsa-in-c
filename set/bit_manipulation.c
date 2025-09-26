/*
 * bit_manipulation.c
 * Set operations using bitwise representation in C.
 * Supports creation, union, intersection, difference, and display.
 * bounded universal set (MAX = 30).
 */

#include <stdio.h>
#define MAX 30
int a=0,b=0,n1,n2;

// Creates two sets from user input using bitwise encoding
void create()
{
    int value;
    printf("Enter Size of Set 1 :");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&value);
        if(value<0||value>MAX-1)
        {
            printf("Value OUtside Universal set !!");
            i--;
        }
        else
            a|=(1U<<value);
    }
    printf("Enter Size of Set 2 :");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++)
    {
        scanf("%d",&value);
        if(value<0||value>MAX-1)
        {
            printf("Value OUtside Universal set !!");
            i--;
        }
        else
            b|=(1U<<value);
    }
}

void unionn()
{
    printf("{");
    int c= a | b;
    for(int i=0;i<MAX;i++)
    {
        if (c&(1U<<i))
            printf("%d,",i);
    }
    printf("}");
}
void intersection()
{
    int c= a & b;
    printf("{");
    for(int i=0;i<MAX;i++)
    {
        if (c&(1U<<i))
            printf("%d,",i);
    }
    printf("}");
}

// Computes and displays the difference: Set 1 - Set 2
void diff()
{
    printf("{");
    int c=a&(~b);
    for(int i=0;i<MAX;i++)
    {
        if (c&(1U<<i))
            printf("%d,",i);
    }
    printf("}");
}

void display()
{
    printf("Set 1 : {");
    for(int i=0;i<MAX;i++)
    {
        if (a&(1U<<i))
            printf("%d,",i);
    }
    printf("}\nSet 2:{");
    for(int i=0;i<MAX;i++)
    {
        if (b&(1U<<i))
            printf("%d,",i);
    }
    printf("}\n");
}
int main() {
    for(;;)
    {
        int c;
        printf("\n1.Create\n2.Union\n3.Intersection\n4.Difference\n5.Display\n6.Exit\n>>");
        scanf("%d",&c);
        if(c==1)
            create();
        else if(c==2)
            unionn();
        else if(c==3)  
            intersection();
        else if(c==4)
            diff();
        else if(c==5)
            display();
        else
            return 0;
    }
    return 0;
}
