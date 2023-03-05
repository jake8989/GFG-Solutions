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
void markParent(Node *root, unordered_map<Node *, Node *> &NodeToParent, Node *&start, int tar)
{
   queue<Node *> q;
   q.push(root);
   while (!q.empty())
   {
      Node *node = q.front();
      q.pop();
      if (node->data == tar)
      {
         start = node;
      }
      if (node->left)
      {
         NodeToParent[node->left] = node;
         q.push(node->left);
      }
      if (node->right)
      {
         NodeToParent[node->right] = node;
         q.push(node->right);
      }
   }
}
void burnTree(Node *root, Node *start, unordered_map<Node *, Node *> &NodeToParent, int &ans)
{
   queue<Node *> q;
   q.push(start);
   unordered_map<Node *, bool> vis;
   vis[start] = true;
   while (!q.empty())
   {
      int size = q.size();
      int isPushed = false;
      for (int i = 0; i < size; i++)
      {
         Node *node = q.front();
         q.pop();
         if (node->left && !vis[node->left])
         {
            q.push(node->left);
            isPushed = true;
            vis[node->left] = 1;
         }
         if (node->right && !vis[node->right])
         {
            q.push(node->right);
            isPushed = true;
            vis[node->right] = 1;
         }
         if (NodeToParent[node] && !vis[NodeToParent[node]])
         {
            q.push(NodeToParent[node]);
            vis[NodeToParent[node]] = 1;
            isPushed = true;
         }
      }
      if (isPushed)
         ans++;
   }
}
int minTime(Node *root, int target)
{
   // Your code goes here
   Node *tgStart = NULL;
   unordered_map<Node *, Node *> NodeToParent;
   markParent(root, NodeToParent, tgStart, target);
   int ans = 0;
   burnTree(root, tgStart, NodeToParent, ans);
   return ans;
}
int main()
{

   return 0;
}