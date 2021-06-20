
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node* newNode(int item)
{
    struct node* temp
        = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}


/* A utility function to insert
   a new node with given key in
 * BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}
//0 not found
//1 found

int search(struct node* node , int key){
        if (node == NULL)
            return 0;
        if(node->key == key)
            return 1;
        else if (key < node->key)
            return search(node->left,key);
        else if (key > node->key)
            return search(node->right,key);

}

void inorder(struct node* root){
        if(root != NULL){
            inorder(root->left); //50->right
            printf("  %d",root->key);
            inorder(root->right);
        }
}
//20 30 50 60 70 80

void preorder(struct node* root){
        if(root != NULL){
            printf("  %d",root->key);
            preorder(root->left); //50->right
            preorder(root->right);
        }
}


void postorder(struct node* root){
        if(root != NULL){
            postorder(root->left); //50->right
            postorder(root->right);
            printf("  %d",root->key);
        }
}


// Driver Code
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 70);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
   // insert(root,25);

    printf("\nSearch 70 => %d",search(root,70));
    printf("\nSearch 75 => %d",search(root,75));
    printf("\nSearch 80 => %d",search(root,80));
    printf("\nSearch 100 => %d",search(root,100));

    printf("\n\n");

    //inorder(root);
    //preorder(root);
    postorder(root);
    return 0;
}
