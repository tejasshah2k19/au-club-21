#include<stdio.h>

struct node {
    int data;
   struct node *left,*right;
};


struct node* smallestNode(struct node* node){

    while(node->left != NULL){
        node = node->left;
    }
    return node;
};


struct node* deleteNode(struct node* root,int key){  //100,500  200,500
    struct node* tmp;
    if(root==NULL){
        printf("\n....Invalid tree...or...Invalid key\n");
        return root;
    }

    if(key < root->data){
        //left
        root->left = deleteNode(root->left,key);
    }else if(key > root->data){
        //right
        root->right = deleteNode(root->right,key); //100->right = delete(200,500) , 200->right = delete(250,500)
                                                //250->right = delete(300,500)
                                                //300-->right = delete(500,500)

    }else if(key == root->data){
        //key found
        // 0 child
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }else if(root->left == NULL){
                //1 child right is present
                 tmp = root->right;
                 free(root);
                 return tmp;
        }else if(root->right == NULL){
            //1 child left
            tmp = root->left;
            free(root);
            return tmp;
        }else{
                //2 child


        }



    }

};

struct node* createNode(struct node *root,int key){

        if(root == NULL){
            root = (struct node*)malloc(sizeof(struct node));
            root->data = key;
            root->left = NULL;
            root->right= NULL;
        }else if(key < root -> data){
            //left  [key <  ]
            root->left = createNode(root->left,key); // 100->left
        }else if(key > root->data){
        //right [ key > ]
            root->right = createNode(root->right,key);
        }

        return root;
    }

void inorder(struct node *root){


    if(root != NULL){ //100root 200root
        inorder(root->left); // inorder(100->left) inorder(80->left) inorder(200->left)
        printf("%d ",root->data); //80 100  200
        inorder(root->right);//80->right 100->right 200->right
    }
}

void preorder(struct node *root){//100

    if(root != NULL){
        printf("%d ",root->data); //80 100 200
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(struct node *root){//100

    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data); //80 100 200
    }
}

int search(struct node *root,int key){
    if(root != NULL){
        if(root->data == key){
            return 1;
        }else if(key > root->data){
            search(root->right,key);
        }else if(key < root -> data){
            search(root->left,key);
        }
    }else{
       return 0;
    }

}
void main(){
    int searchKey = 50;
    struct node *root = NULL;
  //  root = createNode(root,100);
    //       createNode(root,80);
      //     createNode(root,200);
           //inorder(root); // asc order
            //preorder(root);
        //    postorder(root);
    //inorder --> first print all left child then root then right child
    //preorder --> root --> left -> right
    //postorder --> left -> right -> root


     root = createNode(root,100);
           createNode(root,80);
           createNode(root,200);
           createNode(root,70);
           createNode(root,90);
           createNode(root,150);
           createNode(root,250);
            createNode(root,300);
            createNode(root,60);
            createNode(root,270);
            printf("\nTree Data : \n");
            inorder(root);
    /*
                        100
                80             200
             70    90     150      250
           60                            300
                                    270
    */
            //deleteNode(root,60); // 0 child
            //deleteNode(root,250);//1 child right
             //   deleteNode(root,70);//1 child left
           deleteNode(root,80);
            printf("\nTree Data : \n");
            inorder(root);
    /*

        if( search(root,searchKey) == 1){
            printf("\n%d present",searchKey);
        }else{
            printf("\n%d not present",searchKey);

        }*/
}
