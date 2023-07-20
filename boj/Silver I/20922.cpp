#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int a[200001];
int cnt[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, K, i, beg, end, l, r, ans = 0;
	cin >> N >> K;
	for (i=0;i<N;i++) {
		cin >> a[i];
	}
	l = 0;
	r = 0;
	while (l < N) {
		beg = a[l];
		end = a[r];
		if (cnt[beg] == K) {
			cnt[end]--;
			r++;
		} else {
			cnt[beg]++;
			l++;
		}
		ans = max(l - r, ans);
	}

	cout << ans << endl;

	return 0;
}
