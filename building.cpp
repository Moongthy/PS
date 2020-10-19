#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)
#define MOD 1000000007
#define ll long long
ll fact[101];

ll factorial(int n){
    if(n == 1) return fact[n] = 1;
    return fact[n] = (n*factorial(n-1))%MOD;
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    factorial(100);
    f(i, 0, 101)
        cout << i << " : " << fact[i] << "\n";
    return 0;
}