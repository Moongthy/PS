#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 987654321
#define NEGINF -987654321
#define rep(i, a) for(int i = 0; i < a; ++i)
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FASTIO cin.tie(NULL);ios_base::sync_with_stdio(false);

const int maxN = 50;
const int maxK = 100;

int N, K, M, m[maxN], favor[10], cache[maxK][maxN];
vector<double> adj[maxN];



bool isFavor(int music){
    rep(i, M)
        if(music == favor[i])
            return true;
    return false;
}

vector<double> getP(){
    double dp[maxK][maxN];
    rep(i, maxK) rep(j, maxN) dp[i][j] = 0;
    // 해당 시간일 때, 노래일 확률
    queue<pair<int, int>> q;
    dp[0][0] = 1;
    q.push({0, 0});
    vector<double> favorP(M, 0);
    while(!q.empty()){
        int currTime = q.front().first;
        int currMusic = q.front().second;
        double& currP = dp[currTime][currMusic];
        q.pop();
        for(int nextMusic = 0; nextMusic < N; ++nextMusic){
            int nextTime = currTime + m[currMusic];
            double& nextP = dp[nextTime][nextMusic] = currP * adj[currMusic][nextMusic];
           if(nextTime >= K){
               if(isFavor(nextMusic)) favorP[nextMusic] += nextP;
               continue;
           }
           q.push({nextTime, nextMusic});
        }
    }

    return favorP;
}

void solve(){
    cin >> N >> K >> M;
    rep(i, N) cin >> m[i];
    rep(i, N){
        rep(j, N){
            double p;
            cin >> p;
            adj[i].push_back(p);
        }
    }
    rep(i, M) cin >> favor[i];
    vector<double> ans = getP();
    rep(i, ans.size()) cout << ans[i] << " ";
    cout << endl;
}

int main(){
    FASTIO
    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}