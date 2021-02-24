#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct Bstnode {
  int data;
  Bstnode* left;
  Bstnode* right;

};

struct Bstnode* getnewNode(int data) {

  struct Bstnode* newNode = new Bstnode();
  newNode->data = data;
  newNode->left=newNode->right=NULL;

  return newNode;
}

struct Bstnode* insertBSTTree(struct Bstnode ** root, int data) {


  if(!*root) {
    *root = getnewNode(data);      
  }

  if(data < (*root)->data) {
    (*root)->left = insertBSTTree(&((*root)->left), data);
  }

   if(data > (*root)->data) {
    (*root)->right = insertBSTTree(&((*root)->right), data);
  }

  return *root; 

}

bool nodeSearchTree(struct Bstnode **root, int data) {

   if(!(*root)) {
     return false;
   }

   if((*root)->data == data) {
    return true;
    
   }

    if((*root)->data >= data) {
     return nodeSearchTree( &(*root)->left, data);
   }

    if((*root)->data < data){
     return nodeSearchTree( &(*root)->right, data);
   }
 
 return false;

}

int main()
 {
  struct Bstnode* root = NULL;
  int n, num = 0; int nums;
  cout << "Enter no of elements \n";
  cin >> n ;
  for(int i = 0 ; i < n ; i++) {
    cin >> num;
    insertBSTTree(&root, num);
  }
  cout << "Enter the element to be searched \n";
  cin >> nums;
  if(nodeSearchTree(&root, nums) == true) {
   cout << "Element found \n";
  }
  else {
    cout << "No element found \n";
  }
  return 0;
}