/*************************************************************************
	> File Name: 536.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  3/19 11:43:18 2020
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

int n, m, ans, flag, mmax;
char mmap[105][105];
int answer[1000];

int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

void func(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if (mmap[tx][ty] == '1') {
			mmap[tx][ty] = 0;
			ans++;
			func(tx, ty);
		}
	}
	return ;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mmap[i][j];
			}
		}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mmap[i][j] == '1') {
				mmap[i][j] = 0;
				ans = 1;
				func(i,j);
				mmax = max(mmax,ans);
			}
		}
	}
	cout << mmax << endl;
	return 0;
}
