#ifndef CHILDRENLIST_HPP_
#define CHILDRENLIST_HPP_

#include "trees/treeListNode.hpp"

namespace trees {

class TreeNode;
class TreeListNode;
class TreeList {
private:
	TreeListNode* head;
public:
	TreeList();
	TreeListNode* getHead();
	void insertFirst(TreeNode* treeNode);
	void removeFirst();
	void remove(std::string val);
	void removeAll();
	bool isEmpty();
	TreeNode* find(std::string val);
	void print();
	virtual ~TreeList();
};

}

#endif
