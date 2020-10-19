#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)

#define INF 987654321
#define MAX_N 101
#define MAX_M 10001
#define MAX_K 10001

int N, M, K;

// 시간, 비용, 위치
vector<pair<pair<int, int>, int>> board[MAX_N];

// dist[도착지][비용] = 도착점까지 소요비용을 써서 오는데 걸린 최소 시간.
vector<vector<int>> dist;

int minTime(int src){
    // 시간, 비용, 위치
    priority_queue<pair<pair<int,int>, int>> pq;
    dist[src][0] = 0;
    pq.push({{0, 0}, src});

    while(!pq.empty()){
        int here = pq.top().second;
        int curTime = -pq.top().first.first;
        int curCost = -pq.top().first.second;
        pq.pop();

        if(dist[here][curCost] < curTime) continue;
        if(curCost > M) continue;

        // 한번 큐에서 꺼내진 정점은 다시 갱신되지 않는다
        // 갱신은 큐에 넣을 때 하는 것.
        if(here == N-1) return curTime;

        f(i, 0, board[here].size()){
            int there = board[here][i].second;
            int nextTime = board[here][i].first.first + curTime;
            int nextCost = board[here][i].first.second + curCost;
            if(nextCost > M) continue;
            if(nextTime < dist[there][nextCost]){
                // here에서 there까지 nextCost보다 비싼돈을 써서 가는 시간중에, 
                // nextTime보다 크다면, 그들은 모두 nextTime으로 바꾼다.
                // A->B를 가는데 500원 1시간, 1000원 2시간 이라면, 2000원 30분
                // dist[B][500] = 1, dist[B][1000] = 1, dist[B][2000] = 0.5 
                f(j, nextCost+1, M+1){
                    if(dist[there][j] <= nextTime) break;
                    dist[there][j] = nextTime;
                }

                dist[there][nextCost] = nextTime;
                pq.push({{-nextTime, -nextCost}, there});
            }
        }
    }
    return -1;
}

void solve(){
    cin >> N >> M >> K;
    dist = vector<vector<int>>(N, vector<int>(MAX_M, INF));
    f(i, 0, N) board[i].clear();
    f(i, 0, K){
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        --u; --v;
        board[u].push_back({{d, c}, v});
    }
    int ret = minTime(0);
    if(ret != -1) cout << ret << endl;
    else cout << "Poor KCM" << endl;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}