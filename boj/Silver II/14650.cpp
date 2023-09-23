#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N, ans;

void backtrack(int x, int n) {
	if (n == N) {
		if (x && x % 3 == 0) {
			ans++;
		}
		return;
	}
	for (int i=0;i<3;i++) {
		if (x == 0 && i == 0)
			continue;
		backtrack(x * 10 + i, n + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	backtrack(0, 0);
	cout << ans << endl;

	return 0;
}
