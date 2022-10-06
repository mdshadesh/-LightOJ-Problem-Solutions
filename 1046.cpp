#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <utility>

#define SIZE 12
#define MOD 20071027

#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))

using namespace std;

int row, column, n;

int X[] = {1, 1, 2, 2, -1, -1, -2, -2};
int Y[] = {2, -2, 1, -1, 2, -2, 1, -1};

struct point
{
	int x;
	int y;
	int k;
	
	point(int x, int y, int k){this->x = x; this->y = y; this->k = k;}
	point(){}
};

unsigned dist[SIZE][SIZE][11];
unsigned result[SIZE][SIZE];
int grid[SIZE][SIZE];

int main()
{
	int tc, t = 0, i, j, k, m, x, y, z, a, b, c, value, l;
	unsigned d, mx;
	char ch;
	bool flag;
	string str1, str2, s1, s2, s3;
	
	//freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	
	for(t = 1; t <= tc; t++)
	{
		memset(result, 0, sizeof result);
		scanf("%d %d", &row, &column);

		vector<pair<int, int> > points;
		
		getchar();
		for(i = 0; i < row; i++)
		{
			for(j = 0; j < column; j++)
			{
				grid[i][j] = getchar()-'0';
				if(grid[i][j] > 0 && grid[i][j] < 10) points.push_back(make_pair(i, j));
			}
			getchar();
		}
		
		point p;
		/* We do a BFS for each rider */
		for(vector<pair<int, int> >::iterator it = points.begin(); it != points.end(); it++)
		{
			memset(dist, -1, sizeof dist);
			
			queue<point> q;
			q.push(point(it->first, it->second, grid[it->first][it->second]+1));
			dist[it->first][it->second][grid[it->first][it->second]+1] = 1;
			
			while(!q.empty())
			{
				x = q.front().x;
				y = q.front().y;
				k = q.front().k;
				q.pop();
				
				/* we can do l more jumps before time is increased (1 <= l <= K) */
				l = k - 1;
				if(l == 0) l = grid[it->first][it->second];
				
				for(i = 0; i < 8; i++)
				{
					a = x+X[i];
					b = y+Y[i];
					if(!BOUNDARY(a, b)) continue;
					
					/* increase the time if only one jump is left */
					d = dist[x][y][k] + (k == 1 ? 1 : 0);
					if(dist[a][b][l] > d)
					{
						dist[a][b][l] = d;
						q.push(point(a, b, l));
					}
				}
			}
			
			/* BFS is finished, now for each node, from K considerations, find the minimum one */
			for(i = 0; i < row; i++)
			{
				for(j = 0; j < column; j++)
				{
					if(i != it->first || j != it->second)
					{					
						mx = -1;
						for(k = 1; k <= 10; k++)
						{
							if(mx > dist[i][j][k]) mx = dist[i][j][k];
						}
						
						/* We have found the minimum value from K different values. Add it to the total */
						if(mx == -1) result[i][j] = -1;
						else if(result[i][j] != -1) result[i][j] += mx;
					} 
				}
			}
		}
		
		/* BFS is finished for all the riders. Now find the node with minimum total sum of the time */
		mx = -1;
		for(i = 0; i < row; i++)
		{
			for(j = 0; j < column; j++)
			{
				if(result[i][j] < mx) mx = result[i][j];
			}
		}
		
		printf("Case %d: %d\n", t, mx);
	}	
	
	return 0;
}