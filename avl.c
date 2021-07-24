#include<stdio.h>
#include<stdlib.h>
struct Node{

    int key;
    struct Node *left;
    struct Node *right;
    int height;

};


struct Node* createNode(int key){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key; //20
    node->left=NULL;
    node->right=NULL;
    node->height=1;

    return node;
};

int max (struct Node *left,struct Node *right){ //null , 60
    int l,r;
    if(left == NULL){
        l=0;
    }else{
        l = left->height;
    }
    if(right ==NULL){
        r=0;
    }else{
        r = right->height;// 1
    }

    return (l > r)?l:r;

}


int getBf(struct Node *root){
    int l,r;

    if(root->left == NULL){
        l=0;
    }else{
        l = root->left->height;
    }


    if(root->right == NULL){
        r=0;
    }else{
        r = root->right->height;// 1
    }

    return l-r;
}

struct Node* getParent(struct Node *root,int key){

}

struct Node* leftRotate(struct Node *x){

        struct Node *y = x->right;
        struct Node *yl = y->left;

        y->left = x;
        x->right=yl;

        x->height = 1 + max( x->left,x->right );
        y->height = 1 + max( y->left,y->right );

}



struct Node* rightRotate(struct Node *x){

        struct Node *y = x->left;
        struct Node *yr = y->right;

        y->right = x;
        x->left=yr;

        x->height = 1 + max( x->left,x->right );
        y->height = 1 + max( y->left,y->right );

}




struct Node* insert(struct Node *root,int key){ //50,70   60,70
    int balance;
    struct Node *parent;
    if(root == NULL){

        return createNode(key);//height = 1
    }

    if(key < root->key ){
        //left
        root->left  = insert(root->left,key);
        //60->left = 55
    }
    else if(key > root->key){
            //right
            root->right = insert(root->right,key); // 30->right 60->right  70->right [80
            //50->right = insert(60,70)
            //60->right = 70

    }else{
        printf("\nInvalid");
        return root;
    }

    root->height = 1 + max( root->left,root->right );
    //balance factor


    balance = getBf(root);//50 -> -1

            //R
   // parent  = getParent(root,key);

    if( balance < -1 && key > root->right->key){
        //RR
        printf("RR");
        return leftRotate(root);
    }else if(balance < -1 && key < root->right->key){
        //RL
        printf("RL");
        root->right= rightRotate(root);
        return leftRotate(root);
    }else if(balance > 1 && key < parent->key){
        //LL
        printf("LL");
        return rightRotate(root);
    }else if(balance >  1 && key > root->left->key){
        //LR
        printf("LR");
        root -> left = leftRotate(root);
        return rightRotate(root);
    }else{
        printf("\nBal = %d for %d with %d ",balance,root->key,key);
    }

    return root;
};
void preOrder(struct Node *root){

    if(root != NULL){
        printf(" %d",root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void main(){
    struct Node *root = NULL;
    /*
     root  = insert(root,50); // root->50
     root = insert(root,60); //
     root = insert(root,70); //root->50 , 70
     root = insert(root,55);//root->50 , 55
    */

        root=insert(root,50);
        root= insert(root,45);

             root= insert(root,60);
             root= insert(root,55);
            root=  insert(root,70);
             root= insert(root,65);

            printf("\n\n");
            preOrder(root);
}
