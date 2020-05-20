#include <iostream>
using namespace std;
struct BstTree
{
    int data;
    BstTree *left;
    BstTree *right;
};

// inserting node
BstTree *createNode(int data)
{
    struct BstTree *temp = new BstTree();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

BstTree *insertNode(struct BstTree *root, int data)
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

void printInorder(BstTree *root)
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

}