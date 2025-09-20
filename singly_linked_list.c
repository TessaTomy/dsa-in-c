#include <stdio.h>
#include <stdlib.h>

struct sll
{
    int data;
    struct sll* next;
};

int count=0;

typedef struct sll* node;

node start=NULL;

int isempty()
{
    return (!start)?1:0;
}

node read()
{
    node nnode=(node) malloc (sizeof(struct sll));
    nnode->next=NULL;
    printf("Data :");
    scanf("%d",&nnode->data);
    count++;
    return nnode;
}

void insertb()
{
    node nnode= read();
    start=nnode;
}

void insert(int pos)
{
    node nnode=read();
    node temp;
    int c=0;
    for(temp=start;c<pos-1&&temp!=NULL;temp=temp->next,c++);
    nnode->next=temp->next;
    temp->next=nnode;
}

void traverse()
{
	for(node temp=start;temp!=NULL;temp=temp->next)
	{
	    printf("%d -> ",temp->data);
	}
}

void create()
{
    int c=1;
    while(c)
    {
	if(isempty())
	    insertb();
	else
	    insert(count);
	printf("Do u wish to add another elemet (0/1) :");
	scanf("%d",&c);
    }
}




void insertNode()
{
	int pos;
	printf("Insertion Index :");
	scanf("%d",&pos);
	if(pos<1||pos>count+1)
		printf("Invalid Index !!");
	else
	{
		if(pos==1)
		{
			if(isempty())
				insertb();
			else
			{
				node nnode=read();
				nnode->next=start;
				start=nnode;
			}
		}
		else
		{
			insert(pos-1);

		}
			printf("Element Inserted Sucessfully !!");
			traverse();
	}
}
void del()
{
	int pos;
	printf("Deletion Index :");
	scanf("%d",&pos);
	if(pos<1||pos>count)
		printf("Invalid Index !!");
	else
	{
		if(pos==1)
		{
		 node nnode=start;
		 start=start->next;
		 free(nnode);
		}
		
		else
		{
            int c=0;
			node temp;
			for(temp=start;c<pos-2&&temp!=NULL;temp=temp->next,c++);
			node delNode=temp->next;
			temp->next=temp->next->next;
			free(delNode);
			
		}
		count--;
		printf("Element Deleted Sucessfully !!");
		traverse();
	}
}

void freeall()
{
    node next=start,p;
    while(next!=NULL)
	{
	    p=next;
	    next=p->next;
	    free(p);
	}
}
void main() {
    while (1)
    {
	int choice;
	printf("\n=========================\nEnter Your Choice : \n1.Create\n2.Insert\n3.Delete\n4.Travserse\n5.Count\n6.Exit\n?:");
	scanf("%d",&choice);
	switch(choice)
	{
	    case 1:create();
		    break;
	    case 2:insertNode();
		    break;
	    case 3:del();
		    break;
	    case 4: traverse();
		    break;
	    case 5: printf("Total number of nodes = %d",count);
		    break;
	    case 6: freeall();
	        return;
	}
    }
}
