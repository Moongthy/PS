#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)
#define rep(a, n) for(int a = 0; a < n; ++a)
#define MAX_N 20
#define MAX_COST 20000
#define MAX_BUDGET 100000
int n, m, cost[MAX_N], favor[MAX_N], cache[MAX_BUDGET];

int getMaxFavorSum(int budget){
    int& ret = cache[budget];
    if(ret != -1) return ret;

    ret = 0;
    rep(i, n)
        if(budget >= cost[i])
            ret = max(ret, getMaxFavorSum(budget-cost[i]) + favor[i]);
    return ret;
}

int sushi2(){
    int ret = 0;
    for(int budget = 1; i <= m; ++budget){
        c[budget] = 0;
        for(int dish = 0; dish < n; ++dish)
            if(budget >= cost[dish])
                c[budget] = max(c[budget], c[budget - cost[dish] + favor[dish]]);
        ret = max(ret, c[budget]);
    }
    return ret;
}

void solve(){
    cin >> n >> m;
    rep(i, n) cin >> cost[i] >> favor[i];
    memset(cache, -1,sizeof(cache));
    cout << getMaxFavorSum(m) << endl;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
