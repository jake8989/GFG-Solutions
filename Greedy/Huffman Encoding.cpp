/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
   Node *left;
   Node *right;
   int data;
   Node(int d)
   {
      this->data = d;
      left = right = NULL;
   }
};
class cmp
{
public:
   bool operator()(Node *a, Node *b)
   {
      return a->data > b->data;
   }
};
void solve(vector<string> &ans, Node *root, string path)
{
   if (root->left == NULL && root->right == NULL)
   {
      ans.push_back(path);
      path.pop_back();
      return;
   }
   solve(ans, root->left, path + "0");
   solve(ans, root->right, path + "1");
   path.pop_back();
}
vector<string> huffmanCodes(string S, vector<int> f, int N)
{
   // Code here
   vector<string> ans;
   priority_queue<Node *, vector<Node *>, cmp> pq;
   for (int i = 0; i < N; i++)
   {
      Node *tp = new Node(f[i]);
      pq.push(tp);
   }
   while (pq.size() > 1)
   {
      Node *left = pq.top();
      pq.pop();
      Node *right = pq.top();
      pq.pop();
      Node *newNode = new Node(left->data + right->data);
      newNode->left = left;
      newNode->right = right;
      pq.push(newNode);
   }
   Node *root = pq.top();
   pq.pop();
   solve(ans, root->left, "0");
   solve(ans, root->right, "1");
   return ans;
}
int main()
{

   return 0;
}