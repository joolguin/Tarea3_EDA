#ifndef TREENODE_HPP_
#define TREENODE_HPP_
#include <sstream>
#include "trees/treeList.hpp"

namespace trees {

class TreeList;
class TreeNode {
private:
	TreeNode* parent;
	std::string data; //NOMBRE DEL ARCHIVO
	TreeList* children;
public:
	TreeNode();
	TreeNode(std::string val);
	void setParent(TreeNode* node);
	void setData(std::string val);
	void setChildren(TreeList* list);
	TreeNode* getParent();
	std:: string getData();
	TreeList* getChildren();
	virtual ~TreeNode();
};

} 

#endif 