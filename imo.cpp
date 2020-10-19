#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 987654321
#define NEGINF -987654321
#define rep(i, a) for(int i = 0; i < a; ++i)
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FASTIO cin.tie(NULL);ios_base::sync_with_stdio(false);

#define MAX_S 1000

int S, cache[1000][1000];

// 모니터에 moniter개의 이모티콘을 쓰는 최소시간
int imo(int clipboard, int moniter){
    
    int& ret = cache[clipboard][moniter];
    if(ret != -1) return ret;
    
    
}

int main(){

    FASTIO
    cin >> S;
    memset(cache, -1, sizeof(cache));
   
    cout << imo(0, 1) << endl;
    return 0;
}
