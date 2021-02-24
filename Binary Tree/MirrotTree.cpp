// Serialization
// Deserialization

#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct BstNode {
  int data;
  struct BstNode * left;
  struct BstNode * right;
};

struct BstNode* createNode(int data) {

// struct BstNode *temp = new BstNode();
struct BstNode *temp = (struct BstNode*)malloc(sizeof(struct BstNode));
temp->data = data;
temp->left = NULL;
temp->right = NULL;

return temp;

}

struct BstNode* BinaryTree(struct BstNode** root, int data) {

    if( *root == NULL ) 
    {
      return createNode(data);
    }

    else if(data < (*root)->data) 
    {
      (*root)->left = BinaryTree( &((*root)->left), data );
    }
    else 
    {
      (*root)->right = BinaryTree( &((*root)->right), data);
    }

    return *root;

} 

void Print(struct BstNode *root) {

  if (root==NULL)
  {
    return;
  }
  
  Print(root->left);
  printf("%d\n", root->data);
  Print(root->right);

}

bool isMinor(struct BstNode * root, struct BstNode * root1) {

  if(root == NULL  && root1 == NULL) {
    return true;
  }

  if(root && root1 && root->data == root1->data) 
  {
  
   return isMinor(root->left , root1->right) &&
  isMinor(root->right, root1->left);

  }
    return false;

  }


int main() 
{
  struct BstNode* root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(2);
   root->left->left  = createNode(3); 
    root->left->right = createNode(4); 
    root->right->left  = createNode(40); 
    root->right->right = createNode(3);
 
  printf("%d", isMinor(root->left, root->right));
  return 0;
  
}
// Deepest node in a tree
// level of a node
// height of a node
// is Identical Tree


















