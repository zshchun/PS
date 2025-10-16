#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
string arr[] = { "Never gonna give you up", "Never gonna let you down", "Never gonna run around and desert you", "Never gonna make you cry", "Never gonna say goodbye", "Never gonna tell a lie and hurt you", "Never gonna stop", };
int ans = false;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i;
	string s;
	cin >> n;
	cin.ignore(80, '\n');
	for (i=0;i<n;i++) {
		bool found = false;
		getline(cin, s);
		for (string &t : arr) {
			if (s == t) {
				found = true;
				break;
			}
		}
		if (!found)
			ans = true;
	}

	if (ans)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}
