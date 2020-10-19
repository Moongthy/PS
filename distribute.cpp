#include<bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define f(a, b, c) for(ll a = b; a < c; ++a)


// A = [1]
//     [1]
//     [1]

// W = [1 1 1]
//     [1 0 1]
//     [1 1 0]

// N층의 객실분배 경우의 수 = W^(N-1)*A의 원소의 합



const ll MOD = 1000000000+7;
class SquareMatirx{
    public:

        ll size;
        vector<vector<ll>> Mat;

        // 생성자
        SquareMatirx(vector<vector<ll>>& Mat) : size(Mat.size()), Mat(Mat) { }

        // * 오버로딩
        SquareMatirx operator*(const SquareMatirx &ref){
            vector<vector<ll>> ret(size, vector<ll>(size, 0));
            for(ll i = 0; i < size; ++i)
                for(ll j = 0; j < size; ++j)
                    for(ll k=  0; k < size; ++k)
                        ret[i][j]  = (ret[i][j] + Mat[i][k] * ref.Mat[k][j]) % MOD;
            return SquareMatirx(ret);
        }

        void show(){
            for(ll i = 0; i < size; ++i){
                for(ll j = 0; j < size; ++j)
                    cout << Mat[i][j] << " ";
                cout << "\n";
            }
            cout << endl;
        }
};


SquareMatirx identity(ll n){
    vector<vector<ll>> id(n, vector<ll>(n, 0));
    for(ll i = 0; i < n; ++i) id[i][i] = 1;
    return SquareMatirx(id);
}

// A^m을 반환한다.
SquareMatirx Pow(const SquareMatirx& A, long long m){
    //기저사례 : A^0 = I
    if(m == 0) return identity(A.size);
    if(m % 2 > 0) return Pow(A, m-1) * A;
    SquareMatirx half = Pow(A, m/2);
    // A^m = (A^(m/2)) * (A^(m/2))
    return half * half;
}

ll N;

ll distribute(ll floor){
    
    if(floor == 0) return 3;
    
    vector<vector<ll>> Wei;
    vector<ll> tmp0 = {1, 1, 1};
    vector<ll> tmp1 = {1, 0, 1};
    vector<ll> tmp2 = {1, 1, 0};
    Wei.push_back(tmp0);
    Wei.push_back(tmp1);
    Wei.push_back(tmp2);
    SquareMatirx W(Wei);
    SquareMatirx mat = Pow(W, floor);

    ll ret = 0;
    f(i, 0, 3)
        f(j, 0, 3)
            ret = (ret + mat.Mat[i][j]) % MOD;
    // mat.show();
    return ret;

}

int main(){
    
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    cout << distribute(N-1);
    return 0;
}