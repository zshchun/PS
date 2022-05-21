#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[64];
#define ctz(x) __builtin_ctz(x)
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, i, N, v, w, W, h;
	cin >> T;
	while(T--) {
		cin >> N >> W;
		memset(a, 0, sizeof(a));
		for(i=0;i<N;i++) {
			cin >> v;
			a[ctz(v)]++;
		}
		h = 0;
		i=0;
		while (1) {
			w = W;
			for (i=20;i>=0;i--) {
				while (a[i] && w >= (1<<i)) {
					w -= 1<<i;
					a[i]--;
				}
			}
			if (w == W) break;
			h++;
		}
		cout << h << '\n';
	}
	return 0;
}
