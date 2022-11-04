/*
 * treeNode.cpp
 *
 *  Created on: Aug 30, 2022
 *      Author: jsaavedr
 */
#include <sstream>
#include "trees/treeNode.hpp"

namespace trees {

TreeNode::TreeNode(): parent(nullptr), nombre(), children(new TreeList()) {
}

TreeNode::TreeNode(std::string val): parent(nullptr), nombre(val), children(new TreeList()) {
}

void TreeNode::setParent(TreeNode* node){
	parent = node;
}
void TreeNode::setNombre(std::string val){
		nombre = val;
}
void TreeNode::setTipo(int val){
	tipo = val;
}
void TreeNode::setChildren(TreeList* list){
	children = list;
}
TreeNode* TreeNode::getParent(){
	return parent;
}
std::string TreeNode::getNombre(){
	return nombre;
}
TreeList* TreeNode::getChildren(){
	return children;
}
int TreeNode::getTipo(){
	return tipo;
}

TreeNode::~TreeNode() {
	//action when a treeNode is deleted
	//delete the descendants only
	if (children != nullptr){
		delete children;
	}
}

} /* namespace trees */
