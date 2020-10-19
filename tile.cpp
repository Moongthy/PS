#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)
#define MAX_N 3000
#define ll long long
int N, tile[MAX_N], cache[MAX_N][MAX_N];

// 현재 밟은 타일의 수
// 간격
// 일 때, 연속적으로 밟을 수 있는 타일의 수
// -> 최대 합?

int seqLen(int here, int prev){

    int& ret = cache[here][prev];
    if(ret != -1) return ret;

    ret = tile[here];
    f(next, here+1, N)
        if(tile[next]-tile[here] == tile[here]-tile[prev])
            return ret = tile[here] + seqLen(next, here);

    return ret;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));
    cin >> N;
    f(i, 0, N) cin >> tile[i];
    
    int ret = 0;
    f(i, 0, N){
        f(j, i+1, N){
            int tmp = tile[i] + seqLen(j, i);
            if(tmp == tile[i]+tile[j]) tmp = 0;
            ret = max(ret, tmp);
        }
    }

    cout << ret << endl;
    return 0;
}