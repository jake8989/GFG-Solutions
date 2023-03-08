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
vector<int> serialize(Node *root)
{
   // Your code here
   vector<int> ans;
   // level order traversal

   queue<Node *> q;
   q.push(root);
   while (!q.empty())
   {
      Node *par = q.front();
      q.pop();
      if (par == NULL)
         ans.push_back(-1);
      else
      {
         ans.push_back(par->data);
      }
      if (par != NULL)
      {
         q.push(par->left);
         q.push(par->right);
      }
   }
   // for(auto it:ans)cout<<it<<" ";
   return ans;
}

// Function to deserialize a list and construct the tree.
Node *deSerialize(vector<int> &A)
{
   // Your code here
   Node *root = NULL;
   root = new Node(A[0]);
   queue<Node *> q;
   q.push(root);
   int p = 1;

   while (!q.empty() && p != A.size())
   {
      Node *par = q.front();
      q.pop();
      if (A[p] == -1)
      {
         par->left = NULL;
         p++;
      }
      else
      {
         Node *left = new Node(A[p]);
         par->left = left;
         q.push(left);
         p++;
      }
      if (A[p] == -1)
      {
         par->right = NULL;
         p++;
      }
      else
      {
         Node *right = new Node(A[p]);
         par->right = right;
         q.push(right);
         p++;
      }
   }
   return root;
}

int main()
{

   return 0;
}