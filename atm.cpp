#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)

#define MAX_N 1000
int N;
vector<int> P;

int minWait(){
    // 오름차순으로 정렬
    sort(P.begin(), P.end());
    int ret = 0;
    int sum = 0;
    f(i, 0, P.size()){
        ret += P[i];
        sum += ret;
    }
    return sum;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    f(i, 0, N){
        int pi;
        cin >> pi;
        P.push_back(pi);
    }
    cout << minWait();
    return 0;
}