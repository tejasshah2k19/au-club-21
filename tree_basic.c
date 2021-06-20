#include<stdio.h>
#include<conio.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* addNode(int data){

    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right= NULL;

    return node;

}

void main(){

    struct node *root = NULL;
    root = addNode(20);
    root->left = addNode(10);
    root->right =addNode(30);

}
