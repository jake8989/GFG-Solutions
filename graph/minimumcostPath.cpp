/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
int minimumCostPath(vector<vector<int>> &grid)
{
   int n = grid.size();
   int m = grid[0].size();
   vector<vector<int>> vis(n, vector<int>(m, 0));
   vector<vector<int>> dist(n, vector<int>(m, 1e9));
   dist[0][0] = grid[0][0];
   priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
   pq.push({dist[0][0], {0, 0}});
   int movx[] = {-1, 0, 1, 0};
   int movy[] = {0, 1, 0, -1};
   while (!pq.empty())
   {
      int dis = pq.top().first;
      int row = pq.top().second.first;
      int col = pq.top().second.second;
      pq.pop();
      for (int i = 0; i < 4; i++)
      {
         int dr = row + movx[i];
         int dc = col + movy[i];
         if (dr >= 0 && dr < n && dc >= 0 && dc < m)
         {
            if (dist[dr][dc] > dis + grid[row][col])
            {
               dist[dr][dc] = dis + grid[row][col];
               pq.push({dist[dr][dc], {dr, dc}});
            }
         }
      }
   }
   return dist[n - 1][m - 1];
}
int main()
{

   return 0;
}