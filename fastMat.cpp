#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)


/*행렬의 거듭제곱 빨리 구하는 법.*/
/*      분할정복              */


// 정방 행렬을 표현하는 SquareMatrix 클래스
class SquareMatirx{
    public:

        int size;
        vector<vector<int>> Mat;

        // 생성자
        SquareMatirx(vector<vector<int>>& Mat) : size(Mat.size()), Mat(Mat) { }

        // * 오버로딩
        SquareMatirx operator*(const SquareMatirx &ref){
            vector<vector<int>> ret(size, vector<int>(size, 0));
            for(int i = 0; i < size; ++i)
                for(int j = 0; j < size; ++j)
                    for(int k=  0; k < size; ++k)
                        ret[i][j]  = (ret[i][j] + Mat[i][k] * ref.Mat[k][j]) % 1000;
            return SquareMatirx(ret);
        }

        void show(){
            for(int i = 0; i < size; ++i){
                for(int j = 0; j < size; ++j)
                    cout << Mat[i][j] << " ";
                cout << "\n";
            }
            cout << endl;
        }
};


SquareMatirx identity(int n){
    vector<vector<int>> id(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) id[i][i] = 1;
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

long long N, B;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> B;
    vector<vector<int>> tmp(N, vector<int>(N, 0));
    f(i, 0, N)
        f(j, 0, N)
            cin >> tmp[i][j];
    SquareMatirx mat(tmp);
    Pow(mat, B).show();
    return 0;
}
