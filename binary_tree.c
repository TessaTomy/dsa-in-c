#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
    int data;
    struct Tree* left,*right;
}tree;

// Static queue implementation for BFS traversal
#define MAX 100
tree* q[MAX];
int f=-1,r=-1;

// Enqueue a tree node
void nq(tree* nnode)
{
    if(r==MAX-1)
        return;
    if(f==-1)
        f=0;
    q[++r]=nnode;
}

// Dequeue a tree node
tree* dq()
{
    if(f==-1)
        return NULL;
    return q[f++];
}

// Check if queue is empty
int isEmpty()
{
    return (f>r);
}

tree* root=NULL;

// Creates a new tree node with user input and optional left/right children
tree* createNode()
{
    int c;
    tree* nnode=malloc(sizeof(tree));
    printf("Data : ");
    scanf("%d",&nnode->data);
    nnode->left=nnode->right=NULL;
    printf("Do want to add left Child to %d (0/1):",nnode->data);
    scanf("%d",&c);
    if(c==1)
        nnode->left=createNode();
    printf("Do want to add right Child to %d (0/1):",nnode->data);
    scanf("%d",&c);
    if(c==1)
        nnode->right=createNode();
    return nnode;
}

void create()
{
    root=createNode();
}

// Inserts a new node at the first available position (level-order)
void insert(){
    tree* Newnode=malloc(sizeof(tree));
    printf("Data : ");
    scanf("%d",&Newnode->data);
    Newnode->left=Newnode->right=NULL;
    
    f=r=-1;
    if(!root)
    {
        root=Newnode;
        return;
    }
    nq(root);
    while(!isEmpty())
    {
        tree* nnode=dq();
        if(nnode->left)
            nq(nnode->left);
        else
        {
            nnode->left=Newnode;
            return;
        }
        if(nnode->right)
            nq(nnode->right);
        else
        {
            nnode->right=Newnode;
            return;
        }
    }
}

void inorder(tree* root){
    if(!root)
        return;
    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
}
void preorder(tree* root){
    if(!root)
        return;
    printf("%d->",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(tree* root){
    if(!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d->",root->data);
}

// Finds a node with the given value using DFS
tree* findNode(tree* root,int pos)
{
    if(!root)
        return NULL;
    if(pos==root->data)
        return root;
    tree* left= findNode(root->left,pos);
    if(left)
        return left;
    return findNode(root->right,pos);
}

// Finds the deepest node in the tree using BFS
tree* findDeepest()
{
    f=r=-1;
    if(!root)
        return NULL;
    nq(root);
    tree* nnode;
    while(!isEmpty())
    {
        nnode=dq();
        
        if(nnode->left)
            nq(nnode->left);
        if(nnode->right)
            nq(nnode->right);
    }
    return nnode;
}

// Deletes the deepest node from the tree
void delDeep(tree* deep,tree* root)
{
    if(!root)
        return;
    if(deep==root->left)
    {
        root->left=NULL;
        free(deep);
        return;
    }
    if(deep==root->right)
    {
        root->right=NULL;
        free(deep);
        return;
    }
    delDeep(deep,root->left);
    delDeep(deep,root->right);
}

// Deletes a node by replacing with deepest or restructuring
void del(){
    int pos;
    printf("Deletion Element :");
    scanf("%d",&pos);
    tree* nnode=findNode(root,pos);
    if(!nnode)
        printf("Not Found !!");
    else if(nnode->left && nnode->right)
    {
        tree* deep=findDeepest();
        nnode->data=deep->data;
        delDeep(deep,root);
    }
    else if(nnode->left)
    {
        tree* temp=nnode->left;
        nnode->data=temp->data;
        nnode->left=temp->left;
        nnode->right=temp->right;
        free(temp);
    }
    else if(nnode->right)
    {
        tree* temp=nnode->right;
        nnode->data=temp->data;
        nnode->left=temp->left;
        nnode->right=temp->right;
        free(temp);
    }
    else
        delDeep(nnode,root);
}


void bsf(){
    f=r=-1;
    if(!root)
        printf("Empty Tree !!");
    nq(root);
    while(!isEmpty())
    {
        tree* nnode=dq();
        printf("%d->",nnode->data);
        if(nnode->left)
            nq(nnode->left);
        if(nnode->right)
            nq(nnode->right);
    }
}
int main() {
    
    while(1)
    {
        int c;
        printf("\n1.Create\n2.Insert\n3.Delete\n4.Preorder\n5.Postorder\n6.Inorder\n7.BSF:");
        scanf("%d",&c);
        if(c==1)
            create();
        else if(c==2)
            insert();
        else if(c==3)
            del();
        else if(c==4)
            preorder(root);
        else if(c==5)
            postorder(root);
        else if(c==6)
            inorder(root);
        else if(c==7)
            bsf();
        else
            exit(0);
    }
    return 0;
}
