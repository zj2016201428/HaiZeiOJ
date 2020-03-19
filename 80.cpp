/*************************************************************************
	> File Name: 80.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  3/19 11:44:00 2020
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
//此种写法不符合题目输出要求，理解成能到输出yes，不能输出no。深搜没法求最小
//步数，广搜可以
int n, m, sx, sy;
char _map[505][505];
int dir[4][2]{1, 0, 0, 1, -1, 0, 0, -1};

int func(int x, int y) {
    //if (_map[x][y] == 'g') return 1;
    for (int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (_map[tx][ty] == 'g') return 1;
        if (_map[tx][ty] == '.') {
            _map[tx][ty] = 0;
            //此处为什么要返回1？ 因为上一层返回1此处是进入if里，要接着返回1
            //才能继续返回，才能形成递归。：
            if (func(tx, ty)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> _map[i][j];
            if (_map[i][j] == 's') {
                sx = i;
                sy = j;
            }
        }
    }
    if (func(sx, sy)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
