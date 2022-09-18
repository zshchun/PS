#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef pair<char,ll> pcl;
#define endl "\n"

ll alpha[26];
int main() {
	ll i, j, k, ans=0;
	string s;
	getline(cin, s);
	vector<ll> arr;
	vector<pair<char,ll>> morse_table;

	for (i=0;i<(ll)s.size();i++) {
		char c = s[i] | 0x20;
		if ('a' <= c && c <= 'z') {
			alpha[c-'a']++;
			arr.push_back(c-'a');
		}
	}

	for (i=0;i<26;i++) {
		morse_table.push_back(make_pair(i+'a', alpha[i]));
	}

	sort(morse_table.begin(), morse_table.end(), [&](const pcl &lhs, const pcl &rhs) {
		return lhs.second > rhs.second;
	});

	ll numbers[] = { 1, 2, 3, 5, 8, 13, 21 };
	j = 0;
	k = 1;
	for (i=0;i<26;i++) {
		if (numbers[j] <= 0) {
			j++;
			k += 2;
		}
		numbers[j]--;
		morse_table[i].second = k;
	}

	sort(morse_table.begin(), morse_table.end());
	for (i=0;i<arr.size();i++) {
		if (i) ans += 3;
		ans += morse_table[arr[i]].second;
	}

	cout << ans << endl;
	return 0;
}
