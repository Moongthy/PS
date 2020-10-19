#include<bits/stdc++.h>

using namespace std;

#define ll unsigned long long
int M;
ll N;
const ll MOD = 1000000007;
vector<ll> C;
vector<vector<ll>> A;


// 정방행렬이든 아니든 곱해벌임.
vector<vector<ll>> dotMatrix(
    const vector<vector<ll>>& m1, const vector<vector<ll>>& m2){

    vector<vector<ll>>ret(m1.size(), vector<ll>(m1.size(), 0));
    
    for(int i = 0; i < ret.size(); ++i)
        for(int j = 0; j < ret.size(); ++j)
            for(int k = 0; k < ret.size(); ++k)
                ret[i][j] = (ret[i][j] + m1[i][k] * m2[k][j])%MOD;

    return ret;
}

vector<vector<ll>> identity(int size){
    vector<vector<ll>>id(size, vector<ll>(size, 0));
    for(int i = 0; i < size; ++i) id[i][i] = 1;
    return id;
}

// A는 정방행렬이다.
vector<vector<ll>> fastSqr(const vector<vector<ll>>& A, long long m){
    if(m == 0) return identity(A.size());
    if(m % 2 > 0) return dotMatrix(fastSqr(A, m-1), A);
    vector<vector<ll>> half = fastSqr(A, m/2);
    return dotMatrix(half, half); 
}

ll solve(){

    C = vector<ll>(M, 1);
    
    A = vector<vector<ll>>(M, vector<ll>(M, 0));
    for(int i = 0; i < M-1; ++i) A[i][i+1] = 1;
    A[M-1][0] = A[M-1][M-1] = 1;

    vector<vector<ll>> ret = fastSqr(A, N);
    
    ll ans = 0;
    for(int i =0; i < M; ++i)
        ans = (ans + (ret[0][i] * C[i])) % MOD;

    return ans;

}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;
    
    cout << solve();

    return 0;
}