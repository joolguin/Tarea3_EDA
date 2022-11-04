#ifndef TREENODE_HPP_
#define TREENODE_HPP_
#include <sstream>
#include "trees/treeList.hpp"

namespace trees {

class TreeList;
class TreeNode {
private:
	TreeNode* parent;
	std::string nombre; //NOMBRE DEL ARCHIVO
	int tipo;
	TreeList* children;
public:
	TreeNode();
	TreeNode(std::string val);
	void setParent(TreeNode* node);
	void setNombre(std::string val);
	void setTipo(int val);
	void setChildren(TreeList* list);
	TreeNode* getParent();
	std:: string getNombre();
	TreeList* getChildren();
	int getTipo();
	virtual ~TreeNode();
};

} 

#endif 