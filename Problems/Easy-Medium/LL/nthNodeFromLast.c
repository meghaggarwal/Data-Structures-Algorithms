// Given a linked list find nth element from last

#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* link;
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

int findNElement(struct node* head , int k) {

  if (head == NULL | k < 1)
  {
    return -1;
  }
  
  struct node * p = head;
  struct node *q = head;
  while(k-1 >= 1 & q!=NULL) {
    q = q->link;
    k-=1;
  }

  if (q ==NULL)
  {
    return -1;
  }
  
  while(q->link != NULL) {
    p = p->link;
    q = q->link;
  }

  return p->data;

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
  printf("Enter nth element: \n");
  scanf("%d", &k);
  elem = findNElement(head, k);
  printf("Nth element from last of LL is :\n");
  printf("%d", elem);
  return 0;
}