#include <stdio.h>
#include <stdlib.h>

struct cdll {
    int data;
    struct cdll* next;
    struct cdll* prev;
};

typedef struct cdll* node;

node start = NULL;
int count = 0;

int isempty() {
    return (start == NULL);
}

node read() {
    node nnode = malloc(sizeof(struct cdll));
    printf("Data : ");
    scanf("%d", &nnode->data);
    nnode->next = nnode->prev = NULL;
    count++;
    return nnode;
}

void insertb() {
    node nnode = read();
    if (isempty()) {
        start = nnode;
        start->next = start->prev = start;
    } else {
        nnode->next = start;
        nnode->prev = start->prev;
        start->prev->next = nnode;
        start->prev = nnode;
        start = nnode;
    }
}


void insert(int pos) {
    if (pos == 1) {
        insertb();
        return;
    }
    
    node nnode = read();
    node temp = start;
    for (int c = 1; c < pos - 1; c++)
        temp = temp->next;

    nnode->next = temp->next;
    nnode->prev = temp;
    temp->next->prev = nnode;
    temp->next = nnode;
}

void forwardTraverse() {
    printf("Forward Traversal: ");
    if (isempty()) {
        printf("NULL\n");
        return;
    }

    node temp = start;
    for (int i = 0; i < count; i++,temp = temp->next) {
        printf("%d <-> ", temp->data);
    }
}

void backwardTraverse() {
    printf("Reverse Traversal: ");
    if (isempty()) {
        printf("NULL\n");
        return;
    }

    node temp = start->prev;
    for (int i = 0; i < count; i++,temp = temp->prev) {
        printf("%d <-> ", temp->data);
    }
}

void create() {
    int c = 1;
    while (c) {
        insert(count+1);
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
        insert(pos);
        printf("Element Inserted Successfully !!\n");
        forwardTraverse();
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

    node temp = start;
    for (int c = 1; c < pos; c++,temp = temp->next);

    if (count == 1) {
        start = NULL;
        
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        if (temp == start)
            start = temp->next;
    }

    free(temp);
    count--;
    printf("Element Deleted Successfully !!\n");
    forwardTraverse();
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
        printf("\n=========================\nEnter Your Choice :\n1.Create\n2.Insert\n3.Delete\n4.Forward Traverse\n5.Backward Traverse\n6.Count\n7.Search\n8.Exit\n?: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: create(); break;
            case 2: insertNode(); break;
            case 3: del(); break;
            case 4: forwardTraverse(); break;
            case 5: backwardTraverse(); break;
            case 6: printf("Total number of nodes = %d\n", count); break;
            case 7: search(); break;
            case 8: freeall(); return;
        }
    }
}
