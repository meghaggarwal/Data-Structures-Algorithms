// Given two sorted linked list, merge them into a single sorted linked list.

// I/p - 1->2->14->30->40
//     - 6->8->10->48->60->80

// o/p - 1->2->6->8->10->30->40->48->60->80
#include<stdio.h>
#include<stdlib.h>

struct node {

  int data;
  struct node * link;
};

struct node * mergesortedList(struct node* p, struct node * q) {
 
 struct node * res;

 if(!p) {

   return q;
 }

 if(!q) {

   return p;
 }

 if(p->data < q->data)  {
   res = p;
   res->link = mergesortedList(p->link, q);
 }
 else{
   res = q;
   res->link = mergesortedList(p, q->link);
 }
 
 return res;

}



