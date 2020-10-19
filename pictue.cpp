#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)
#define MAX 15

// cost[i][j] : i가 j한테 그림을 파는 가격
int N, cache[MAX][10][1<<MAX];
string cost[MAX];

// 현재 소유자가 owner
// owner가  그림을 산 가격이 prevPrice
// 그림을 소유했던 사람들 owned
// 일 때, 소유했던 사람들의 최댓값
int maxOwn(int owner, int prevPrice, int owned){

    int& ret = cache[owner][prevPrice][owned];
    if(ret != -1) return ret;

    ret = 1;
    f(next, 0, N){
        if(owned & (1<<next)) continue;
        if(cost[owner][next]-'0' < prevPrice) continue;
        ret = max(ret, 1 + maxOwn(next, cost[owner][next]-'0', owned | (1<<next)));
    }
    return ret;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    f(i, 0, N)
        cin >> cost[i];
    
    int ret = 1;
    int owned = (1<<0);
    f(i, 1, N)
        ret = max(ret, 1 + maxOwn(i, cost[0][i]-'0', owned|(1<<i)));
    cout << ret << endl;

    return 0;
}