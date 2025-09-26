#include <stdio.h>
#include <stdlib.h>

struct csll {
    int data;
    struct csll* next;
};

typedef struct csll* node;

node start = NULL;
int count = 0;

int isempty() {
    return (start == NULL);
}

node read() {
    node nnode = (node)malloc(sizeof(struct csll));
    if (!nnode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Data : ");
    scanf("%d", &nnode->data);
    nnode->next = NULL;
    count++;
    return nnode;
}

void insertb() {
    node nnode = read();
    if (isempty()) {
        start = nnode;
        start->next = start;
    } else {
        node temp;
        for ( temp = start;temp->next!=start; temp=temp->next);
        nnode->next = start;
        temp->next = nnode;
        start = nnode;
    }
}

//insertion mid/end
void insert(int pos) {
    node nnode = read(),temp;
    int c;
    for (temp = start,c=1;temp->next!=start&&c<pos-1; temp=temp->next,c++);
    nnode->next = temp->next;
    temp->next = nnode;
}

void traverse() {
    if (isempty()) {
        printf("List is empty\n");
        return;
    }
    node temp = start;
    for (int i = 0; i < count; i++,temp = temp->next) {
        printf("%d -> ", temp->data);
    }
}

void create() {
    int c = 1;
    while (c) {
        if (isempty())
            insertb();
        else
            insert(count);
        printf("Do u wish to add another element (0/1) : ");
        scanf("%d", &c);
    }
}

void insertNode() {
    int pos;
    printf("Insertion Index : ");
    scanf("%d", &pos);
    if (pos < 1 || pos > count + 1)
        printf("Invalid Index !!\n");
    else {
        if (pos == 1)
            insertb();
        else
            insert(pos);
        printf("Element Inserted Successfully !!\n");
        traverse();
    }
}

void del() {
    int pos;
    printf("Deletion Index : ");
    scanf("%d", &pos);
    if (pos < 1 || pos > count) {
        printf("Invalid Index !!\n");
        return;
    }

    if (pos == 1) {
        node delNode = start;
        if (count == 1) {
            start = NULL;
        } else {
            node temp;
            for ( temp = start;temp->next!=start; temp=temp->next);
            start = start->next;
            temp->next = start;
        }
        free(delNode);
    } else {
        int c;
        node temp;
        for (temp = start,c=1;temp->next!=start&&c<pos-1; temp=temp->next,c++);
        node delNode = temp->next;
        temp->next = delNode->next;
        free(delNode);
    }

    count--;
    printf("Element Deleted Successfully !!\n");
    traverse();
}

void search() {
    if (isempty()) {
        printf("Linked List is Empty !!\n");
        return;
    }

    int key;
    printf("Enter value to search: ");
    scanf("%d", &key);

    node temp = start;
    for (int pos = 1; pos <= count; pos++, temp = temp->next) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
    }

    printf("Element %d not found in the list\n", key);
}

void freeall() {
    if (isempty()) return;

    node temp = start->next;
    for (int i = 1; i < count; i++) {
        node p = temp;
        temp = temp->next;
        free(p);
    }
    free(start);
    start = NULL;
    count = 0;
}

void main() {
    while (1) {
        int choice;
        printf("\n=========================\nEnter Your Choice :\n1.Create\n2.Insert\n3.Delete\n4.Traverse\n5.Count\n6.Search\n7.Exit\n?: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: create(); break;
            case 2: insertNode(); break;
            case 3: del(); break;
            case 4: traverse(); break;
            case 5: printf("Total number of nodes = %d\n", count); break;
            case 6: search(); break;
            case 7: freeall(); return;
        }
    }
}
