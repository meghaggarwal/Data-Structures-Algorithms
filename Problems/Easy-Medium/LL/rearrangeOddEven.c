#include<stdio.h>
#include<stdlib.h>


struct node {

  int data;
  struct node* link;
};

struct node* prev_even = NULL;
struct node* prev_odd = NULL;
struct node* even_head = NULL, *odd_head = NULL;
struct node* evenInsert(struct node* head) {

  if(even_head==NULL) {
    prev_even = head;
    even_head = head;
    return prev_even;
  }
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = head->data;
  prev_even->link = new_node;
  prev_even = new_node;
  return prev_even;

}

struct node* oddInsert(struct node* head) {

  if(odd_head==NULL) {
    prev_odd = head;
    odd_head = head;
    return odd_head;
  }
  struct node* new_node = (struct node*)malloc(sizeof(struct node));
  new_node->data = head->data;
  prev_odd->link = new_node;
  prev_odd = new_node;

}

struct node* rearrange(struct node* head) {
  int counter = 1;
  struct node* temp = head;
  while(temp!=NULL) {
  
   if(counter%2==0) {
     prev_even = evenInsert(temp);
   }

   else {

     oddInsert(temp);
   }
 counter++;
 temp = temp->link;
  }

  if(prev_even!=NULL) {
  prev_even->link = NULL;
  prev_odd->link = even_head;
  }
  return odd_head;
}



void Insert(int data, struct node **head) 
{
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
  res = rearrange(head);
  Print(res);
     
}