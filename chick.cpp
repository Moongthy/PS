#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(ll a = b; a < c; ++a)
#define ll long long
const ll mod = 100000007;
ll K, N;
vector<vector<ll>> mat;

vector<vector<ll>> dot(const vector<vector<ll>>& A, const vector<vector<ll>>& B){
    vector<vector<ll>> ret(K, vector<ll>(K, 0));
    f(i, 0, K)
        f(j, 0, K)
            f(l, 0, K)
                ret[i][j] = (ret[i][j] + A[i][l]*B[l][j]) % mod;
    return ret;
}

vector<vector<ll>> POW(const vector<vector<ll>>& A, ll m){
    vector<vector<ll>> ret(K, vector<ll>(K, 0));
    if(m == 0){
        f(i, 0, K) ret[i][i] = 1;
        return ret;
    }
    if(m%2>0) return dot(POW(A, m-1), A);
    vector<vector<ll>> half = POW(A, m/2);
    return dot(half, half);
}

ll base(ll N){
    ll n = 2;
    f(i, 0, N-1){
        n = (n*2)%mod;
    }
    return n;
}

void solve(){
    cin >> K >> N;
    K++;
    mat = vector<vector<ll>>(K, vector<ll>(K, 0));
    if(K==1){
        mat = vector<vector<ll>>(2, vector<ll>(2, 1));
        ++K;
    }
    else{
        mat[0][0] = mat[0][K-1] =1;
        f(i, 0, K-1) mat[i+1][i] = 1;
    }

    vector<vector<ll>> ret;
    ret = POW(mat, N);
    ll chick = 0;
    f(i, 0, ret[K-1].size())
        chick = (chick + ret[K-1][i]) % mod;
    cout << chick << endl;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}