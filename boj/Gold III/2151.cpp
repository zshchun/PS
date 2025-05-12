#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 1234567890
#define EMPTY 0
#define WALL 1
#define MIRROR_EMPTY 2
#define MIRROR_1 3
#define MIRROR_3 4
#define KEEP_EMPTY 5

int N, ans = INF;
int a[51][51];
bool visited[51][51][4][2500];

vector<pa> door;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void dfs(int y, int x, int d, int cnt) {
        int nx, ny, nd;
        if (ans <= cnt) return;
        if (y == door[1].first && x == door[1].second) {
                ans = min(ans, cnt);
                return;
        }
        if (a[y][x] == WALL || visited[y][x][d][cnt]) return;
        visited[y][x][d][cnt] = 1;
        //visited[y][x][d] = 1; // low memory, more latency
        if (a[y][x] == EMPTY || a[y][x] == KEEP_EMPTY) {
                ny = y + dy[d];
                nx = x + dx[d];
                if (ny >= 0 && ny < N && nx >= 0 && nx < N)
                    dfs(ny, nx, d, cnt);
        } else if (a[y][x] == MIRROR_EMPTY) {
                a[y][x] = KEEP_EMPTY;
                ny = y + dy[d];
                nx = x + dx[d];
                if (ny >= 0 && ny < N && nx >= 0 && nx < N)
                    dfs(ny, nx, d, cnt);
                a[y][x] = MIRROR_3;
                nd = (d+3)%4;
                ny = y + dy[nd];
                nx = x + dx[nd];
                if (ny >= 0 && ny < N && nx >= 0 && nx < N)
                        dfs(ny, nx, nd, cnt+1);
                a[y][x] = MIRROR_1;
                nd = (d+1)%4;
                ny = y + dy[nd];
                nx = x + dx[nd];
                if (ny >= 0 && ny < N && nx >= 0 && nx < N)
                        dfs(ny, nx, nd, cnt+1);
                a[y][x] = MIRROR_EMPTY;
        } else if (a[y][x] == MIRROR_1) {
                nd = (d+1)%4;
                ny = y + dy[nd];
                nx = x + dx[nd];
                if (ny >= 0 && ny < N && nx >= 0 && nx < N)
                        dfs(ny, nx, nd, cnt);
        } else if (a[y][x] == MIRROR_3) {
                nd = (d+3)%4;
                ny = y + dy[nd];
                nx = x + dx[nd];
                if (ny >= 0 && ny < N && nx >= 0 && nx < N)
                        dfs(ny, nx, nd, cnt);
        }
        //visited[y][x][d] = 0;
}      

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int i, j, d;
        char c;
        cin >> N;
        for (i=0;i<N;i++) {
                for (j=0;j<N;j++) {
                        cin >> c;
                        if (c == '*')
                                a[i][j] = WALL;
                        else if (c == '!')
                                a[i][j] = MIRROR_EMPTY;
                        else if (c == '#')
                                door.push_back(pa(i, j));
                }
        }

        for (i=0;i<4;i++) {
            memset(visited, 0, sizeof(visited));
            dfs(door[0].first, door[0].second, i, 0);
        }
        cout << ans << endl;
        return 0;
}

