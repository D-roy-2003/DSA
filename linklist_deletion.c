#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void traversal(struct node* ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

struct node* deleteatbegin(struct node* head)
{
    struct node* ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

struct node* deletebetween(struct node* head, int index)
{
    struct node* p=head;
    struct node* q=head->next;
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

struct node* deleteatend(struct node* head)
{
    struct node* p=head;
    struct node* q=head->next;
    while(q->next!=NULL)
    {
    p=p->next;
    q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

struct node* deleteatval(struct node* head, int  element)
{
    struct node* p=head;
    struct node* q=head->next;
    while(q->next!=NULL && q->data!=element)
    {
        p=p->next;
        q=q->next;
    }
    if(q->data==element)
    {
        p->next=q->next;
        free(q);
    }
    return head;
}

int main()
{
struct node* head=(struct node* )malloc(sizeof(struct node));
struct node* first=(struct node* )malloc(sizeof(struct node));
struct node* second=(struct node* )malloc(sizeof(struct node));
struct node* third=(struct node* )malloc(sizeof(struct node));
struct node* fourth=(struct node* )malloc(sizeof(struct node));
    
head->data=10;
head->next=first;

first->data=20;
first->next=second;

second->data=30;
second->next=third;

third->data=40;
third->next=fourth;

fourth->data=50;
fourth->next=NULL;

printf("\nGiven linked list before deletion:");
traversal(head);
// head=deleteatbegin(head);
// head=deleteatend(head);
// head=deletebetween(head, 3);
head=deleteatval(head, 20);
printf("\nGiven linked list after deletion:");
traversal(head);
return 0;
}