#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<int,int> pi;
#define endl "\n"
#define INF 123456789
#define ERR 0x01020304
#define W (ans & 0xff)
#define O ((ans >> 8) & 0xff)
#define L ((ans >> 16) & 0xff)
#define F ((ans >> 24) & 0xff)

char t[26];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int i = 0, cnt;
	while (i < s.size()) {
		cnt = 0;
		string t;
		while (s[i+cnt] == 'w') cnt++;
		t.append(cnt, 'w');
		t.append(cnt, 'o');
		t.append(cnt, 'l');
		t.append(cnt, 'f');
		if (cnt == 0 || t != s.substr(i, t.size())) {
			cout << "0\n";
			return 0;
		}
		i += t.size();
	}
	cout << "1\n";
	return 0;
}
