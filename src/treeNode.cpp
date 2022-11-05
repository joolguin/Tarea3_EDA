/*
 * treeNode.cpp
 *
 *  Created on: Aug 30, 2022
 *      Author: jsaavedr
 */
#include <sstream>
#include "trees/treeNode.hpp"

namespace trees {

TreeNode::TreeNode(): parent(nullptr), nombre(),tipo() , children(new TreeList()) {
}

TreeNode::TreeNode(std::string val, int x): parent(nullptr), nombre(val), tipo(x),children(new TreeList()) {
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
std::string TreeNode::getNombre(){
	return nombre;
}
int TreeNode::getTipo(){
	return tipo;
}
void TreeNode::setChildren(TreeList* list){
	children = list;
}
TreeNode* TreeNode::getParent(){
	return parent;
}
TreeList* TreeNode::getChildren(){
	return children;
}


TreeNode::~TreeNode() {
	//action when a treeNode is deleted
	//delete the descendants only
	if (children != nullptr){
		delete children;
	}
}

} /* namespace trees */
