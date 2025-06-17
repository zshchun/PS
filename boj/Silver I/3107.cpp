#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> a;
	vector<int> b;
	int i, v;
	string s;
	while (getline(cin, s, ':')) {
		if (s == "") break;
		stringstream ss(s);
		ss >> std::hex >> v;
		a.push_back(v);
	}

	while (getline(cin, s, ':')) {
		v = 0;
		stringstream ss(s);
		ss >> std::hex >> v;
		b.push_back(v);
	}

	while (a.size() + b.size() < 8)
		a.push_back(0);

	a.insert(a.end(), b.begin(), b.end());

	for (i=0;i<a.size();i++) {
		if (i) cout << ':';
		cout << hex << setw(4) << setfill('0') << a[i];
	}
	


	return 0;
}
