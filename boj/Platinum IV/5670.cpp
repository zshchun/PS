#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int N;
struct Trie {
//	Trie *child[26];
	map<char, Trie*> child;
	bool last;
	int count;
	Trie() {
//		memset(child, 0, sizeof(child));
		last = false;
		count = 0;
	}
	~Trie() {
		for (int i=0;i<26;i++)
			if (child.find(i) != child.end())
				delete child[i];
	}
	void insert(const char *c) {
		if (*c == 0) {
			last = true;
			return;
		}
		int idx = (*c) - 'a';
		if (child.find(idx) == child.end()) {
			child[idx] = new Trie();
			count++;
		}
		child[idx]->insert(c+1);
	}
	int find(const char *c, int i) {
		if (*c == 0)
			return 0;
		int idx = (*c) - 'a';
		if (child.find(idx) == child.end())
			return strlen(c);
		int typing = (!last && i > 0 && count == 1) ? 0 : 1;
		return child[idx]->find(c+1, i+1) + typing;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	string s;
	while (cin >> N) {
		Trie *trie = new Trie();
		vector<string> a(N);
		double ans = 0;
		for (i=0;i<N;i++) {
			cin >> a[i];
			trie->insert(a[i].c_str());
		}
		for (i=0;i<N;i++) {
			ans += trie->find(a[i].c_str(), 0);
		}
		cout << fixed << setprecision(2) << ans / N << endl;
	}
	return 0;
}
