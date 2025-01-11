#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next ;
};
struct Node* create(int data){
    struct Node * new = (struct Node*)malloc(sizeof(struct Node));
    new ->data = data;
    new -> next =NULL;
    return new;
}
struct Node *build(int n){
    struct Node *head = NULL, *temp = NULL, *current = NULL;
    int value ;
    for  (int i = 0; i<n; i++){
        printf("enter the node %d \n", i+1);
        scanf("%d", &value);
        temp = create(value);
        if(head == NULL){
            head = temp;
        }
        else {
            current -> next = temp;
        }
        current = temp;
    } 
    return head;
}
void traverse (struct Node*ptr){
    while(ptr != NULL){
        printf("Elemnts %d \n", ptr->data);
        ptr = ptr -> next;
}
}
struct Node* insertatfirst(int data, struct Node*head){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> next = head;
    ptr -> data = data;
    return ptr;
}
struct Node * insertatnext(struct Node *head, int data , int position){
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node *p= head;
    int i =0;
    while(i != position - 1 ){
        p= p ->next;
        i++;
    }
    ptr -> data = data;
    ptr -> next = p-> next;
    p-> next = ptr;
    return head;
}
struct Node*insertatend(struct Node*head, int data){
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node*p = head ;
    while (p ->next != NULL){
        p = p-> next;
    }
    ptr ->data = data;
    p ->next = ptr;
    ptr -> next = NULL;
    return head ;
}
int main(){
    int n;
    printf("enter the number of elements ");
    scanf("%d", &n);
    struct Node*head = build(n);
    traverse(head);
    printf("\n");
    head = insertatfirst(34, head);
    traverse(head);
    printf("\n");
    insertatnext(head, 89, 2);
    traverse(head);
    printf("\n");
    head = insertatend(head , 78);
    traverse(head);
    return 0;
}
