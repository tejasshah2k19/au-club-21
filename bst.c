#include<stdio.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node* createNode(int data){
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data=  data;
    tmp->left  = NULL;
    tmp->right = NULL;
    return tmp;
}



struct node* insertNode(struct node* node,int data){
        if ( node == NULL){
            return createNode(data);//40
        }

        if (data < node -> data){
            node->left = insertNode(node->left,data);
        }else if(data > node -> data){
            node->right = insertNode(node->right,data);
        }
        return node;
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("  %d",root->data);
        inorder(root->right);
    }
}

struct node* deleteNode(struct node* root,int key){ //100 7
    struct node* tmp=NULL;
    struct node* tmp2=NULL;
    if(root == NULL){
        printf("\n%d not found",key);
        return root;
    }

    if(key < root->data){ //65
       root->left =  deleteNode(root->left,key); //25,7->NULL

    }else if(key > root->data){//65
       root->right =  deleteNode(root->right,key);
    }else if(key == root->data){
            //1 -- zero child
            if(root->left == NULL &&  root->right == NULL){
                free(root);
                return NULL;
            }

            //2 -- one child
            else if(root->left == NULL  ){
                     struct node* tmp = root->right;
                     free(root);
                    return tmp;
            }else if(root->right == NULL){
                    struct node* tmp = root->left;
                    free(root);
                    return tmp;

            }else{
                    //3 -- two child
                    //pre --> left --> highest
                    //succ ---> right --> lowest

                     tmp = root->right; //root 53  tmp 55
                     tmp2=tmp; // 55
                     while(tmp->left != NULL ){
                        tmp2= tmp;//54
                        tmp=tmp->left;//53

                     }
                     //tmp
                     root->data = tmp->data;
                     root->right = deleteNode(root->right,tmp->data);//

            }


    }

    return  root;
}

int main(){
    struct node* root = NULL;
    root =  insertNode(root,50);
    insertNode(root,45);
    insertNode(root,40);
    insertNode(root,46);
    insertNode(root,70);
    insertNode(root,65);
    insertNode(root,85);

    printf("\nTree Data : ");
    inorder(root);
    deleteNode(root,45);

    printf("\nTree Data : ");
    inorder(root);


    return 0;

}
/*
            50
    45           70
  40   46      65    85
//90
*/
