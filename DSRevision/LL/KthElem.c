#include<stdio.h>
#include<stdlib.h>

struct node{

  int data;
  struct node * next;
};

struct node* createNode(int data) {

  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->data = data;
  temp->next = NULL;
  return temp;
}

void printNode(struct node* root) {

  struct node* head = root;
  while(head) {

    printf("%d\n", head->data);
    head = head->next;
  }
}

void kElementList(struct node * root , int k)
 {
int n = 0;
struct node* p , * q;
p = q =  root;
while(n < k && q) {

q = q->next;
n+=1;

}

if (!q) {
  printf("%d", -1);
  return;
}

while(q) {
  q= q->next;
  p = p->next;
}

printf("%d", p->data);
}

int main() {

  struct node* root = createNode(10);
  root->next = createNode(20);
  root->next->next = createNode(23);
  root->next->next->next = createNode(90);
  printNode(root);
  kElementList(root, 10);
  return 0;

}
