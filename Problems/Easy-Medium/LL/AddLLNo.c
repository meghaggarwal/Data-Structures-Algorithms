#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node * link;
};

int getEqualList(struct node *head1, struct node* head2);
int getlenList(struct node *head);
int addElementList(struct node* head1, struct node* head2 , int diff);

int getEqualList(struct node *head1, struct node* head2) {

int temp;
int l1, l2, diff;
l1 = getlenList(head1);
l2 = getlenList(head2);
if(l1>l2) {
  diff = l1 -l2;
  temp = addElementList(head1, head2 , diff);
}
else {
  diff = l2 - l1;
  temp = addElementList(head2, head1, diff);
}

}

int getlenList(struct node *head) {

  int counter = 0;
  if(head==NULL) {
    return 0;
  }
  while(head->link) {
 
  head = head->link;
  counter++;

  }

  return counter;
}

int addElementList(struct node* head1, struct node* head2 , int diff) {

struct node* temp1, *temp2;
temp1 = head1;

while(diff > 0) 
{
struct node* newnode = (struct node*)malloc(sizeof(struct node));
newnode->data = 0;
newnode->link = head2;
head2 = newnode;
diff --;
}
temp2 = head2;


int res = (temp1->data + temp2->data);

while(temp2->link!=NULL && temp1->link!=NULL){

res = res * 10 + temp1->link->data + temp2->link->data;
temp2 = temp2->link;
temp1 = temp1->link;

}

return res;
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

  struct node * head , *head2= NULL;
  int n, num, k, elem;
  printf("Enter the no of elements in first list: \n");
  scanf("%d", &n);
  printf("Enter the elements in list: \n");
  for(int i = 0; i<n;i++) {
    scanf("%d", &num);
    Insert(num, &head);
  }
  printf("The List is: \n");
  Print(head);

  printf("Enter the no of elements in second list: \n");
  scanf("%d", &n);
   
  printf("Enter the elements in second list: \n");
  for(int i = 0; i<n;i++) {
    scanf("%d", &num);
    Insert(num, &head2);
  }
  printf("The List is: \n");
  Print(head2);
  printf("%d\n", getEqualList(head, head2));

}