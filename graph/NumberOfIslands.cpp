/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
// Function to find the number of islands.
int numIslands(vector<vector<char>> &grid)
{
   int n = grid.size();
   int m = grid[0].size();
   vector<vector<int>> vis(n, vector<int>(m, 0));
   int ans = 0;
   // int movx[] = {-1, 0, 1, 0};
   // int movy[] = {0, 1, 0, -1};
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (grid[i][j] == 1 && !vis[i][j])
         {
            ans++;
            queue<pair<int, int>> q;
            q.push({i, j});
            vis[i][j] = 1;
            while (!q.empty())
            {
               /* code */
               int r = q.front().first;
               int c = q.front().second;
               q.pop();
               for (int k = -1; k <= 1; k++)
               {
                  for (int m_ = -1; m_ <= 1; m_++)
                  {
                     int dr = k + r;
                     int dc = m_ + c;
                     if (dr >= 0 && dr < n && dc >= 0 && dc < m && grid[dr][dc] == '1' && (!vis[dr][dc]))
                     {
                        q.push({dr, dc});
                        vis[dr][dc] = 1;
                     }
                  }
               }
            }
         }
      }
   }
}
int main()
{

   return 0;
}