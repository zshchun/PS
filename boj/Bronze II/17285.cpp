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
	int i; 
	string s, t;
	cin >> s;
	for (i=0;i<256;i++) {
		t = s;
		for (char &c : t)
			c ^= i;
		if (t.substr(0, 8) == "CHICKENS") {
			cout << t << endl;
			break;
		}
	}
	return 0;
}
