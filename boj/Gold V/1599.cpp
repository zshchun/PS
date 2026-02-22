#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789

map<char,char> min2al = { {'a', 'a'}, {'b', 'b'}, {'k', 'c'}, {'d', 'd'}, {'e', 'e'}, {'g', 'f'}, {'h', 'g'}, {'i', 'h'}, {'l', 'i'}, {'m', 'j'}, {'n', 'k'}, {'c', 'l'}, {'o', 'm'}, {'p', 'n'}, {'r', 'o'}, {'s', 'p'}, {'t', 'q'}, {'u', 'r'}, {'w', 's'}, {'y', 't'}, };

map<char,string> al2min = { {'a', "a"}, {'b', "b"}, {'c', "k"}, {'d', "d"}, {'e', "e"}, {'f', "g"}, {'g', "h"}, {'h', "i"}, {'i', "l"}, {'j', "m"}, {'k', "n"}, {'l', "ng"}, {'m', "o"}, {'n', "p"}, {'o', "r"}, {'p', "s"}, {'q', "t"}, {'r', "u"}, {'s', "w"}, {'t', "y"}, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, i, j;
	cin >> n;
	vector<string> a;
	string s, t;
	for (i=0;i<n;i++) {
		cin >> s;
		t = "";
		for (j=0;j<s.size();j++) {
			if (j+1 < s.size() && s[j] == 'n' && s[j+1] == 'g') {
				t += 'l';
				j++;
			} else {
				t += min2al[s[j]];
			}
		}
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	for (string &x : a) {
		t = "";
		for (j=0;j<x.size();j++)
			t += al2min[x[j]];
		cout << t << endl;
	}

	return 0;
}
