/*************************************************************************
	> File Name: 237.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  3/19 11:40:50 2020
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
//没有顺序，每个组合都输出一次
int n, num[15], cnt, mark[15];//mark：标记已经输出过的数

void func(int left) {
    if (left == 0) {
        for (int i = 0; i < cnt; i++) {
            if (i) cout << " ";
            cout << num[i];
        }
        cout << endl;
        return;
    }
    //没有顺序，每个组合都输出一次,因此每次都从i = 1开始
    for (int i = 1; i <= n; i++) {
        if(mark[i] == 0) {
            mark[i] = 1;
            num[cnt++] = i;
            func(left - 1);
            cnt--;
            mark[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    func(n);

    return 0;
}
