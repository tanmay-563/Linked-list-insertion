#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next ;
};
void traverse (struct Node*ptr){
    while(ptr != NULL){
        printf("elemnts %d \n", ptr->data);
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
    struct Node * head ;
        struct Node * second ;
            struct Node * third ;
    head = (struct Node *)malloc (sizeof(struct Node));
    second = (struct Node *)malloc (sizeof(struct Node));
    third = (struct Node *)malloc (sizeof(struct Node));
    head -> data = 7;
    head -> next = second;
    second -> data = 77;
    second -> next = third;
    third -> data = 777;
    third -> next = NULL;
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
