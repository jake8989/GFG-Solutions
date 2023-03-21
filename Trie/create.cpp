/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
   char data;
   TrieNode *children[26];
   bool isTerminal;
   TrieNode(char d)
   {
      data = d;
      for (int i = 0; i < 26; i++)
      {
         children[i] = NULL;
      }
      isTerminal = false;
   }
};
class Trie
{
public:
   TrieNode *root;
   Trie()
   {
      root = new TrieNode('#');
   }

   void insertUtil(TrieNode *root, string key)
   {
      if (key.length() == 0)
      {
         root->isTerminal = true;
         return;
      }
      int index = key[0] - 'A';
      TrieNode *child;
      if (root->children[index] != NULL)
      {
         child = root->children[index];
      }
      else
      {
         child = new TrieNode(key[0]);
         root->children[index] = child;
      }
      insertUtil(child, key.substr(1));
   }
   void insertWord(string key)
   {
      insertUtil(root, key);
   }
   bool searchUtil(TrieNode *root, string key)
   {
      if (key.length() == 0)
      {
         return root->isTerminal;
      }
      int index = key[0] - 'A';
      TrieNode *child;
      if (root->children[index] != NULL)
      {
         child = root->children[index];
      }
      else
      {
         return false;
      }
      return searchUtil(child, key.substr(1));
   }
   bool searchWord(string key)
   {
      return searchUtil(root, key);
   }
};
int main()
{
   Trie *t = new Trie();
   t->insertWord("ABCD");
   if (t->searchWord("ABCD"))
      cout << ":YES\n";
   else
      cout << "NO\n";
   if (t->searchWord("ABCDE"))
      cout << ":YES\n";
   else
      cout << "NO\n";
   return 0;
}