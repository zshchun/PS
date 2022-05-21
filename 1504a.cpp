#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool valid(string s) {
	for (int i=0;i<s.size()/2;i++) {
		if (s[i] != s[s.size()-i-1])
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll T, i, N;
	cin >> T;
	string s, ss;
	while(T--) {
		cin >> s;
		bool found = false;
		if (valid(s+'a') && valid('a'+s)) {
			cout << "NO\n";
		} else {
			if (!valid(s+'a'))
				cout << "YES\n" << s+'a' << '\n';
			else
				cout << "YES\n" << 'a'+s << '\n';
//			for(i=0;i<s.size();i++) {
//				string ss = s.substr(0,i) + 'a' + s.substr(i);
//				if (!valid(ss)) {
//					cout << "YES\n" << ss << '\n';
//					break;
//				}
//			}
		}
	}
	return 0;
}
