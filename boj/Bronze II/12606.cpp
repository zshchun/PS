#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N, i;
	cin >> N;
	string s, t;
	cin.ignore();
	for (i=1;i<=N;i++) {
		string ans;
		getline(cin, s);
		stringstream ss(s);
		while (ss >> t) {
			ans = t + " " + ans;
		}
		cout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}
