#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)
#define rep(a, n) for(int a = 0; a < n; ++a)
int N, best;
vector<int> seq;
const int MAX = 248;

int getMax(int start, int end){
   	FAST;
	int n, d[MAX][MAX]{ 0 }, ans=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d[i][i];
		ans = max(ans, d[i][i]);
	}
	
	for (int sz = 1; sz < n; sz++) {

		for (int i = 0; i + sz < n; i++) {

			for (int k = i; k < i+sz; k++) {
                         
				if (d[i][k] == d[k + 1][i + sz]) 
                    d[i][i + sz] = max(d[i][i + sz], d[i][k] + 1);
	
    			ans = max(ans, d[i][i + sz]);
			}
		}
	}

	cout << ans << '\n';
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    seq = vector<int>(N);
    rep(i, N) cin >> seq[i];
    best = 0;
    cout << getMax(seq) << endl;
    return 0;
}