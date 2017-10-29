#pragma once
#include"HuffNode.h"
#include<iostream>
using namespace std;

class IntlNode :public HuffNode
{
private:
	HuffNode* left;
	HuffNode* right;
	HuffNode* parent;
	bool leftC;
	int wgt;
public:
	IntlNode(HuffNode* l, HuffNode* r) {
		left = l;
		right = r;
		left->setLeftC(1);
		right->setLeftC(0);
		wgt = left->weight() + right->weight();
	}
	int weight() {
		return wgt;
	}
	HuffNode* const leftChild() {
		return left;
	}
	HuffNode* const rightChild() {
		return right;
	}
	void setLeft(HuffNode* node) {
		left = node;
	}
	void setParent(HuffNode* p)
	{
		parent = p;
	}
	HuffNode* getParent()
	{
		return parent;
	}
	void setRight(HuffNode* node) {
		right = node;
	}
	void setLeftC(bool c)
	{
		leftC = c;
	}
	bool isLeft() {
		return leftC;
	}
	bool isLeaf() {
		return false;
	}
	char val()
	{
		return '\0';
	}
};
