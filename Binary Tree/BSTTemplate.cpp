#include<stdio.h>
#include<stdlib.h>

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

int main() {

  struct BstNode* root = NULL;
  int n, num;
  printf("Enter the no of nodes in the tree: ");
  scanf("%d", &n);
  for(int i = 0; i<n;i++) {
    scanf("%d", &num);
    root = BinaryTree(&root, num);
  }

  printf("Binary Tree is: \n");
  Print(root);
  
}
// Deepest node in a tree
// level of a node
// height of a node
// is Identical Tree
