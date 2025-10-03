#include<stdio.h>
#include<stdlib.h>

typedef struct Tree
{
    struct Tree* left,*right;
    int data;
}node;

node* root=NULL;

//bst insertion logic
node* appendNode(node* nnode,node* root)
{
    if(!root)
        return nnode;
    else if(root->data>nnode->data)
        root->left=appendNode(nnode,root->left);
    else
        root->right=appendNode(nnode,root->right);
    return root;
}

void createNode(int val)
{
    node* nnode=malloc (sizeof(node)); 
    nnode->data=val;
    nnode->left=nnode->right=NULL;
    root=appendNode(nnode,root);
}

void create(){
    int val;
    root=NULL;
    printf("Enter values to insert (press -1 to stop) : ");
    while(1)
    {
        scanf("%d",&val);
        if(val==-1)
            return;
        createNode(val);
    }
}

void insert(){
    int val;
    printf("Value ?: ");
    scanf("%d",&val);
    createNode(val);
}

void preorder(node* root){
    if(!root)
        return;
    printf("%d->",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d->",root->data);
}

void inorder(node * root){
    if(!root)
        return;
    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
}

void bsf(){
    node* queue[50];
    int f=0,r=-1;
    queue[++r]=root;
    while(f<=r)
    {
        node* temp=queue[f++];
        printf("%d->",temp->data);
        if(temp->left)
            queue[++r]=temp->left;
        if(temp->right)
            queue[++r]=temp->right;
    }
}

// to search for node to delete
node* findNode(int val, node* root) {
    if (!root)
        return NULL;
    if (root->data == val)
        return root;
    node* result = NULL;
    if (val < root->data)
        result = findNode(val, root->left);
    else
        result = findNode(val, root->right);
    return result;
}

//finds Leftmost node in right subtree
node* findInorderSuccessor(node* root){
    if(!root)
        return NULL;
    if(!root->left)
        return root;
    return findInorderSuccessor(root->left);
}

// handle deletion of nodes with 0 or 1 child

void discard(node* del) {
    if (!root || !del)
        return;

    node* queue[50];
    int f = 0, r = -1;
    queue[++r] = root;

    while (f <= r) {
        node* temp = queue[f++];

        if (temp->left == del) {
            temp->left = (del->left) ? del->left : del->right;
            free(del);
            return;
        } else if (temp->right == del) {
            temp->right = (del->left) ? del->left : del->right;
            free(del);
            return;
        }

        if (temp->left)
            queue[++r] = temp->left;
        if (temp->right)
            queue[++r] = temp->right;
    }
}

void del(){
    int v;
    printf("Enter value to delete : ");
    scanf("%d",&v);
    node* toDelete=findNode(v,root);
    if(!toDelete)
        printf("Value not found !!");
    else if(toDelete->left&&toDelete->right)
    {
        node* temp=findInorderSuccessor(toDelete->right);
        toDelete->data=temp->data;
        discard(temp);
    }    
    else
        discard(toDelete);
}

void main()
{
    int n;
    while(1)
    {
        printf("\nEnter your choice :\n1.Create Tree\n2.Insert Value\n3.Inorder Traversal\n4.Preorder Traversal\n5.Postorder Traversal\n6.BSF\n7.Delete\n8.Exit\nChoice ?:");
        scanf("%d",&n);
        switch(n)
        {
            case 1:create();break;
            case 2:insert();break;
            case 3:inorder(root);break;
            case 4:preorder(root);break;
            case 5:postorder(root);break;
            case 6:bsf();break;
            case 7:del();break;
            case 8:return;
        }
    }
}
