

checkSiblings(root, data, data1) {

  if(!root){
    return False
  }
 
  if(root->left->data == data) || (root->right->data == data) 
  and (root->left->data == data1) || (root->right->data == data1)

  {
    return True
  }

  return checkSiblings(root->left, data, data1)
|| checkSiblibgs(root->right, data, data1)


}