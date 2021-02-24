#include<stdio.h>
#include<stdlib.h>

struct node {
   int data;
   struct node *link;
};

void lastLink(struct node *head) {

  struct node* temp = head;

  while(temp->link !=NULL) 
  {

    temp = temp->link;
    // printf("%d\n", temp->data);

  }

 temp->link = head;
}

void Insert(int data, struct node **head) 
{

  struct node* temp = (struct node *)malloc(sizeof(struct node));
  temp->data = data;
  temp->link = NULL;

  if(*head == NULL) 
  {
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

void Print(struct node *head) 
{

  while(head!=NULL)
  {
    printf("%d\n", head->data);
    head = head->link;
  }
}

int removeLoop(struct node*p , struct node * q, struct node* head, struct node * prev) {

p = head;
while(p!=NULL && q!=NULL) 
{
  if(p==q) {
    prev->link = NULL;
    return p->data;
  }
  prev = q;
  p= p->link;
  q= q->link;

} 
}

int findLenLoop(struct node* p, struct node * q) {

  q = q->link;
  int counter = 1;
  while(p != q) {
    q = q ->link;
    counter +=1;
  }

  return counter;

}

int findLoop(struct node* head) {

  struct node*p,*q,*prev;
  int startloop;
  p=q=head;
  while(p &&  q && q->link) {

    prev = p;
    p = p->link;
    q = q->link->link;
 
    if(p==q) {
      
      printf("Length of loop is  %d\n", findLenLoop(p, q));
      printf("Loop exists:\n");
      startloop = removeLoop(p, q, head, prev);
      return startloop;
    }
  }
  printf("No loop exists:\n");
  return -1;
}

int main() {

  struct node * head = NULL;
  int n, num, k, elem, loop_elem;
  printf("Enter the no of elements in list: \n");
  scanf("%d", &n);
  printf("Enter the elements in list: \n");
  for(int i = 0; i<n;i++) {
    scanf("%d", &num);
    Insert(num, &head);
  }
  printf("The List is: \n");
  Print(head);
  lastLink(head);
  loop_elem = findLoop(head);
  printf("Starting point of loop: %d\n",loop_elem);
  findLoop(head);
  Print(head);
  
     
}