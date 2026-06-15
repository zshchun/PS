#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pa;
typedef list<pair<int,int>> lpa;
class LRUCache {
	int cap = 0;
	int tick = 0;
	lpa cache;
	unordered_map<int,lpa::iterator> m;
	void update(lpa::iterator it) {
		cache.splice(cache.begin(), cache, it);
	}

public:
	LRUCache(int capacity) : cap(capacity) {}

	int get(int key) {
		auto it = m.find(key);
		if (it == m.end())
			return -1;
		update(it->second);
		return it->second->second;
	}

	void put(int key, int value) {
		auto it = m.find(key);
		if (it != m.end()) {
			update(it->second);
			it->second->second = value;
			return;
		}
		cache.push_front(pa(key, value));
		m[key] = cache.begin();
		if (cache.size() > cap) {
			int k = cache.back().first;
			m.erase(k);
			cache.pop_back();
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
