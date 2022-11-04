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
	tree.setRoot(new trees::TreeNode("/", 1));
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
					cout<<"cd: se debe especificar un archivo"<<endl;
				}
				if(words.size()>2){
					cout<<"cd: demasiados argumentos"<<endl;
				} 
				else{ 
					trees::TreeNode* node = tree.find(words[1]);
					if (node != nullptr){
						current_node = words[1];
					}
					else{
						cout<<"cd: no existe el archivo o carpeta: "<<words[1]<<endl;
					}
				}
			}

			if (words[0]== "ls"){
				if (words.size()<2){
					cout<<"ls: se debe especificar un archivo"<<endl;
				}
				if(words.size()>2){
					cout<<"ls: demasiados argumentos"<<endl;
				} 
				else{
					trees::TreeNode* node = tree.find(words[1]);
					if (node != nullptr){
						node->getChildren()->print();
					}
					else{
						cout<<"ls: no existe el archivo o carpeta: "<<words[1]<<endl;
					}
				}
			}

			if (words[0] == "mkdir"){ 
				if (words.size()<2){
					cout<<"mkdir: se debe especificar un archivo"<<endl;
				}
				if(words.size()>2){
					cout<<"mkdir: demasiados argumentos"<<endl;
				} 
				else{
					trees::TreeNode* node = tree.find(words[1]);//cambiar: solamente no pueden haber dos archivos con el mismo nombre en el mismo NIVEL 
					trees::TreeNode* nodeparent = tree.find(current_node);
					if (node == nullptr){
						if (current_node == "/"){
							tree.insert(words[1], current_node, 1);
						}
						else if (nodeparent->getTipo() == 1){
							tree.insert(words[1], current_node, 1);
						}
						
						else{
							cout<<"mkdir: no se puede insertar en un archivo"<<endl;
						}
					}
					else{
						cout<<"mkdir: "<<words[1]<<": la carpeta ya existe"<<endl;
					}
				}
			}

			if (words[0] == "mkfile"){ 
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
					trees::TreeNode* nodeparent = tree.find(current_node);
					if (node != nullptr){
						if (words[1] == "/"){
							tree.insert(words[1], words[1], 0);
						}
						else if (nodeparent->getTipo() == 1){
							tree.insert(words[2], words[1], 0);
						}
						else{
							cout<<"mkfile: no se puede insertar en un archivo"<<endl;
						}
					}
					else{
						cout<<"mkfile: La carpeta "<< words[1]<<" no existe"<<endl;
					}
				}
			}
/*
			if (words[0]=="rm"){
				if (words.size()<2){
					cout<<"rm: se debe especificar un archivo"<<endl;
				}
				if(words.size()>2){
					cout<<"rm: demasiados argumentos"<<endl;
				} 
				else{
					trees::TreeNode* node = tree.find(words[1]);
					if (node != nullptr){
						///
					}
					else{
						cout<<"rm: La carpeta "<< words[1]<<" no existe"<<endl;
					}
				}
				
			}
*/
			if (words[0]=="tree"){
				if (words.size()<2){
					cout<<"mkdir: se debe especificar un archivo"<<endl;
				}
				if(words.size()>2){
					cout<<"mkdir: demasiados argumentos"<<endl;
				} 
				else{
				trees::TreeNode* node = tree.find(words[1]);
				if (node != nullptr){
					tree.traverse_rec(node, 1);
				}
				else{
					cout<<"tree: La carpeta "<< words[1]<<" no existe"<<endl;
				}
				}
			}
		}
		words.clear();
	}
/*
	trees::TreeNode* node = tree.find("/");
	if (node != nullptr){
		node->getChildren()->print();
	}
	*/
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