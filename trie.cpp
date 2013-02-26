#include <iostream>
#include <vector>
#include <cstdlib>
#include <stack>
#include <string>
#include <climits>
#include <ctime>
#include <map>
#include <hash_map>

using namespace std;

class TrieTreeNode {
  hash_map<char, TrieTreeNode> children;
	char val;
	vector<int> indexes;
public:	
	TrieTreeNode() {}
	TrieTreeNode(char newval): val(newval) {}
	void insert(string s, int index);
	vector<int> getIndex(string s);
};

void TrieTreeNode::insert(string s, int index) {
	indexes.push_back(index);
	if (!s.empty()) {
		if (children.find(s[0]) == children.end()) {
			children[s[0]] = TrieTreeNode(s[0]);
		}
		children[s[0]].insert(s.substr(1), index);
	}
}

vector<int> TrieTreeNode::getIndex(string s) {
	if (s.empty()) return this->indexes;
	if (children.find(s[0]) != children.end()) {
		return children[s[0]].getIndex(s.substr(1));
	}
	return vector<int>();
}

int main() {
	string s("mississippi");	
	TrieTreeNode trie(0);
	for (int i = 0; i < s.size(); i++) {
		trie.insert(s.substr(i), i);
	}
	vector<int> v = trie.getIndex("si");
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "---";
	}
	system("PAUSE");
}
