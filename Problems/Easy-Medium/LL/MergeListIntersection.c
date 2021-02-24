#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* link;
};

int findLengthList(struct node * head) {

  int counter = 0;
  while(head!=NULL) {
    counter++;
    head = head->link;
  }
  return counter;

}

int MergeElementList(struct node * head1, struct node *head2, int diff)
{
  while(diff > 0) {

    if(head1==NULL){
      return -1;
    }
    head1 = head1->link;
    diff --;
  }

while(head1 && head2){
  if(head1->link == head2->link){
    return head2->link->data;
  }
  head1 = head1->link;
  head2 = head2->link;
}
return -1;


}


int MergePointList(struct node * head1, struct node* head2) {

int l1, l2, diff;
l1 = findLengthList(head1);
l2 = findLengthList(head2);

if(l1 > l2){
  diff = l1 - l2;
  return MergeElementList(head1, head2, diff);
}

else {
  return MergeElementList(head2, head1, diff);
}
return -1;
}



int main(struct node* head1, struct node * head2) {

struct node* newNode = (struct node*)malloc(sizeof(struct node));
newNode->data = 2;
newNode->link = NULL;
head1 = newNode;

newNode = (struct node*)malloc(sizeof(struct node));
newNode->data = 10;
newNode->link = NULL;
head1->link = newNode;

newNode = (struct node*)malloc(sizeof(struct node));
newNode->data = 15;
newNode->link = NULL;
head1->link->link = newNode;

newNode = (struct node*)malloc(sizeof(struct node));
newNode->data = 7;
newNode->link = NULL;
head2= newNode;

newNode = (struct node*)malloc(sizeof(struct node));
newNode->data = 25;
newNode->link = NULL;
head1->link->link->link = newNode;
head2->link = newNode;

newNode = (struct node*)malloc(sizeof(struct node));
newNode->data = 45;
newNode->link = NULL;
head1->link->link->link->link = newNode;
head2->link->link = newNode;


printf("The list merges at %d\n", MergePointList(head1, head2));


}