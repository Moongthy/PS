#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)
#define rep(a, n) for(int a = 0; a < n; ++a)
#define MAXN 30
#define MAXK 135

int N, K;

char actions[3] = {'A', 'B', 'C'};

cache[30][30][30][450];
int cntS(int n, int a, int b, int k){

    if(n == N)

    int& ret = cache[n][a][b][k];
    if(ret != -1) return ret;

    if(n == 0) ret = cnt(int )
}




int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> K;
    brute("");
    return 0;
}