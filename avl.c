#include<stdio.h>

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
    if(left == null){
        l=0;
    }else{
        l = left->height;
    }
    if(right == null){
        r=0;
    }else{
        r = right->height;// 1
    }

    return (l > r)?l:r;

}

struct Node* insert(struct Node *root,int key){ //50,55 | 60,55 | null,55
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
            //50->right = insert(60,65)


    }else{
        return root;
    }

    root->height = 1 + max( root->left,root->right );

    //balance factor
};


void main(){
    struct Node *root = NULL;

     root  = insert(root,50); // root->50
     root = insert(root,60); //
     root = insert(root,70); //root->50 , 70
     root = insert(root,55);//root->50 , 55
}
