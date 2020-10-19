#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)

#define MAX 1500

int R, C;

vector<pair<int, int>> swan;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool lake[MAX][MAX];

bool isMeet(int y1, int x1, int y2, int x2){
    vector<vector<bool>> visited(R, vector<bool>(C, false));
    
    queue<pair<int,int>> q;
    q.push({y1, x1});

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        visited[cy][cx] = true;
        if(cy == y2 && cx == x2) return true;
        f(i, 0, 4){
            int ny = y1+dy[i];
            int nx = x1+dx[i];
            if(ny < 0 || nx < 0 || ny > R-1 || nx > C-1)
                continue;
            if(visited[ny][nx]) 
                continue;
            q.push({ny, nx});
        }
    }    
    return false;
}

void dayAfter(){
    f(i, 0, R)
        f(j, 0, C)
            if(lake[i][j])
                f(k, 0, 4){
                    int y = i+dy[k];
                    int x = i+dx[k];
                    if(y < 0 || x < 0 || y > R-1 || x > C-1)
                        continue;
                    if(!lake[y][x])
                }

        
}

int meetSwan(){
    int days = 0;
    while(!isMeet(swan[0].first, swan[0].second, swan[1].first, swan[1].second)){
        dayAfter();
        ++days;
    }
    return days;
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> R >> C;
    f(i, 0, R)
        f(j, 0, C){
            char x;
            cin >> x;
            lake[i][j] = (x == 'X') ? false : true; 
            if(x == 'L') swan.push_back({i, j});
        }

    cout << meetSwan() << endl;
    return 0;
}