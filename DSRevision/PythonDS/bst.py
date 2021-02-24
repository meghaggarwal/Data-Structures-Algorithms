from dataclasses import dataclass

@dataclass
class Bst():
  data:int
  left:object
  right:object


def insertNode(data, b):
  if b is None:
    return Bst(data, None, None)

  if data < b.data:
    b.left = insertNode(data, b.left)

  else:
    b.right = insertNode(data, b.right)

  return b
      
   
b = None
b = insertNode(1, b)
insertNode(2, b)
insertNode(3,b)

def traverse_in_order(root):
    if root is None:
        return

    if root.left is not None:
        traverse_in_order(root.left)

    print(root.data)

    if root.right is not None:
        traverse_in_order(root.right)


if __name__ == "__main__":
    traverse_in_order(b)


# 2 3 4 5 6 7

# void inorderTraversal(struct node * root) {
 
#    if(!root):
#      return

#     inorderTraversal(root->left)
#     print(root->data)


# }