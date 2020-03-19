/*************************************************************************
	> File Name: 83.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  3/19 11:47:11 2020
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
int num[10], cnt;

void output() {
    for (int i = 0; i < cnt; i++) {
        if (i == cnt - 1) cout << num[i];
        else cout << num[i] << "+";
    }
    cout << endl;
    return ;
}
//花树状图，模拟下函数，不成立的情况也加到ans里了，只不过返回是0，加0.
//s：从几开始 left_num：剩下的数值， left_cnt: 剩下的份数
int func(int s, int left_num, int left_cnt) {
    if (left_cnt == 0) {
        if (left_num == 0) {
            output();
            return 1;
        }
        return 0;
    }
    int ans = 0;
    for (int i = s; i <= left_num; i++) {
        num[cnt++] = i;
        ans += func(i, left_num - i, left_cnt - 1);

        cnt--;
    }
    return ans;
}


int main() {
    int n, m;
    cin >> n >> m;
    cout << func(1, n, m) << endl;
    return 0;
}
