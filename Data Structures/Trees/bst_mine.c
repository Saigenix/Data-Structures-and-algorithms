#include<stdio.h>
#include<stdlib.h>

struct node {
int key;
struct node* left;
struct node* right;
};

struct node *minValueNode(struct node *node) {
  struct node *current = node;

  while (current && current->left != NULL)
    current = current->left;

  return current;
}



struct node * createNode(int d){
struct node* n;
n = (struct node *)malloc(sizeof(struct node));
n-> key = d;
n-> left = NULL;
n -> right = NULL;
return n; 
}

struct node *insert(struct node *node, int key) {
  if (node == NULL) return createNode(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

   
    struct node *temp = minValueNode(root->right);

    root->key = temp->key;

    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

void inorder(struct node* r){
if (r->left != NULL) inorder(r->left);
printf("%d ",r->key);
if (r->right != NULL) inorder(r->right);
}

void preorder(struct node* r){
printf("%d ",r->key);
if (r->left != NULL) preorder(r->left);
if (r->right != NULL) preorder(r->right);
}

void postorder(struct node* r){
if (r->left != NULL) postorder(r->left);
if (r->right != NULL) postorder(r->right);
printf("%d ",r->key);
}

void search(struct node* r, int k){
if (r->key == k){
printf("element is found...\n");
return;
}
if (r == NULL) return;
if (r->left != NULL) search(r->left,k);
if (r->right != NULL) search(r->right,k);


}

void main(){
//       8
//     /  \
//    7    9
//  /       \
// 4         10
// /
//3
struct node* root = createNode(8);
int val;
int key;


while(1){
printf("\n 1. insert \n 2. delete \n 3. inorder \n 4. preorder \n 5.postorder \n 6. search \n");
scanf("%d",&val);
switch(val){
case 1: 
printf("enter value to add: \n");
scanf("%d",&key);
root = insert(root,key);
break;
case 2: 
printf("enter value to delete: \n");
scanf("%d",&key);
root = deleteNode(root,key);
break;
case 3: 
printf("inorder : \n");
inorder(root);
break;
case 4:
printf("\n");
printf("preorder : \n");
preorder(root);
break;
case 5:
printf("\n");
printf("postorder : \n");
postorder(root);
printf("\n");
break;
case 6: printf("enter value to search: \n");
scanf("%d",&key);
search(root,key);
break;
}
}

}