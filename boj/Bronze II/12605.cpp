#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i;
	string s, t; 
	cin >> n;
	cin.ignore(80, '\n');
	for (i=1;i<=n;i++) {
		getline(cin, s);
		stringstream ss(s);
		vector<string> a;
		while (ss >> t)
			a.push_back(t);
		reverse(a.begin(), a.end());
		cout << "Case #" << i << ": ";
		for (string &x: a)
			cout << x << ' ';
		cout << endl;
	}
	return 0;
}
