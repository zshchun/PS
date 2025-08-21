#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	string s;
	cin >> i >> s;
	for (char &c : s)
		c ^= 0x20;
	cout << s << endl;
	return 0;
}
