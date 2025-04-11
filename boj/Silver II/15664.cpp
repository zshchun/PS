#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int n, m;
int ans[9];
vector<int> a;

void backtrack(int s, int i) {
	if (s == m) {
		for (int j=0;j<m;j++)
			cout << ans[j] << ' ';
		cout << endl;
		return;
	}
	ans[s] = -1;
	for (;i<a.size();i++) {
		if (i && ans[s] == a[i]) continue;
		ans[s] = a[i];
		backtrack(s+1, i+1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, v;
	cin >> n >> m;
	for (i=0;i<n;i++) {
		cin >> v;
		a.push_back(v);
	}
	sort(a.begin(), a.end());
	backtrack(0, 0);
	return 0;
}
