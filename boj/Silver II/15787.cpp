#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, cmd, x, y, N, M;

	cin >> N >> M;
	vector<int> a(N);

	for (i=0;i<M;i++) {
		cin >> cmd >> x;
		x--;
		if (cmd == 1) {
			cin >> y;
			a[x] |= (1 << (y-1));
		} else if (cmd == 2) {
			cin >> y;
			a[x] &= ~(1 << (y-1));
		} else if (cmd == 3) {
			a[x] = (a[x] << 1) & 0xfffff;
		} else if (cmd == 4) {
			a[x] = (a[x] >> 1);
		}
	}

	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());

	cout << a.size() << endl;

	return 0;
}
