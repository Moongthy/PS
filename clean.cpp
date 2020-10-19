#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 987654321
#define NEGINF -987654321
#define rep(i, a) for(int i = 0; i < a; ++i)
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FASTIO cin.tie(NULL);ios_base::sync_with_stdio(false);

int N, M, P[20];

struct dayInfo{
    int i;
    int j;
    int k;
};

const int max_day = 10;
const int max_dirty = 1000;
const int max_clean = 10;

int getDirty(){

    
    queue<dayInfo> q;
    // days 일에 clean번의 청소가 남고 k의 더러움일 때 지금까지느낀 덜어움의 총합의 최솟값
    int dp[max_day][max_clean][max_dirty];
    q.push({0, M, 0});
    dp[0][M][0] = 0;

    
    
    
    
    
}

int main(){
    FASTIO

    cin >> N >> M;
    for(int i = 1; i <= N; ++i) cin >> P[i];
    P[0] = 0;

    cout << getDirty() << endl;
    return 0;

}