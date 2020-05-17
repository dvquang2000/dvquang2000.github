#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct Node{
	string name;
	vector<Node*> childNodes;
};

void addChildNodes(Node *node, vector<string> childValues);
void enterTree(Node *&root);
void preorder(Node *root);
void inorder(Node *root);

int main(){
	// create root
	Node *root = new Node;
	cout << "Root's name: ";
	cin >> root->name;
	
	enterTree(root);	
	
	cout << "pre-order traversal" << endl;
	preorder(root);
	return 0;
}

void enterTree(Node *&root) {
	
	int numChilds;
	cout << "Number of child : " << endl;
	cin >> numChilds;
	vector<string> childVals;
	
	cout << "Value of childs 1 : " << endl;
	// Values for childs
	for(int i = 0; i < numChilds; i++){
		fflush(stdin);
		string value;
		getline(cin, value);
		childVals.push_back(value);	
	}
	
	addChildNodes(root, childVals);
	
	cout << "Value of childs 2 : " << endl;
	
	for(int i = 0; i < numChilds; i++) {
		Node *child = root->childNodes[i];
		int tmpNumChilds;
		cin >> tmpNumChilds;
		vector<string> tmpChildValues;
		
		for(int j = 0; j < tmpNumChilds; j++) {
			fflush(stdin);
			string tmp;
			getline(cin, tmp);
			tmpChildValues.push_back(tmp);	
		}
		
		addChildNodes(child, tmpChildValues);
	}
}

void addChildNodes(Node *rootNode, vector<string> childValues) {
	for (int i = 0; i < childValues.size(); i++){
		Node *childNode = new Node;
		childNode->name = childValues[i];
		
		rootNode->childNodes.push_back(childNode);
	}
}

void preorder(Node *root) {
	if (root==NULL) {
		return;
	}
	cout << root->name << endl;
	for(int i = 0; i < root->childNodes.size(); i++){
		preorder(root->childNodes[i]);
	}
}

void inorder(Node *root) {
	if (root==NULL) {
		return;
	}
	if (root->childNodes.size() == 0) {
		cout << root->name << endl;
		return;
	}
	inorder(root->childNodes[0]);
	cout << root->name << " have " << root->childNodes.size() << " childs ." << endl;
	
	for(int i = 1; i < root->childNodes.size(); i++) {
		inorder(root->childNodes[i]);
	}
}

