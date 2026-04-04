#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	string s;
	cin.ignore();
	while (T--) {
		getline(cin, s);
		stringstream ss(s);
		string t;
		while (ss >> t) {
			reverse(t.begin(), t.end());
			cout << t << ' ';
		}
		cout << endl;
	}
	return 0;
}
