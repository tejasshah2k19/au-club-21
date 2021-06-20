#include<stdio.h>

struct node {
    int data;//
    struct node *next;//
}*head=NULL,*lastNode=NULL;
// head is null = link list empty
// node ->next = null -> node last
void insertNode(){
    int num;
    struct node *tmp;
    printf("enter number");
    scanf("%d",&num);//10 12 20

    if(head == NULL){
            head  = (struct node*) malloc(sizeof(struct node));
            head->data = num;
            head->next = NULL;
            lastNode = head;
    }else{
            tmp  = (struct node*) malloc(sizeof(struct node));
            tmp->data= num;
            tmp->next = NULL;
            lastNode -> next = tmp;
            lastNode = tmp;
    }
}

void insertAnyBefore(){
    int dest,isFound=0,num;
    struct node *p,*q,*s;

    printf("Enter Node  before you want to add");
    scanf("%d",&dest);

    p = head;
    while(p!=NULL)
    {
        if(p->data == dest){
            isFound = 1;
            break;
        }
        p=p->next;
    }

    if(isFound == 0){
        printf("\nInvalid Node");
    }else{
            printf("\nEnter new node");
            scanf("%d",&num);

            if(p == head){
                insertAtBeg(num);
                return;
            }
            q = (struct node*)malloc(sizeof(struct node));

            q->data=num;

            s= head;
            while(s->next!=p){
                s=s->next;
            }

            s->next = q;
            q->next = p;

    }
}


void insertAtBeg(int num){

    struct node *p;
    p    = (struct node*)malloc(sizeof(struct node));
    p->data = num;
    p->next = head;
    head =p;
}


void display(){
    struct node *p;
    p =head;

    while(p!=NULL){
        printf("%d->",p->data);
        p = p->next;
    }
}
void main(){
    int num;
    insertNode(); //10
    insertNode(); //12
    insertNode(); //20
    insertNode(); //25
    insertAnyBefore();
    display();
    insertAnyBefore();
    display();


}
