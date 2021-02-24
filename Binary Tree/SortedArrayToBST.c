// Given a sorted array convert it into BST

// 1,2,3,4,5,6,7,8

int arr[] = {1,2,3,4,5,6,7,8}

len = sizeof(arr)/ sizeof(int)
if(len(arr) == 1) {
  temp = newNode()
  temp->data = arr
  return temp
}

mid = len // 2
if(!root) {
  root->data = mid
  temp = newNode()
}

root->left = arrayToBST(root->left, arr, 0, mid - 1)
root->right = arrayToBST(root->right, arr, mid + 1, len)
return temp;
