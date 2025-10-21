#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int visited[1001];
int l, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, p, k, exp=0, mx=0;
	int exp_num, max_num;
	cin >> l >> n;
	for (i=1;i<=n;i++) {
		int cnt = 0;
		cin >> p >> k;
		for (j=p;j<=k;j++) {
			if (visited[j]) continue;
			visited[j] = i;
			cnt++;
		}
		if (exp < k-p+1) {
			exp = k-p+1;
			exp_num = i;
		}
		if (mx < cnt) {
			mx = cnt;
			max_num = i;
		}
	}
	cout << exp_num << endl;
	cout << max_num << endl;

	return 0;
}
