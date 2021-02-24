#include<stdio.h>
#include<stdlib.h>

#define MARKER -1
struct node {
  int data;
  struct node * left;
  struct node * right;

};

struct node* newNode(int data) {

  struct node * temp = (struct node *)malloc(sizeof(struct node));
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}


struct node* serializeTree(struct node* root, FILE* fp) {

if(!root) {
  return NULL;
}

fprintf(fp, "%d ", root->data);
serializeTree(root->left, fp);
serializeTree(root->right, fp);

fprintf(fp, "%d ", MARKER);

}

struct node* deSerializeTree(FILE * fp, struct node* root) {

  int val;
  fscanf(fp, "%d", &val);

  if(val == MARKER ){
    return NULL;
  }
  root = newNode(val);
  root->left = deSerializeTree(fp, root->left);
  root->right = deSerializeTree(fp, root->right);
  return root;
}

void printInorder(struct node* root) {


if(!root) {
  return;
}
 printInorder(root->left);
 printf("%d\n", root->data);
 printInorder(root->right);

}

int main() {
  
  struct node* root = NULL;
  struct node* root1 = NULL;
  int val;
  root = newNode(10);
  root->left = newNode(7);
  root->right = newNode(12);
  root->left->left = newNode(2);
  root->left->right = newNode(8);

  FILE *fp = fopen("TreeOut.txt", "w");
  if(!fp) {
      puts("Could not open file");
      return 0;
  }
  serializeTree(root, fp);
  fclose(fp);
  fp = fopen("TreeOut.txt", "r");
  fscanf(fp, "%d", &val);
  printf("%d\n", val);
  fscanf(fp, "%d", &val);
  printf("%d\n", val);
  fscanf(fp, "%d", &val);
  printf("%d\n", val);
  fscanf(fp, "%d%s", &val);
  printf("%d%s\n", val);

  // root1= deSerializeTree(fp, root1);
  // printInorder(root1);
  

}