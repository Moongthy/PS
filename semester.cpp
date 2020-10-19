#include<bits/stdc++.h>

using namespace std;
#define MAXN 12

const int INF = 987654321;
int n, k, m, l;

// prerequisite[i] = i번째 과목의 선수과목의 집합
int prerequisite[MAXN];
// classes[i] = i번째 학기에 개설되는 과목의 집합
int classes[10];
int cache[10][1<<MAXN];
// n의 이진수 표현에서 켜진 비트의 수를 반한다.
int bitCount(int n);

// 이번학기가 semester이고, 지금까지 들은 과목의 집합이 taken일 때
// k개 이상의 과목을 모두 들으려면 몇 학기나 더 있어야 하는가?
// 불가능한 경우 INF를 반환한다.

int graduate(int semester, int taken){
    // 기저 사례 : k개 이상의 과목을 이미 들은 경우
    if(__builtin_popcount(taken) >= k) return 0;
    // 기저 사례 : m 학기가 전부 지난 경우
    if(semester == m) return INF;
    // 메모이제이션
    int& ret = cache[semester][taken];
    if(ret != -1) return ret;
    ret = INF;
    // 이번 학기에 들을 수 있는 과목 중 아직 듣지 않은 과목들을 찾는다.
    // classes[semester]과 taken중 둘다 1인 비트를 끈다. 비트제거.
    int canTake = (classes[semester] & ~taken);
    // 선수과목을 다 듣지 않은 과목들을 걸러낸다.
    for(int i = 0; i < n; ++i)
        if((canTake & (1 << i)) && // canTake의 켜진 비트 (이번 학기의 열리는 강의들 중, 아직 듣지 않은 과목)
         (taken & prerequisite[i]) != prerequisite[i]) // i번째 과목의 선수과목들중 내가 들은 과목 != i번째 과목을 듣기 위해서 들어야하는 과목 
            canTake &= ~(1 << i); // canTake에서 i번째 과목을 뺌.
    // 이 집합의 모든 부분집합을 순회한다.
    for(int take = canTake; take > 0; take = (take-1) & canTake){
        // 한 학기에 l 과목까지만 들을 수 있다.
        if(__builtin_popcount(take) > l) continue;
        ret = min(ret, graduate(semester+1, taken | take) + 1);
    }
    // 이번 학기에 아무 것도 듣지 않았을 경우
    ret = min(ret, graduate(semester+1, taken));
    return ret;
}


void solve(){
    memset(prerequisite, 0, sizeof(prerequisite));
    memset(cache, -1, sizeof(cache));
    memset(classes, 0, sizeof(classes));
    cin >> n >> k >> m >> l;
    
    // i번째 과목의 선수과목들을 입력받음.
    for(int i = 0; i < n; ++i){
        int preNum;
        cin >> preNum;
        for(int j = 0; j < preNum; ++j){
            int pre;
            cin >> pre;
            prerequisite[i] |= (1 << pre);
        }
    }

    // i번째 학기에 개설되는 과목들을 입력받음.
    for(int i = 0; i < m; ++i){
        int classNum;
        cin >>classNum;
        for(int j = 0; j < classNum; ++j){
            int cl;
            cin >> cl;
            classes[i] |= (1 << cl);
        }
    }
    // 결과 출력
    int ret = graduate(0, 0);
    if(ret == INF) cout << "IMPOSSIBLE" << endl;
    else cout << ret << endl;
}

int main(){   
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
        solve();   
    return 0;
}