#include<bits/stdc++.h>

using namespace std;

#define f(a, b, c) for(int a = b; a < c; ++a)

vector<int> moves;
// 일대일 대응 함수
inline int cell(int y, int x) { return 1 << (y * 5 + x); }

// 게임판에 놓을 수 있는 블록들의 위치를 미리 계산한다.
void precalc(){
    // 세칸 짜리 L자 모양 블록들을 계산한다.
    f(y, 0, 4)
        f(x, 0, 4){
            vector<int> cells;
            f(dy, 0, 2)
                f(dx, 0, 2)
                    cells.push_back(cell(y+dy, x+dx));
            int square = cells[0] + cells[1] + cells[2] + cells[3];
            f(i, 0, 4) moves.push_back(square-cells[i]);
        }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    return 0;
}