#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b;
	vector<int> ans;
	while (a || b) {
		c = a % 10;
		c += b % 10;
		ans.push_back(c);
		a /= 10;
		b /= 10;
	}
	reverse(ans.begin(), ans.end());

	for (int &x : ans)
		cout << x;
	cout << endl;

	return 0;
}
