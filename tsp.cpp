#include<bits/stdc++.h>

using namespace std;

#define MAX 16
#define INF 1000000000
int n, dist[MAX][MAX];
// 1 << MAX = 2^MAX
// -1로 초기화함.
int cache[MAX][1<<MAX];
// here : 현재 위치
// visited : 각 도시의 방문 여부
// here에서 시작해 남은 도시들을 방문할 수 있는 최단 경로의 길이를 반환한다.
// 나머지 도시들을 모두 방문하는 경로들 중 가장 짧은 것의 길이를 반환한다.
// 항상 0번 도시부터 시작한다고 가정한다.
int shortPath2(int here, int visited){
    // 기저 사례 : 모든 도시를 다 방문했을 때는 0번 도시로 돌아가고 종료한다.
    // 모든 도시를 방문한 시점에서, 0번 도시로 가는 길이 없으면 INF반환
    if(visited == (1 << n)-1){
        if(dist[here][0])
            return dist[here][0];
        else 
            return INF;
    }
    // 메모이제이션
    int& ret = cache[here][visited];
    if(ret >= 0) return ret;

    ret = INF; // 매우 큰 값으로 초기화
    // 다음 방문할 도시를 전부 시도해 본다.
    for(int next = 0; next < n; ++next){
        // 이미 방문한 도시일 경우
        if(visited & (1 << next)) continue;
        // 갈수없는 도시일 경우
        if(!dist[here][next]) continue;
        int cand = dist[here][next] + shortPath2(next, visited + (1 << next));
        ret = min(ret, cand);
    }
    return ret;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    memset(cache, -1, sizeof(cache));
    memset(dist, 0, sizeof(dist));
    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> dist[i][j];
    cout << shortPath2(0, 1) << endl;
    return 0;
}