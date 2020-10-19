#include<bits/stdc++.h>

using namespace std;

int r, c;
int len;
int cache[200][100][100];
const int MOD = 1000000007;

bool isNear(int a, int b, int i, int j){
    if(a == i && b == j) return true;
    if(abs(a-i) == 1 && (b == j || abs(b-j) == 1)) return true;
    if(abs(b-j) == 1 && (a == i || abs(a-i) == 1)) return true;
    return false;
}


int solve(int n, int a, int b){
    
    if(n == 0) return 1;
    
    int& ret = cache[n][a][b];
    if(ret != - 1) return ret;

    ret = 0;
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            if(!isNear(a, b, i, j))
                ret = (ret + solve(n-1, i, j)) % MOD;

    return ret;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));
    cin >> r >> c >> len;
    int ret = 0;
    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            ret = (ret + solve(len-1, i, j)) % MOD;
        
    
    cout << ret; 
    return 0;
}