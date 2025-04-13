#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	getline(cin, s);
	if (s.find("d2") != string::npos || s.find("D2") != string::npos)
		cout << "D2\n";
	else
		cout << "unrated\n";
	return 0;
}
