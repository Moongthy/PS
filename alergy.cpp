#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)
#define ll long long
int N, M, best;
vector<string> friends;
// 각 친구가 먹을 수 있는 음식 목록
vector<vector<int>> friendsFood;
// 각 음식을 먹을 수 있는 친구들 목록
vector<vector<int>> foodsFriend;

void countFood(int cook, ll eaten){ 
    if(cook >= best) return;
    if(N == __builtin_popcount(eaten)){best = cook; return;}
    f(nextFriend, 0, N){
        if(eaten & (1<<nextFriend)) continue;
        f(i, 0, friendsFood[nextFriend].size()){
            ll newEaten = eaten;
            int nextFood = friendsFood[nextFriend][i];
            f(j, 0, foodsFriend[nextFood].size())
                newEaten |= (1<<foodsFriend[nextFood][j]);
            countFood(cook+1, newEaten);
        }
        break;
    }
}

void solve(){
    best = 987654321;
    friends.clear();
    friendsFood.clear();
    foodsFriend.clear();
    cin >> N >> M;
    friendsFood = vector<vector<int>>(N);
    f(i, 0, N){
        string f;
        cin >> f;
        friends.push_back(f);
    }
    f(i, 0, M){
        int n;
        cin >> n;
        vector<int> fr;
        f(j, 0, n){
            string f;
            cin >> f;
            f(k, 0, friends.size())
                if(f == friends[k]){
                    friendsFood[k].push_back(i);
                    fr.push_back(k);
                }
        }
        foodsFriend.push_back(fr);
    }
   countFood(0, 0);
   cout << best << endl;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();

    return 0;
}