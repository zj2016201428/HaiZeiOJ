/*************************************************************************
	> File Name: 235.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  3/19 11:39:35 2020
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

int num[15], cnt, n;

void output() {
    for (int i = 0; i < cnt; i++) {
        if (i) cout << " ";
        cout << num[i];
    }
    cout << endl;
}
//自己画一棵树就明白了，模拟一下代码执行过程
void func(int s) {
    for (int i = s; i <= n; i++) {
        num[cnt++] = i;
        //cnt++;
        output();
        func(i + 1);
        cnt--;
    }
}

int main() {
    cin >> n;
    func(1);

    return 0;
}
