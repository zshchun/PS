#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;
	cin >> n;
	cin >> s;
	if (s.find("ooo") != string::npos)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
