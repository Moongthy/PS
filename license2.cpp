#include <bits/stdc++.h>
using namespace std;

int dp[111][111][222][2]; //x-pos, y-pos, change, dir
int distR[111][111];
int distC[111][111];

// dp[y][x][k][dir] : y,x에서 k번 방향을 바꿔서 현재 dir방향을 바라볼 때, 현재까지드는 연료의 최솟값.
void init(){
    // dp를 ????????로 초기화 한다.
	memset(dp, 0x3f, sizeof dp);
    // 0, 0에서 0번 방향을 바꿔서 오른쪽, 아래쪽을 바라보고 있을 때, 현재까지 쓴 연료의 최솟값.
	dp[0][0][0][0] = dp[0][0][0][1] = 0;
}   

void solve(){
	init();
	int n, m, l, g; //map, time, gas
	int ans = 1e9+7;
	cin >> n >> m >> l >> g;
	for(int i=0; i<n; i++) for(int j=0; j<m-1; j++) cin >> distR[i][j];
	for(int i=0; i<n-1; i++) for(int j=0; j<m; j++) cin >> distC[i][j];

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			for(int k=0; k<222; k++){
				// 오른쪽 이동
				if(i+1 < n){
					// 현재 방향이 
					dp[i+1][j][k][0] = min(dp[i+1][j][k][0], dp[i][j][k][0] + distC[i][j]);
					dp[i+1][j][k+1][0] = min(dp[i+1][j][k+1][0], dp[i][j][k][1] + distC[i][j]);
				}
				// 아래로 이동
				if(j+1 < m){
					dp[i][j+1][k][1] = min(dp[i][j+1][k][1], dp[i][j][k][1] + distR[i][j]);
					dp[i][j+1][k+1][1] = min(dp[i][j+1][k+1][1], dp[i][j][k][0] + distR[i][j]);
				}
			}
		}
	}

	for(int k=0; k<222; k++){
		if(dp[n-1][m-1][k][0] <= g){
			ans = min(ans, (n-1)*l + (m-1)*l + k);
		}
		if(dp[n-1][m-1][k][1] <= g){
			ans = min(ans, (n-1)*l + (m-1)*l + k);
		}
	}
	if(ans > 1e9) cout << -1 << "\n";
	else cout << ans << "\n";
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
}