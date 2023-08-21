#include <stdio.h>
#include <stdlib.h>

struct node
{
  int key;
  struct node *left;
  struct node *right;
};

struct node *CreateNode(int val)
{
  struct node *n;
  n = (struct node *)malloc(sizeof(struct node));
  n->key = val;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void Inorder(struct node* n){
  if(n != NULL){
    Inorder(n->left);
    printf("%d ",n->key);
    Inorder(n->right);
  }
}

void preOrder(struct node* n){
  if(n != NULL){
    printf("%d ",n->key);
    preOrder(n->left);
    preOrder(n->right);
  }
}

void PostOrder(struct node* n){
  if(n != NULL){
    PostOrder(n->left);
    PostOrder(n->right);
    printf("%d ",n->key);
  }
}

struct node* Insert(struct node* root,int key){
  if(root == NULL){
    return CreateNode(key);
  }

  if(key < root->key){
    root->left = Insert(root->left,key);
  }else if(key > root->key){
    root->right = Insert(root->right,key);
  }

  return root;
}

struct node* Search(struct node* root,int key){
  if(root==NULL || key == root->key){
    return root;
  }
  if(key < root->key){
    return Search(root->left,key);
  }
  return Search(root->right,key);
}

struct node* MinVal(struct node* r){
  struct node* p = r;
  while(p!=NULL && p->left!=NULL){
    p =p->left;
  }
  return p;
}

struct node* DeleteNode(struct node* root,int key){
  if(root == NULL){
    return root;
  }
  if(key < root->key){
    root->left = DeleteNode(root->left,key);
  }else if(key > root->key){
    root->right = DeleteNode(root->right,key);
  }else{
    if(root-> left == NULL){
      struct node* temp = root->right;
      free(root);
      return temp;

    }
    if(root->right == NULL){
      struct node* temp = root->left;
      free(root);
      return temp;
    }
    struct node * min = MinVal(root->right);
    root->key = min->key;
    root->right = DeleteNode(root->right,min->key);

  }
  return root;
}

int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}



void main()
{

  struct node *root = CreateNode(12);
  //        12
  //      /  \
/ /     7    15
  //   /  \     \
  //  4    8     17
  // /
  // 3
  // create - to create or add node in binary tree
  // delete - to delete from binary tree
  // traversal - inorder , preorder , postorder
  // search - to find element in binary tree

int val;
int key;


while(1){
printf("\n 1. insert \n 2. delete \n 3. inorder \n 4. preorder \n 5.postorder \n 6. search \n");
scanf("%d",&val);
switch(val){
case 1: 
printf("enter value to add: \n");
scanf("%d",&key);
root = Insert(root,key);
break;
case 2: 
printf("enter value to delete: \n");
scanf("%d",&key);
root = DeleteNode(root,key);
break;
case 3: 
printf("inorder : \n");
Inorder(root);
break;
case 4:
printf("\n");
printf("preorder : \n");
preOrder(root);
break;
case 5:
printf("\n");
printf("postorder : \n");
PostOrder(root);
printf("\n");
break;
case 6: printf("enter value to search: \n");
scanf("%d",&key);
Search(root,key);
break;
}
}



}