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

int MiddleElem(struct node *head) {

 struct node *p,*q;
 p=q=head;
 while ((q->link!=NULL) && (q->link->link !=NULL))
 {
    p = p->link;
    q = q->link->link;
 }
return p->data;
 
}

void EvenOddList(struct node* head) {
  while(head!=NULL)
  {
     if (head->link == NULL)
     {
        printf("Odd list");
        return;
     }
     else if(head->link->link == NULL) {
        printf("Even list");
        return;
     }
     else{
        head = head->link;
     }
     
  }

  return;
  
}


int main() {

  struct node * head = NULL;
  int n, num, k, elem, mid_elem;
  printf("Enter the no of elements in list: \n");
  scanf("%d", &n);
  printf("Enter the elements in list: \n");
  for(int i = 0; i<n;i++) {
    scanf("%d", &num);
    Insert(num, &head);
  }
  printf("The List is: \n");
  Print(head);
  EvenOddList(head);
//   printf("The middle element is: \n");
//   mid_elem = MiddleElem(head);
//   printf("%d",mid_elem);
//   Print(head);

     
}