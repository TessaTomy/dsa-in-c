#include <stdio.h>
#include <stdlib.h>

struct dll {
    int data;
    struct dll* next;
    struct dll* prev;
};

typedef struct dll* node;

node start = NULL;
node end = NULL;
int count = 0;

int isempty() {
    return (!start) ? 1 : 0;
}

node read() {
    node nnode = malloc(sizeof(struct dll));
    printf("Data : ");
    scanf("%d", &nnode->data);
    nnode->next = nnode->prev = NULL;
    count++;
    return nnode;
}

void insertb() {
    node nnode = read();
    if (isempty()) {
        start = end = nnode;
    } else {
        nnode->next = start;
        start->prev = nnode;
        start = nnode;
    }
}

void insert_end() {
    node nnode = read();
    if (isempty()) {
        start = end = nnode;
    } else {
        end->next = nnode;
        nnode->prev = end;
        end = nnode;
    }
}

void insert(int pos) {
    if (pos == count + 1) {
        insert_end();
        return;
    }

    node nnode = read();
    node temp = start;
    int c;

    for (c = 1; c < pos - 1 && temp != NULL; c++,temp = temp->next);

    nnode->next = temp->next;
    nnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = nnode;

    temp->next = nnode;
}

void forwardTraverse() {
    printf("Forward Traversal: ");
    for (node temp = start; temp != NULL; temp = temp->next)
        printf("%d <-> ", temp->data);
    printf("NULL\n");
}

void backwardTraverse() {
    printf("Reverse Traversal: ");
    for (node temp = end; temp != NULL; temp = temp->prev)
        printf("%d <-> ", temp->data);
    printf("NULL\n");
}

void create() {
    int c = 1;
    while (c) {
        insert_end();
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
    int c = 1;

    while (c < pos && temp != NULL) {
        temp = temp->next;
        c++;
    }

    if (temp == NULL) return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        start = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        end = temp->prev;

    free(temp);
    count--;
    printf("Element Deleted Successfully !!\n");
    forwardTraverse();
}

void search() {
    if (!start) {
        printf("Linked List is Empty !!\n");
        return;
    }

    int key, pos = 1;
    printf("Enter value to search: ");
    scanf("%d", &key);

    for (node temp = start; temp != NULL; temp = temp->next, pos++) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
    }

    printf("Element %d not found in the list\n", key);
}

void freeall() {
    node next = start, p;
    while (next != NULL) {
        p = next;
        next = p->next;
        free(p);
    }
    start = end = NULL;
    count = 0;
}

void main() {
    while (1) {
        int choice;
        printf("\n=========================\nEnter Your Choice :\n1.Create\n2.Insert\n3.Delete\n4.Forward Traverse\n5.Backward Traverse\n6.Count\n7.Search\n8.Exit\n?: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: create(); 
                    break;
            case 2: insertNode(); 
                    break;
            case 3: del(); 
                    break;
            case 4: forwardTraverse(); 
                    break;
            case 5: backwardTraverse(); 
                    break;
            case 6: printf("Total number of nodes = %d\n", count);     break;
            case 7: search(); 
                    break;
            case 8: freeall(); 
                    return;
        }
    }
}
