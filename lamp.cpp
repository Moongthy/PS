#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)
#define rep(n) for(int i = 0; i < n; ++i)


int K, N;
vector<int> lampsColor;
int cache[200][200];




// start ~ end까지 전구를 lampsColor[start]의 색깔로 바꾸는 최소 변환 횟수
int cntOn(int start, int end){
    // cout << start << " " << end << endl;
    if(start == end) return 0;

    int& ret = cache[start][end];
    if(ret != -1) return ret;

    ret = 987654321;
    for(int s = start; s < end; s++){
        int tmp = lampsColor[start] == lampsColor[s+1] ? 0 : 1;
        ret = min(ret, cntOn(start, s) + cntOn(s+1, end) + tmp);
    }

    return ret;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));
    cin >> N >> K;
    lampsColor = vector<int>(N+1, 0);
    for(int i = 1; i <= N; ++i){ cin >> lampsColor[i]; }
    

    cout << cntOn(1, N);
    return 0;
}