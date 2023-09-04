#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, M, ans;
int a[100001];
int b[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
        cin >> N >> M;
        vector<pair<int,int>> p;
        int i, y, x;
        int sy = 0;
        int sx = 0;
        for (i=0;i<M;i++) {
                cin >> a[i] >> b[i];
        }
        sort(a, a+M);
        sort(b, b+M);
        y = a[M/2];
        x = b[M/2];
        ans = 0;
        for (i=0;i<M;i++) {
                ans += abs(a[i] - y);
                ans += abs(b[i] - x);
        }
        cout << ans << endl;
	return 0;
}
