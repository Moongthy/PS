#include<bits/stdc++.h>

using namespace std;
#define MAX 105
#define f(a, b, c) for(int a = b; a < c; ++a)

int h, w;
bool visited[MAX][MAX];
vector<string> m;
string key;
vector<pair<char, pair<int, int>>> door;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

bool hasKey(char c){
    int k = c - 'A';
    f(i, 0, key.size())
        if(key[i]-'a' == k){
            return true;
        }
    return false;
}

vector<int> hasDoor(char c){
    vector<int> doorlist;
    int k = c - 'a';
    f(i, 0, door.size())
        if(door[i].first-'A' == k)
            doorlist.push_back(i);
    return doorlist;
}

int docCnt(int y, int x){
    int ret = 0;
    queue<pair<int,int>> pq;
    pq.push(make_pair(y, x));
    while(!pq.empty()){
        pair<int,int> here = pq.front();
        int herey = here.first;
        int herex = here.second;
        pq.pop();
        visited[herey][herex] = true;
        if(m[herey][herex] == '*') continue;
        if(m[herey][herex] == '$') ++ret;
        if(m[herey][herex] >= 'a' && m[herey][herex] <= 'z') {
            key += m[herey][herex];
            vector<int>dl = hasDoor(m[herey][herex]);
            if(dl.size() > 0)
                f(i, 0, dl.size())
                    pq.push(make_pair(door[i].second.first, door[i].second.second));
        }
        if(m[herey][herex] >= 'A' && m[herey][herex] <= 'Z'){
            if(!hasKey(m[herey][herex])){
                door.push_back(make_pair(m[herey][herex], make_pair(herey, herex)));
                continue;
            }
        }
        m[herey][herex] = '.';
        
        f(i, 0, 4){
            int ny = herey + dy[i];
            int nx = herex + dx[i];
            if(ny < 0 || nx < 0 || ny > h-1 || nx > w-1) continue;
            if(visited[ny][nx]) continue;
            char there = m[ny][nx];
            // 열쇠, 열쇠있는 문, 빈길, 문서
            pq.push(make_pair(ny, nx));
        }
    }
    return ret;
}


void solve(){
    cin >> h >> w;
    memset(visited, false, sizeof(visited));
    m = vector<string>(h, string(""));
    door.clear();
    f(i, 0, h)
        cin >> m[i];
    cin >> key;
    if(key == "0") key = "";
    int ret = 0;
    f(i, 0, w) ret += (docCnt(0, i)+docCnt(h-1, i));
    f(i, 1, h-1) ret += (docCnt(i, 0)+docCnt(i, w-1));
    cout << ret << endl;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}