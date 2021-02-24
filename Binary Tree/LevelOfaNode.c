Find the level of a node in a given tree using level order travseral.
Iterative way to traverse the tree in all forms.


int heightofTree(struct node * root) {

  if(!root) {
    return -1;
  }

  leftheight = heightofTree(root->left) + 1
  rightheight = heightofTree(root->right) + 1
  root->height = leftheight - rightheight

  return root->height;
}