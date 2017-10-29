#pragma once
#include"HuffNode.h"
#include"LeafNode.h"
#include"IntlNode.h"
#include<iostream>
using namespace std;

class HuffTree
{
private:
	HuffNode* Root;
public:
	HuffTree(char& value, int freq) {
		Root = new LeafNode(value, freq);
	}
	HuffTree(HuffTree* l, HuffTree* r) {
		Root = new IntlNode(l->root(), r->root());
	}
	HuffNode* root() {
		return Root;
	}
	~HuffTree() {};
	int weight() {
		return Root->weight();
	}
};
