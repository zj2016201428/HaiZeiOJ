/*************************************************************************
	> File Name: 535.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  3/19 11:46:13 2020
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
char mmap[55][55];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

void func(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (mmap[tx][ty] == '.') {
            mmap[tx][ty] = 0;
            ans++;
            func(tx, ty);
        }
    }
    return ;
}

int main() {
    cin >> m >> n;
   /* for (int i = 1; i <= m; i++) {
        cin >> (&mmap[i][1]);
    }
*/
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //cin >> mmap[i][j];
            if (mmap[i][j] == '@') {
                sx = i;
                sy = j;
            }
        }
    }
    func(sx, sy);
    cout << ans << endl;
    return 0;
}
