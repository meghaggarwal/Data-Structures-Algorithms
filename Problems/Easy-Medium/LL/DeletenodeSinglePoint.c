// Delete a node given a single pointer reference.

// i/p - 1->2->10->4->9->6
//             p
// 0/p- 1->2->4->9->6

// Copy data from p->next to p and delete p->next


struct node {
  int data;
  struct node* link;
};

struct node* deleteNode(struct node *p) {
  
  struct node* temp = p->link;
  p->data = temp->data;
  p->link = temp->link;
  free(temp);

}

int main() {


}