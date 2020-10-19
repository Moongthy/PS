#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)
#define ll long long
#define INF 987654321
ll price;
int cache[101];
int coin[3] = {1, 10, 25};
int cntLittle(int leftPrice){
    
    int& ret = cache[leftPrice];
    if(ret != -1) return ret;

    if(leftPrice < 10) return ret = leftPrice;

    ret = INF;
    for(int c : coin){
        if(leftPrice >= c)
            ret = min(ret, 1 + cntLittle(leftPrice - c));
    }
    return ret;
}

ll cnt(ll leftPrice){
    ll leftPrice1 = leftPrice / 100;
    ll leftPrice2 = leftPrice % 100;
    if(leftPrice > 100)
        return cnt(leftPrice1) + cntLittle((int)leftPrice2);
    else
        return cntLittle((int)leftPrice2);
}

void solve(){
    memset(cache, -1, sizeof(cache));
    cin >> price;
    cout << cnt(price) << "\n";
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}