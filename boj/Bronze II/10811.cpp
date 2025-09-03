#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, i, u, v;
	cin >> n >> m;
	vector<int> a;
	for (i=1;i<=n;i++)
		a.push_back(i);

	for (i=0;i<m;i++) {
		cin >> u >> v;
		reverse(a.begin()+u-1, a.begin()+v);
	}
	for (int &x : a)
		cout << x << ' ';
	cout << endl;
	return 0;
}
