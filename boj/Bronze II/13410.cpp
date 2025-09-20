#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k, v, i;
	cin >> n >> k;
	vector<int> a;
	for (i=1;i<=k;i++) {
		string t = to_string(n*i);
		reverse(t.begin(), t.end());
		a.push_back(stoi(t));
	}
	sort(a.begin(), a.end());
	cout << a.back() << endl;
	return 0;
}
