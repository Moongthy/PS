#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)
#define rep(a, n) for(int a = 0; a < n; ++a)

int M, N, L, G, costCol[100][100], costRow[100][100];

// y, x에서 gas만큼 연료를 가지고 dir방향 일 떄, 목적지까지 가는 최소 시간. 
dp[y][x][2][gas]
int getMinTime(){
    
    for(int y = 1; y <= M; ++y)
        for(int x = 1; x <= N; ++x)
            for(int gas = 0; gas <= G; ++gas)
                for(int dir = 0; dir < 2; ++dir)
                    if(dir == 0)
                        if(gas >= costCol[y][x] && gas >= costRow[y][x])
                            dp[y][x][gas][dir] = min(dp][y+1][x][gas-costCol[y][x]][dir]+L, dp[y][x+1][gas-costRow[y][x]][!dir]+1+L);
                        else if(gas >= costCol[y][x])
                            dp[y][x][gas][dir] = min(dp[y][x][gas][dir], dp[y+1][x][gas-costCol[y][x][dir]]+L);
                        else if(gas >= costRow[y][x])
                            dp[y][x][gas][!dir] = min(dp[y][x][gas][!dir], dp[y+1][x][gas-costCol[y][x][dir]]+L+1);
                    else if(dir == 1)
                        if(gas >= costCol[y][x] && gas >= costRow[y][x])
                            dp[y][x][gas][dir] = min(dp][y+1][x][gas-costCol[y][x]][dir]+L, dp[y][x+1][gas-costRow[y][x]][!dir]+1+L);
                        else if(gas >= costCol[y][x])
                            dp[y][x][gas][dir] = min(dp[y][x][gas][dir], dp[y+1][x][gas-costCol[y][x][dir]]+L);
                        else if(gas >= costRow[y][x])
                            dp[y][x][gas][!dir] = min(dp[y][x][gas][!dir], dp[y+1][x][gas-costCol[y][x][dir]]+L+1);


}

void solve(){
    cin >> M >> N >> L >> G;
    rep(i, M)
        rep(j, N-1)
            cin >> costRow[i][j];
    rep(i, M-1)
        rep(j, N)
            cin >> costCol[i][j];
    cout << getMinTime() << endl;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
