/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
   int data;
   Node *left;
   Node *right;
   Node(int data)
   {
      this->data = data;
      this->left = NULL;
      this->right = NULL;
   }
};
void solve(Node *root, Node *&head, Node *&prev)
{
   if (root == NULL)
      return;
   solve(root->left, head, prev);
   if (prev == NULL)
   {
      head = root;
   }
   else
   {
      root->left = prev;
      prev->right = root;
   }
   prev = root;
   solve(root->right, head, prev);
}

// Function to convert binary tree to doubly linked list and return it.
Node *bToDLL(Node *root)
{
   // your code here
   Node *head, *prev;
   head = prev = NULL;
   solve(root, head, prev);
   return head;
}
int main()
{

   return 0;
}