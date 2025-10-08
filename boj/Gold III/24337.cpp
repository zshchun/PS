#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, a, b, i;
	vector<int> ans;
	cin >> n >> a >> b;
	if (a + b - 1 > n) {
		cout << "-1\n";
		return 0;
	}

	for (i=1;i<a;i++)
		ans.push_back(i);
	ans.push_back(max(a, b));
	for (i=b-1;i>=1;i--)
		ans.push_back(i);

	cout << ans.front() << ' ';
	for (i=0;i<n-ans.size();i++)
		cout << "1 ";
	for (i=1;i<ans.size();i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
