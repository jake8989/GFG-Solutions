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
Node *markParent(Node *root, int target, unordered_map<Node *, Node *> &NodeToParent, Node *&res)
{
   queue<Node *> q;
   q.push(root);
   while (!q.empty())
   {
      Node *node = q.front();
      q.pop();
      if (node->data == target)
      {
         res = node;
      }
      if (node->left)
      {
         q.push(node->left);
         NodeToParent[node->left] = node;
      }
      if (node->right)
      {
         q.push(node->right);
         NodeToParent[node->right] = node;
      }
   }
}
vector<int> KDistanceNodes(Node *root, int target, int k)
{
   // return the sorted vector of all nodes at k dist
   // inorder to travel on the upward direction we have to make each node's parent
   unordered_map<Node *, Node *> NodeToParent;
   Node *tgStart = NULL;
   markParent(root, target, NodeToParent, tgStart);
   unordered_map<Node *, bool> vis;
   vis[tgStart] = 1;
   queue<Node *> q;
   q.push(tgStart);
   int level = 0;
   while (!q.empty())
   {
      int size = q.size();
      if (level++ == k)
         break;
      for (int i = 0; i < size; i++)
      {
         Node *node = q.front();
         q.pop();
         if (node->left && !vis[node->left])
         {
            q.push(node->left);
            vis[node->left] = 1;
         }
         if (node->right && !vis[node->right])
         {
            q.push(node->right);
            vis[node->right] = 1;
         }
         if (NodeToParent[node] && !vis[NodeToParent[node]])
         {
            q.push(NodeToParent[node]);
            vis[NodeToParent[node]] = true;
         }
      }
   }
   vector<int> ans;
   while (!q.empty())
   {
      /* code */
      ans.push_back(q.front()->data);
      q.pop();
   }
   return ans;
}

int main()
{

   return 0;
}