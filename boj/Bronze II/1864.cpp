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
	string s;
	while (cin >> s) {
		int d = 1, ans = 0;
		reverse(s.begin(), s.end());
		for (char c : s) {
			if ('-' == c) ans += d * 0;
			else if ('\\' == c) ans += d * 1;
			else if ('(' == c) ans += d * 2;
			else if ('@' == c) ans += d * 3;
			else if ('?' == c) ans += d * 4;
			else if ('>' == c) ans += d * 5;
			else if ('&' == c) ans += d * 6;
			else if ('%' == c) ans += d * 7;
			else if ('/' == c) ans += d * -1;
			else return 0;
			d *= 8;
		}
		cout << ans << endl;
	}
	return 0;
}
