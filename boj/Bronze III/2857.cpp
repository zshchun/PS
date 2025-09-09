#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, found = false;
	string s;
	for (i=1;i<=5;i++) {
		cin >> s;
		if (s.find("FBI") != string::npos) {
			cout << i << ' ';
			found = true;
		}
	}
	if (!found)
		cout << "HE GOT AWAY!\n";
	return 0;
}
