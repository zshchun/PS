#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int ans;

bool is_vowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	bool last = is_vowel(s[0]);

	for (int i=1;i<s.size();i++) {
		if (is_vowel(s[i]) == last) {
			cout << "0\n";
			return 0;
		}
		last = is_vowel(s[i]);
	}
	cout << "1\n";

	return 0;
}
