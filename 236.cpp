/*************************************************************************
	> File Name: 236.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  3/19 11:44:33 2020
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
//搞懂235，236无非就是多了个left计数，达到left就输出返回
int n, m, num[15], cnt;

void func(int s, int left) {
    if (left == 0) {
        for (int i = 0; i < cnt; i++) {
            if (i) cout << " ";
            cout << num[i];
        }
        cout << endl;
        return ;
    }
    for (int i = s; i <= n - left + 1; i++) {
        num[cnt++] = i;
        func(i + 1, left - 1);
        cnt--;
    }
}

int main() {
    cin >> n >> m;
    func(1, m);

    return 0;
}
