#include<iostream>
#include<stdlib.h>
using namespace std;

void LeftView(struct BstTree * root, int level);
struct BstTree *createNode(int data);
struct BstTree *insertNode(BstTree *root, int data);
void printInorder(BstTree *root);

struct BstTree {
  int data;
  BstTree *left;
  BstTree *right;

};

int temp = -1;

void LeftView(BstTree *root, int level) {

  if(root == NULL) {
    return ;
  }  
  if(temp < level) {
    temp = level;
    cout << root->data << endl;
  }
  LeftView(root->left, level+1);
  LeftView(root->right, level + 1);
}



BstTree *createNode(int data)
{
    struct BstTree *temp = new BstTree();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct BstTree *insertNode(struct BstTree *root, int data)
{

    if (root == NULL)
        return createNode(data);

    else if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }

    return root;
}

void printInorder(struct BstTree *root)
{

    if (root == NULL)
        return;
    else
    {
        printInorder(root->left);
        cout << root->data << endl;
        printInorder(root->right);
    }
}

int main()
{
    struct BstTree *root = NULL;
    int n, val;
    cout << "Enter the no of nodes to be inserted in Binary Tree: " << endl;
    cin >> n;
    cout << "Enter the node values: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        root = insertNode(root, val);
    }
    cout << "Inserted Successfully, Values in order traversal: " << endl;
    printInorder(root);
    LeftView(root, 0);

}