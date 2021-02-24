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
     
}


Given a LL with random pointers, clone this LL with random pointers
Proof of Floyd cycle algorithm
Palindrome reverse a LL.
add two no's and return as LL.



