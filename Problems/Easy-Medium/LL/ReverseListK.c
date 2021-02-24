// Given a LL, reverse it recursively

// i/p - 1->2->3->4->5
// o/p - 5<-4<-3<-2<-1

#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* link;
};

struct node* head_new = NULL;
struct node* reverseList(struct node* head) {

struct node *next_node;
struct node* temp = head;

if (temp->link == NULL)
{
  head_new = temp;
  return NULL;
}

next_node = temp->link;
reverseList(next_node);
next_node->link = temp;
temp->link = NULL;
return head_new;
}

void Insert(int data, struct node **head) {
  struct node* temp = (struct node *)malloc(sizeof(struct node));
  temp->data = data;
  temp->link = NULL;

  if(*head == NULL) {
    *head = temp;
    return;
  }
  struct node * temp1 = *head;
  while (temp1->link !=NULL)
  {
    temp1 = temp1->link;
  }
  temp1->link = temp;

}

void Print(struct node *head) {
  while(head!=NULL) {
    printf("%d\n", head->data);
    head = head->link;
  }
}


int main() {

  struct node * head = NULL;
  struct node * res;
  int n, num, k, elem;
  printf("Enter the no of elements in list: \n");
  scanf("%d", &n);
  printf("Enter the elements in list: \n");
  for(int i = 0; i<n;i++) {
    scanf("%d", &num);
    Insert(num, &head);
  }
  printf("The List is: \n");
  Print(head);
  res = reverseList(head);
  Print(res);
     
}

