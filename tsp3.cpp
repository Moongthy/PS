#include<bits/stdc++.h>

using namespace std;

#define INF 987654321
#define f(a, b, c) for(int a = b; a < c; ++a)
#define MAXN 16

int N, locX[MAXN], locY[MAXN];
long double dist[MAXN][MAXN], cache[MAXN][1 << MAXN];


void initDist(){
    f(i, 0, N)
        f(j, 0, N){
            if(i == j) continue;
            dist[i][j] = (long double)sqrt((long double)pow(locX[i]-locX[j], 2) + (long double)pow(locY[i]-locY[j], 2));
        }
}

// 내 위치가 here, 방문한 도시들이 visited일 때
// 순회의 남은 경로에 필요한 최소 비용
long double tsp(int here, int visited){
    // 기저 사례 : 모든 도시를 방문 했을 때, 처음으로 가는 비용을 반환
    if(visited == (1 << N)-1) return dist[here][0];

    long double& ret = cache[here][visited];
    if(ret != 0) return ret;

    // 모든 도시들을 방문하면서, 최소 비용을 ret으로 함.
    ret = INF;
    f(next, 0, N){
        // 이미 방문한 도시
        if((1 << next) & visited) continue;
        long double cand = dist[here][next] + (ret, tsp(next, visited | (1 << next)));
        ret = min(ret, cand);
    }
    return ret;
}


int main(){
    cout << std::setprecision(20);
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(cache, 0, sizeof(cache));
    cin >> N;
    f(i, 0, N)
        cin >> locX[i] >> locY[i];
    initDist();
    // 0번 도시부터 출발.
    cout << tsp(0, (1 << 0)) << endl;
    return 0;
}