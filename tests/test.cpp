#include <iostream>
#include "trees/tree.hpp"
#include <vector>
#include <string>

using namespace std;

int main(int nargs, char** vargs){
	cout<<"Bienvenido a TreeSO!"<<endl;
	cout<<"Autores: <Matias Leyton> y <Josefa Olguin>"<<endl<<"/#"<<endl;
	
	trees::Tree tree;
	tree.setRoot(new trees::TreeNode("/"));
	string current_node = "/";
	bool exit = true; 
	while (exit){
		vector<string> words;
		string action;
		cout<<"insert command"<<endl;
		getline(cin, action);
		stringstream test(action);
		string segment;

		while(getline(test, segment, ' '))
		{
			words.push_back(segment);
		}

		if (words[0] == "exit"){
			exit = false;
		}
		else{
			if (words[0]== "cd"){
				if (words.size()==1){
					cout<<"Se debe especificar un archivo"<<endl;
				}
				else{
					current_node = words[1];
				}
			}
			if (words[0]== "ls"){
				if (words.size()==1){
					cout<<"Se debe especificar un archivo"<<endl;
				}
				else{
					trees::TreeNode* node = tree.find(words[1]);
					if (node != nullptr){
						node->getChildren()->print();
					}
				}
			}
			if (words[0] == "mkfile"){
				if (words.size()==1){
					cout<<"Se debe especificar un archivo"<<endl;
				}
				else{
					tree.insert(words[1], current_node);
				}
			}
		}
		words.clear();
	}

	tree.traverse();

	trees::TreeNode* node = tree.find("/");
	if (node != nullptr){
		node->getChildren()->print();
	}
	return 0;
}

//COMANDOS DENTRO DEL WHILE
//cd == tree.find()  raiz o nodo actual
//ls == getChildren de la raiz o el nodo actual 
//mkdir == crear nodo
//mkfile == tree.insert() insertamos archivo en cierta carpeta 
//rm == remove (se borra el nado y todos sus hijos) 
//tree == tree.traverse
//find == 
//exit == condicion del while cumplida
//condicion insert a nodo -> no tiene que ser archivo 
//root == /
// carpetas: 