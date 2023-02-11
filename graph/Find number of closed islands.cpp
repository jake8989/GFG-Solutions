/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
int closedIslands(vector<vector<int>> &grid, int N, int M)
{
   // Code here
   vector<vector<int>> vis(N, vector<int>(M, 0));
   queue<pair<int, int>> q;
   int movx[] = {-1, 0, 1, 0};
   int movy[] = {0, 1, 0, -1};
   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < M; j++)
      {
         if (grid[i][j] == 1)
         {
            if (i == 0 || i == N - 1 || j == 0 || j == M - 1)
            {
               if (grid[i][j] == 1 && (!vis[i][j]))
               {
                  queue<pair<int, int>> q;
                  q.push({i, j});
                  vis[i][j] = 1;
                  while (!q.empty())
                  {
                     /* code */
                     int row = q.front().first;
                     int col = q.front().second;
                     q.pop();
                     for (int i = 0; i < 4; i++)
                     {
                        int dr = row + movx[i];
                        int dc = col + movy[i];
                        if (dr >= 0 && dr < N && dc >= 0 && dc < M && (!vis[dr][dc]) && grid[dr][dc] == 1)
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
   int ans = 0;
   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < M; j++)
      {
         if (grid[i][j] == 1)
         {
            ans++;
            if (grid[i][j] == 1 && (!vis[i][j]))
            {
               queue<pair<int, int>> q;
               q.push({i, j});
               vis[i][j] = 1;
               while (!q.empty())
               {
                  /* code */
                  int row = q.front().first;
                  int col = q.front().second;
                  q.pop();
                  for (int i = 0; i < 4; i++)
                  {
                     int dr = row + movx[i];
                     int dc = col + movy[i];
                     if (dr >= 0 && dr < N && dc >= 0 && dc < M && (!vis[dr][dc]) && grid[dr][dc] == 1)
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
   return ans;
}
int main()
{

   return 0;
}