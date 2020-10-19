#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)
#define rep(a, n) for(int a = 0; a < n; ++a)
#define MAXN 111
#define MAXM 111
#define INF 987654321

// M : 행
// N : 열
// L : 한 칸 움직이는 데 걸리는 시간
// G : 연료

int M, N, L, G, costRow[MAXM][MAXN], costCol[MAXM][MAXN];

int cache[MAXM][MAXN][2][MAXM+MAXN];
int bestTime;
// 현재 위치 y, x, dir 방향이고, turn번 방향을 바꾸었을 때, 현재까지 쓴 최소 연료.
int measureCost(int y, int x, int dir, int turn, int cost){
    if(y < 0 || x < 0) return INF;

    if(y == 0 && x == 0 && turn == 0) {
        if(cost <= G){
            int time = (M+N-2)*L+turn;
            if(time < bestTime) bestTime = time;
        }
        return 0 ;
    }

    int& ret = cache[y][x][dir][turn];
    if(ret != -1) return ret;

    if(dir) return ret = min(measureCost(y, x-1, dir, turn, cost + costRow[y][x-1]) + costRow[y][x-1] , measureCost(y-1, x, !dir, turn-1, cost + costCol[y-1][x]) + costCol[y-1][x] );

    else return ret = min(measureCost(y-1, x, dir, turn, cost + costCol[y-1][x]) + costCol[y-1][x],
                        measureCost(y, x-1, !dir, turn-1, cost + costRow[y][x-1]) + costRow[y][x-1] );
}

void solve(){
    bestTime = INF;
    memset(cache, -1, sizeof(cache));

    cin >> M >> N >> L >> G;
    rep(i, M)
        rep(j, N-1)
            cin >> costRow[i][j];

    rep(i, M-1)
        rep(j, N)
            cin >> costCol[i][j];
    
    rep(i, MAXN+MAXM){
        measureCost(M-1, N-1, true, i, 0);
        measureCost(M-1, N-1, false, i, 0);
    }
    cout << bestTime << endl;
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}