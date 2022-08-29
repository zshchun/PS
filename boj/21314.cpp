#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string append(char head, char repeat, ll length) {
	string s;
	ll i;
	if (length) {
		s += head;
		for (i=0;i<length-1;i++) {
			s += repeat;
		}
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	ll i, min_length = 0, max_length = 0;
	string max_str, min_str;
	if (s.size() == 0) {
		cout << "0\n";
		return 0;
	}
	for (i=0;i<(ll)s.size();i++) {
		max_length++;
		min_length++;
		if (s[i] == 'K') {
			if (min_length > 1)
				min_str += append('1', '0', min_length-1);
			min_str += '5';
			max_str += append('5', '0', max_length);
			max_length = 0;
			min_length = 0;
		}
	}

	if (max_length)
		max_str += append('1', '1', max_length);
	if (min_length)
		min_str += append('1', '0', min_length);

	cout << max_str << '\n';
	cout << min_str << '\n';
	return 0;
}
