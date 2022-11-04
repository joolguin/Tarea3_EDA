#include <iostream>
#include "trees/tree.hpp"
#include <vector>
#include <string>
#include <sstream>
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
				if (words.size()<2){
					cout<<"Se debe especificar un archivo"<<endl;
				}
				if(words.size()>2){
					cout<<"Demasiados argumentos"<<endl;
				} 
				else{ 
					trees::TreeNode* node = tree.find(words[1]);
					if (node != nullptr){
						current_node = words[1];
					}
					else{
						cout<<"Esta carpeta no existe"<<endl;
					}
				}
			}
			if (words[0]== "ls"){
				if (words.size()<2){
					cout<<"Se debe especificar un archivo"<<endl;
				}
				if(words.size()>2){
					cout<<"Demasiados argumentos"<<endl;
				} 
				else{
					trees::TreeNode* node = tree.find(words[1]);
					if (node != nullptr){
						node->getChildren()->print();
					}
					else{
						cout<<"Esta carpeta no existe"<<endl;
					}
				}
			}
			if (words[0] == "mkdir"){
				if (words.size()<2){
					cout<<"Se debe especificar un archivo"<<endl;
				}
				if(words.size()>2){
					cout<<"Demasiados argumentos"<<endl;
				} 
				else{
					tree.insert(words[1], current_node);
				}
			}
			if (words[0] == "mkfile"){ // esto es para insertar un archivo, falta cambiar eso en el ADT del TreeNode, por mientras guarda un archivo en un archivo especificado
				if (words.size()<2){
					cout<<"Faltan argumentos"<<endl;
				}
				if (words.size()<3){
					cout<<"Faltan el nombre del archivo"<<endl;
				}
				if (words.size()>3){
					cout<<"Demasiados argumentos"<<endl;
				}
				else{
					trees::TreeNode* node = tree.find(words[1]);
					if (node != nullptr){
						tree.insert(words[2], words[1]);
					}
					else{
						cout<<"La carpeta "<< words[1]<<" no existe"<<endl;
					}
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