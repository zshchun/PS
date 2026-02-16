#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int H, W, N, M, x, y;
	cin >> H >> W >> N >> M;
	x = (W + M) / (M + 1);
	y = (H + N) / (N + 1);
	cout << x * y << endl;
	return 0;
}
