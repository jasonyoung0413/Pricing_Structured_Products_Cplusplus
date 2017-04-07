#ifndef TREE_H
#define TREE_H

class Node {
public:
	Node* uuchild;
	Node* udchild;
	Node* ddchild;
	Node* duchild;
	Node* mmchild;
	Node* parent;
	int level;
	Node() 
		:uuchild(0), udchild(0), ddchild(0), duchild(0), mmchild(0),parent(0) {
	}
};

class TreeNode :public Node {
public:
	double lnstock1_price;
	double lnstock2_price;
	double* warrant_value;
	TreeNode* uuchild;
	TreeNode* udchild;
	TreeNode* ddchild;
	TreeNode* duchild;
	TreeNode* mmchild;
	TreeNode* parent;
	TreeNode() :
		lnstock1_price(0), lnstock2_price(0), warrant_value(0),
		uuchild(0), udchild(0), ddchild(0), duchild(0), mmchild(0),parent(0){
	}
	TreeNode operator=(TreeNode* t) {
		this->lnstock1_price = t->lnstock1_price;
		this->lnstock1_price = t->lnstock2_price;
		this->warrant_value = t->warrant_value;
		this->uuchild = t->uuchild;
		this->udchild = t->udchild;
		this->ddchild = t->ddchild;
		this->duchild = t->duchild;
		this->mmchild = t->mmchild;
		this->level = t->level;
		return *this;
	}
};

class Tree {
public:
	TreeNode* root;
	Tree()
		:root(0), nlevel(0) {
	}
	void setlevel(int n) { nlevel = n; }
	int getlevel() { return nlevel; }
private:
	int nlevel;
};
#endif