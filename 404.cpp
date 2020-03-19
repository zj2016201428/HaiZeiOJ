/*************************************************************************
	> File Name: 404.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  3/19 11:45:36 2020
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

int n, m, ans = 1, sx, sy;
char mmap[3005][3005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int check[3005][3005];//去重数组
void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];

        if (tx < 1 || ty < 1 ||tx > n || ty > m) continue;//越界，忽略，继续
        if (mmap[tx][ty] != mmap[x][y] && check[tx][ty] == 0) {
            check[tx][ty] = 1;
            ans++;
            func(tx, ty);
        }
    }
}


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> (&mmap[i][1]);
    }
    cin >> sx >> sy;
    check[sx][sy] = 1;
    func(sx, sy);
    cout << ans << endl;
    return 0;
}
