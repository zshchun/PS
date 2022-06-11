#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T, i, v, N, M, ans;
	cin >>T;
	while (T--) {
		cin >> N >> M;
		memset(a, 0, sizeof(int)*(M+1));
		for(i=0;i<N;i++) {
			cin>>v;
			a[v % M]++;
		}
//		for(i=0;i<M;i++) {
//			cout << i<<":"<<a[i] <<"\n";
//		}
		ans = 0;
		for(i=1;i<(M+1)/2;i++) {
			if (a[i] && a[M-i]) {
//				&& abs(a[i] - a[N-i]) == 1) {
				v = min(a[i], a[M-i]);
				a[i] -= v;
				a[M-i] -= v;
				if (a[i]) {
					a[i]--;
				} else if (a[M-i]) {
					a[M-i]--;
				}
				ans++;
			}
		}
		if (M%2 == 0 && a[M/2]) {
			a[M/2] = 0;
			ans++;
		}
		if (a[0]) ans++;
		for(i=1;i<M;i++) {
//			cout << i<<":"<<a[i] <<"\n";
			if (a[i]) ans += a[i];
		}
//		if (N % 2 == 1 && a[N/2]) ans++;
		cout << ans << '\n';
	}
	return 0;
}
