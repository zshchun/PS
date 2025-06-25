#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	vector<int> ans;
	cin >> n;
	if (!n) {
		cout << "0\n";
		return 0;
	}
	while (n) {
		if (n % 2 == 0) {
			ans.push_back(0);
			n /= -2;
		} else {
			ans.push_back(1);
			n = (n-1) / -2;
		}
	}
	for (auto it=ans.rbegin();it != ans.rend();it++)
		cout << *it;
	cout << endl;

	return 0;
}
