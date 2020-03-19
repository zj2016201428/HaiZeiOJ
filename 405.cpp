/*************************************************************************
	> File Name: 405.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  3/19 11:42:21 2020
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
using namespace std;

struct node {
    int x, y;
};

int n, m, k, ans;
char mmap[3005][3005];
int check[3005][3005];
int  dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
queue<node> que;

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (check[tx][ty] == 0 && mmap[tx][ty] != mmap[x][y] && mmap[tx][ty]) {
            ans++;
            check[tx][ty] = 1;
            que.push({tx, ty});
            func(tx, ty);

        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> (&mmap[i][1]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (check[i][j] == 0) {
                ans = 1;
                check[i][j] = 1;
                que.push({i, j});
                func(i, j);
                while (!que.empty()) {
                    node temp = que.front();
                    que.pop();
                    check[temp.x][temp.y] = ans;
                }
            }
        }
    }
    for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		cout << check[a][b] << endl;
	}

    return 0;
}
