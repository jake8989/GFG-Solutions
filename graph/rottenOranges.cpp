/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>> &grid)
{
   int n = grid.size();
   int m = grid[0].size();
   vector<vector<int>> vis(n, vector<int>(m, 0));
   // should use bfs because we have traverse for every level and return maximum of it
   queue<pair<int, pair<int, int>>> q;
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (grid[i][j] == 2)
         {
            q.push({0, {i, j}});
            vis[i][j] = 1;
         }
      }
   }
   int time_ans = 0;
   int movx[] = {-1, 0, 1, 0};
   int movy[] = {0, 1, 0, -1};
   while (!q.empty())
   {
      /* code */
      int t = q.front().first;
      time_ans = max(time_ans, t);
      int row = q.front().second.first;
      int col = q.front().second.second;
      q.pop();
      for (int i = 0; i < 4; i++)
      {
         int dr = row + movx[i];
         int dc = col + movy[i];
         if (dr >= 0 && dr < n && dc >= 0 && dc < m && grid[dr][dc] == 1 && (!vis[dr][dc]))
         {
            q.push({t + 1, {dr, dc}});
            vis[dr][dc] = 1;
         }
      }
   }
   // checking the condition for not rotten at all
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (grid[i][j] == 1 && (!vis[i][j]))
            return -1;
      }
   }
   return time_ans;
}
int main()
{

   return 0;
}