#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
vector<int> ans[500];

vector<int> operator+(const vector<int>& lhs, const vector<int>& rhs) {
	vector<int> ret;
	int x = 0;
	for (int i=0;i<max(lhs.size(), rhs.size());i++) {
		if (i < lhs.size()) x += lhs[i];
		if (i < rhs.size()) x += rhs[i];
		ret.push_back(x % 10);
		x /= 10;
	}
	if (x) ret.push_back(x);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, sz, carry, x;
	ans[0].push_back(1);
	ans[1].push_back(1);
	ans[2].push_back(3);
	for (i=3;i<=250;i++)
		ans[i] = ans[i-2] + ans[i-2] + ans[i-1];
	while (cin >> n) {
		for (auto it=ans[n].rbegin();it != ans[n].rend(); it++)
			cout << *it;
		cout << endl;
	}
	return 0;
}
