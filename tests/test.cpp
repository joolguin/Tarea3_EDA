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
			// COMANDO CD
			if (words[0]== "cd"){
				if (words.size()<2){
					cout<<"cd: se debe especificar un archivo"<<endl;
				}
				if(words.size()>2){
					cout<<"cd: demasiados argumentos"<<endl;
				} 
				else{
					if(words[1] == "."){
						current_node = current_node;
					} 
					else if(words[1]== ".." && current_node != "/"){
						trees::TreeNode* node = tree.find(current_node);
						trees::TreeNode* parent = node->getParent();
						string name = parent->getNombre();
						current_node = name;
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
			}
			
			// COMANDO LS
			if (words[0]== "ls"){
				if (words.size()<2){
					cout<<"ls: se debe especificar un archivo"<<endl;
				}
				if(words.size()>2){
					cout<<"ls: demasiados argumentos"<<endl;
				} 
				else{
					if(words[1] == "."){
						trees::TreeNode* node = tree.find(current_node);
						if (node != nullptr){
							node->getChildren()->print();
						}
					} 
					else if(words[1]== ".." && current_node != "/"){
						trees::TreeNode* node = tree.find(current_node);
						trees::TreeNode* parent = node->getParent();
						string name = parent->getNombre();
						trees::TreeNode* node1 = tree.find(name);
						if (node1 != nullptr){
							node1->getChildren()->print();
						}
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
			}
			//COMANDO MKDIR
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
			//COMANDO MKFILE
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
					if (words[1] == "."){
						trees::TreeNode* node = tree.find(current_node);
						if (node != nullptr){
							if(current_node == "/"){
								tree.insert(words[2], current_node, 0);
							}
							else if (node-> getTipo()== 1){
								tree.insert(words[2],current_node,0);
							}
						}
					}
					else if (words[1]==".." && current_node != "/"){
						trees::TreeNode* node = tree.find(current_node);
						trees::TreeNode* parent = node->getParent();
						string name = parent->getNombre();
						trees::TreeNode* node1 = tree.find(name);
						if (node1 != nullptr){
							if(name == "/"){
								tree.insert(words[2], name, 0);
							}
							else if (node-> getTipo()== 1){
								tree.insert(words[2] ,name, 0);
							}
						}
					}
					else{
					trees::TreeNode* node = tree.find(words[1]);
					if (node != nullptr){
						if (words[1] == "/"){
							tree.insert(words[2], words[1], 0);
						}
						else if (node->getTipo() == 1){
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
			}
			//COMANDO RM
			if (words[0]=="rm"){
				if (words.size()<2){
					cout<<"rm: se debe especificar un archivo"<<endl;
				}
				if(words.size()>2){
					cout<<"rm: demasiados argumentos"<<endl;
				} 
				else{
					if (words[1] == "." && current_node != "/"){
						trees::TreeNode* node = tree.find(current_node);
						trees::TreeList* childrens = node->getParent()->getChildren();
						if (node != nullptr){
						childrens->remove(node->getNombre());
					}
					}
					else if (words[1]==".." && current_node != "/"){
						trees::TreeNode* node = tree.find(current_node);
						trees::TreeNode* parent = node->getParent();
						string name = parent->getNombre();
						if (name != "/"){
							trees::TreeNode* node = tree.find(name);
							trees::TreeList* childrens = node->getParent()->getChildren();
							if (node != nullptr){
								childrens->remove(node->getNombre());
							}
						}
					}
					else{
					trees::TreeNode* node = tree.find(words[1]);
					trees::TreeList* childrens = node->getParent()->getChildren();
					if (node != nullptr){
						childrens->remove(node->getNombre());
					}
					else{
						cout<<"rm: La carpeta "<< words[1]<<" no existe"<<endl;
					}
					}
				}
			}
			//COMANDO TREE
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
			//COMANDO FIND
			if (words[0]=="find"){
				if (words.size()<3){
					cout<<"find: se debe especificar una carpeta y un nombre a buscar"<<endl;
				}
				if(words.size()>3){
					cout<<"find: demasiados argumentos"<<endl;
				} 
				else{
					cout<<tree.find_rec1(words[2], tree.find(words[1]))->getNombre()<<endl;
				}
			}
		}
		words.clear();
	}
	return 0;
}



