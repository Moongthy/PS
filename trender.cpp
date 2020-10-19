#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)
#define ll unsigned long long

const int MOD = 1000000000+7;
int N, K, cache[51][1501];
vector<vector<string>> bucket;

// smaller이 larger의 부분 연속 문자열인가?
// time complexity : O((M-N)N) <- 무적권 시간초과. KMP써야됨
// 좆같네,,,

bool isSub(const string& smaller, const string& larger){
    if(larger == larger[0]+smaller) return true;
    if(larger == smaller+larger[larger.size()-1]) return true;
    return false;
}

// count 경우의 수 when choose k-th player in n-th bucket
// time complexity : O()
int count(int n, int k){

    // base case : 1 ~ N번쨰 플레이어를 모두 선택함. 경우의 수 1 추가.
    if(n == 0) return 1;

    int& ret = cache[n][k];
    if(ret != -1) return ret;

    ret = 0;
    f(nextK, 0, K)
        if(isSub(bucket[n-1][nextK], bucket[n][k]))
            ret = (ret + count(n-1, nextK)) % MOD;

    return ret;
}

void solve(){
    memset(cache, -1, sizeof(cache));

    cin >> N >> K;
    
    f(i, 0, N){
        vector<string> buck;
        f(j, 0, K){
            string tmp;
            cin >> tmp;
            buck.push_back(tmp);
        }
        bucket.push_back(buck);
    }

    int ret = 0;
    f(i, 0, K) {
        ret = (ret + count(N-1, i)) % MOD;
    }
    cout << ret << endl;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}