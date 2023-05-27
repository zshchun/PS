#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef tuple<ll,ll,ll,ll> tup;
#define endl "\n"
#define INF 123456789

int p[3001];

int find(int x) {
    if (p[x] < 0) {
        return x;
    }
    return (p[x] = find(p[x]));
}

void _union(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a != b) {
        p[a] += p[b];
        p[b] = a;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll T, N, x, y, r, i, j, nx, ny, nr, ans;
    cin >> T;
    while (T--) {
        cin >> N;
        ans = 0;
        fill(p, p+3001, -1);
        vector<tup> a;
        for (i=0;i<N;i++) {
            cin >> x >> y >> r;
            ans++;
            for (auto &t : a) {
                tie(j, nx, ny, nr) = t;
                ll dr = (r + nr) * (r + nr);
                ll dxy = (x - nx) * (x - nx) + (y - ny) * (y - ny);
                if (dr >= dxy && find(i) != find(j)) {
                    _union(i, j);
                    ans--;
                }
            }
            a.push_back(tup(i, x, y, r));
        }

        cout << ans << endl;
    }
    return 0;
}
