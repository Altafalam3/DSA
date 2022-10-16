// Binary Search Tree
#include <stdio.h>
#include <stdlib.h>

struct node
{
   int data;
   struct node *left;
   struct node *right;
};

struct node *ins(struct node *root, int val)
{
   struct node *temp = root;
   // ek piche rehke hamesha follow krtaa
   struct node *follow = NULL;
   struct node *new = (struct node *)malloc(sizeof(struct node));
   new->data = val;
   new->left = NULL;
   new->right = NULL;

   // empty tree condition
   if (root == NULL)
   {
      root = new;
      return root;
   }

   // traverse to find node where to insert
   while (temp != NULL)
   {
      follow = temp;
      if (temp->data < new->data)
      {
         temp = temp->right;
      }
      else
      {
         temp = temp->left;
      }
   }

   // inserting node check -left /right
   if (follow->data > new->data)
   {
      follow->left = new;
   }
   else
   {
      follow->right = new;
   }
   return root;
}

struct node *inorderpre(struct node *root)
{
   root = root->left;
   while (root->right != NULL)
   {
      root = root->right;
   }
   return root;
}

struct node *del(struct node *root, int x)
{
   // save inorder predecessor for swapping
   struct node *iPre;
   if (root == NULL)
   {
      return NULL;
   }
   if (root->left == NULL && root->right == NULL)
   {
      free(root);
      return NULL;
   }
   // searching for the node to be deleted
   if (x < root->data)
   {
      root->left = del(root->left, x);
   }
   else if (x > root->data)
   {
      root->right = del(root->right, x);
   }
   // delete when the node is found
   else
   {
      iPre = inorderpre(root);
      root->data = iPre->data;
      root->left = del(root->left, iPre->data);
   }
   return root;
}

// display using inorder
void display(struct node *root)
{
   if (root != NULL)
   {
      display(root->left);
      printf("%d\t", root->data);
      display(root->right);
   }
}

void preorder(struct node *root)
{
   if (root != NULL)
   {
      printf("%d\t", root->data);
      display(root->left);
      display(root->right);
   }
}

void postoder(struct node *root)
{
   if (root != NULL)
   {
      display(root->left);
      display(root->right);
      printf("%d\t", root->data);
   }
}

// search iteration
int searchIter(struct node *root, int key)
{
   while (root != NULL)
   {
      if (key == root->data)
      {
         return 1;
      }
      else if (key < root->data)
      {
         root = root->left;
      }
      else
      {
         root = root->right;
      }
   }
   return 0;
}

//search recursive
int search(struct node *root, int key)
{
   if (root != NULL)
   {
      if (key == root->data)
      {
         return 1;
      }
      else if (key < root->data)
      {
         return search(root->left, key);
      }
      else
      {
         return search(root->right, key);
      }
   }
   else
   {
      return 0;
   }
}

struct node *createNode(int data)
{
   struct node *n;                                 // creating a node pointer
   n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
   n->data = data;
   n->left = NULL;
   n->right = NULL;
   return n; // returning node
}

int main()
{
   struct node *root = NULL;

   // c is choice
   int c, val;
   root=ins(root, 1);
   root=ins(root, 7);
   root=ins(root, 3);
   display(root);
   printf("\n%d\n",search(root,7));
   printf("\n%d\n",search(root,5));

   printf("\n%d\n",searchIter(root,7));
   printf("\n%d\n",searchIter(root,5));

   //   while (c != 4)
   //    {
   //       printf("\nEnter\n 1.for insert\n 2.for delete\n 3.for display\n 4.for exit\n");
   //       scanf("%d", &c);
   //       switch (c)
   //       {
   //       case 1:
   //          printf("\nEnter the value");
   //          scanf("%d", &val);
   //          root = ins(root, val);
   //          if (root != NULL)
   //             display(root);
   //          else
   //             printf("Tree is empty");
   //          break;
   //       case 2:
   //          printf("Enter the value");
   //          scanf("%d", &val);
   //          root = del(root, val);
   //          if (root != NULL)
   //             display(root);
   //          else
   //             printf("Tree is empty");
   //          break;
   //       case 3:
   //          if (root != NULL)
   //             display(root);
   //          else
   //             printf("Tree is empty");
   //          break;
   //       }
   //    }

   return 0;
}
