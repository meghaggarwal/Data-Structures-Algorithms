// Given a binary tree, connect the nodes present on the same level
#include<stdlib.h>
#include<iostream>
#include<stdio.h>
using namespace std;

void connectNodes(struct BstTree *root);
struct BstTree * getNewNode(struct BstTree * root);
struct BstTree * newNode(int data);

struct BstTree
{

  int data;
  struct BstTree *left;
  struct BstTree *right;
  struct BstTree *next;
};

void connectNodes(struct BstTree *root)
{

  struct BstTree *p = root;
  if(!root) {
    return;
  }
  
  while (p)
  {

    struct BstTree *q = p;
    while (q!=NULL)
    {

      if (!q)
      {
        return;
      }

      if (q->left)
      {

        if (q->right)
        {

          q->left->next = q->right;
        }

        else
        {
          q->left->next = getNewNode(q);
        }
      }

      if (q->right)
      {

        q->right->next = getNewNode(q);
      }

      q = q->next;
    }

    if(p->left) {
      p = p->left;
    }
    else if(p->right) {
      p = p->right;
    }
    else {
      p = getNewNode(p);
    }
  }
}


struct BstTree * getNewNode(struct BstTree * root) {
   
    struct BstTree * temp = root->next;
    while(temp!=NULL) {

      if(temp->left) {

        return temp->left;
      }
      if(temp->right) {
        return temp->right;
      }
      temp = temp->next;
    }

    return NULL;

}

struct BstTree * newNode(int data) {
  
  struct BstTree* temp = (struct BstTree *)malloc(sizeof(struct BstTree));
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  temp->next = NULL;
  return temp;

}

int main() {

   struct BstTree* root = newNode(2);
   root->left = newNode(24);
   root->right = newNode(100);
   root->left->left = newNode(10);
   root->right->right = newNode(120);
   connectNodes(root);
    printf("Following are populated nextRight pointers in the tree "
           "(-1 is printed if there is no nextRight) \n"); 
    cout << root->data << endl;
    printf("next of %d is %d \n", root->left->data, 
           root->left->next? root->left->next->data: -1); 
    printf("next of %d is %d \n", root->right->data, 
           root->right->next? root->right->next->data: -1); 
    printf("next of %d is %d \n", root->left->left->data, 
           root->left->left->next? root->left->left->next->data: -1); 
    printf("next of %d is %d \n", root->right->right->data, 
           root->right->right->next? root->right->right->next->data: -1); 

    return 0;
}