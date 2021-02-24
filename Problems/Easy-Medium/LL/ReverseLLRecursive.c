// Given a LL, reverse it in size of k

// i/p - 1->2->3->4->5->6->7->8

// o/p - 3->2->1->6->5->4->8->7

#include<stdio.h>
#include<stdlib.h>

struct node {

  int data;
  struct node *link;
};

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

struct node *reverseListGroup(struct node * head, int k) {

int count = 0;
struct node* head_node = head;
struct node *next_node, *prev = NULL;
while(head!=NULL && count < k)
 {

   next_node = head->link;
   head->link = prev;
   prev = head;
   head = next_node;
   count++;
   
}
  if(head!=NULL) {
  head_node->link = reverseListGroup(head, 3);

  }

  return prev;

}

int main() {

  struct node * head = NULL;
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
  head = reverseListGroup(head, 3);
  Print(head);

}