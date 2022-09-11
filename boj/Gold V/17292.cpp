#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
typedef pair<string,string> ps;

inline bool is_adjacent(const ps &p) {
	char a = p.first[0];
	char b = p.second[0];
	if (a > b) swap(a, b);
	if (a+1 == b || (a == '1' && b == 'f') || (a == '9' && b == 'a'))
		return true;
	return false;
}

inline bool is_equal(const ps &p) {
	return p.first[0] == p.second[0];
}

inline bool is_monocolor(const ps &p) {
	return p.first[1] == p.second[1];
}

inline char max_char(const ps &p) {
	return max(p.first[0], p.second[0]);
}
inline char min_char(const ps &p) {
	return min(p.first[0], p.second[0]);
}

inline bool is_max_black(const ps &p) {
	if (p.first[0] > p.second[0])
		return p.first[1] == 'b';
	return p.second[1] == 'b';
}

bool compare(const ps &lhs, const ps &rhs) {
	if (is_adjacent(lhs) != is_adjacent(rhs))
		return is_adjacent(lhs) > is_adjacent(rhs);
	if (is_equal(lhs) != is_equal(rhs))
		return is_equal(lhs) > is_equal(rhs);
	if (is_monocolor(lhs) != is_monocolor(rhs))
		return is_monocolor(lhs) > is_monocolor(rhs);
	if (max_char(lhs) != max_char(rhs))
		return max_char(lhs) > max_char(rhs);
	if (min_char(lhs) != min_char(rhs))
		return min_char(lhs) > min_char(rhs);
	return is_max_black(lhs) > is_max_black(rhs);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i, j;
	string input;
	cin >> input;
	stringstream ss(input);
	string s;
	vector<string> cards;
	vector<pair<string,string>> card_pairs;
	while (getline(ss, s, ','))
		cards.push_back(s);

	for (i=0;i<6;i++)
		for (j=i;j<6;j++)
			if (i != j)
				card_pairs.push_back(make_pair(cards[i], cards[j]));

	sort(card_pairs.begin(), card_pairs.end(), compare);

	for (i=0;i<(ll)card_pairs.size();i++) {
		cout << card_pairs[i].first << card_pairs[i].second << endl;
	}

	return 0;
}
