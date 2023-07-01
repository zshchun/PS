#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll N, i, ans = 0;
	cin >> N;
	vector<string> a;
	string s;
	for (i=0;i<N;i++) {
		cin >> s;
		a.push_back(s);
	}
	auto it = a.begin();
	for (i=0;i<N;i++) {
		cin >> s;
		if (s != *it) {
			a.erase(find(a.begin(), a.end(), s));
			ans++;
		} else {
			it++;
			if (it == a.end())
				break;
		}
	}
	cout << ans << endl;
	return 0;
}
