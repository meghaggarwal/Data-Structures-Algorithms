#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* link;
};

void Insert(int data, struct node **head);
void Print(struct node *head);
struct node* getOddEvenElement(struct node * head);
struct node* MergeList(struct node* oddhead, struct node * odd, struct node* even);

struct node* getOddEvenElement(struct node * head)
 {
struct node *p, *odd,*even,*headnew, * oddhead, *evenhead;
int counter = 1;
odd=even=headnew=oddhead=evenhead=NULL;
p = head;

while(p!=NULL)
{

if(counter%2==1){

  if(!oddhead) {

    oddhead = p;
    odd = p;
  }
  else
  {
  odd->link = p;
  odd = odd->link;
    
  }

}

else{

  if(!evenhead) {

    evenhead = p;
    even = p;
    
  }
  else
  {
    
  even->link = p;
  even = even->link;
  }


}

counter ++;
p = p->link;

}

if(even!=NULL) {
even->link = NULL;
}

headnew = MergeList(oddhead,odd, evenhead);
return headnew;
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
  return;
}

struct node* MergeList(struct node* oddhead, struct node * odd, struct node* evenhead)
{

if(!odd) {
  return NULL;
}

odd->link = evenhead;
return oddhead;

}
int main() {

  struct node * head = NULL;
  int n, num, k, elem;
  struct node* res;
  printf("Enter the no of elements in list: \n");
  scanf("%d", &n);
  printf("Enter the elements in list: \n");
  for(int i = 0; i<n;i++) {
    scanf("%d", &num);
    Insert(num, &head);
  }
  printf("The List is: \n");
  Print(head);
  res = getOddEvenElement(head);
  Print(res);
  Print(head);
     
}
