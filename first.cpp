
#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)

const int MAX = 2000000000+1;
// 주어지는 수열의 길이
int n, k;

// cacheLen[start] = start에서 시작하는 증가 부분 수열의 최대 길이
int cacheLen[501];

// cacheLen[start] = start에서 시작하는 최대 증가 부분 수열의 수
int cacheCnt[501];

// Sequence
int S[500];

// S[start]에서 시작하는 증가 부분 수열 중 최대 길이를 반환한다.
int lis(int start){
    int &ret = cacheLen[start+1];
    if(ret != -1) return ret;
    // 항상 S[start]는 있기 때문에 길이는 최하 1
    ret = 1;
    f(next, start+1, n)
        if(start == -1 || S[start] < S[next])
            ret = max(ret, lis(next)+1);
    return ret;
}

// S[start]에서 시작하는 최대 증가 부분 수열의 수를 반환한다.
int count(int start){
    // 기저사례 : LIS의 길이가 1인 경우
    if(lis(start) == 1) return 1;
    // 메모이제이션
    int &ret = cacheCnt[start+1];
    if(ret != -1) return ret;
    ret = 0;
    f(next, start+1, n){
        // S[next] > S[start]
        // start의 증가부분수열최대길이 == next의 증가부분수열최대길이+1
        if((start == -1 || S[start] < S[next]) && (lis(start) == lis(next)+1))
            
    }
    return ret;
}

// S[start]에서 시작하는 LIS중 사전순으로  skip개 건너뛴 수열을 lis에 저장한다.
void reconstruct(int start, int skip, vector<int>& LIS){
    // 1. S[start]는 항상 LIS에 포함된다.
    if(start != -1) LIS.push_back(S[start]);
    // 2. 뒤에 올 수 있는 숫자들과 위치의 목록을 만든다.
    //    (숫자, 숫자의 위치)의 목록이 된다.
    vector<pair<int, int>> followers;
    f(next, start+1, n)
        if((start == -1 || S[start] < S[next]) && lis(start) == lis(next)+1)
            followers.push_back(make_pair(S[next], next));
    sort(followers.begin(), followers.end());
    // 3. k번째 LIS의 다음숫자를 찾는다.
    f(i, 0, followers.size()){
        int idx = followers[i].second;
        int cnt = count(idx);
        if(cnt <= skip)
            skip -= cnt;
        else{
            // 다음 숫자는 S[idx]임을 알았다.
            // 4. 재귀 호출을 통해
            reconstruct(idx, skip, LIS);
            break;
        }
    }
}

void solve(){
    memset(S, 0, sizeof(S));
    memset(cacheCnt, -1, sizeof(cacheCnt));
    memset(cacheLen, -1, sizeof(cacheLen));
    cin >> n >> k;
    f(i, 0, n) cin >> S[i];
    int len = lis(-1);
    count(-1);
    vector<int> LIS;
    reconstruct(-1, k-1, LIS);
    cout << len-1 << "\n";
    f(i, 0, LIS.size())
        cout << LIS[i] << " ";
    cout << endl;
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
