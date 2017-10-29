#pragma once
#include"HuffNode.h"
#include<iostream>
using namespace std;

class LeafNode :public HuffNode
{
private:
	char data;
	bool leftC;
	HuffNode* parent;
	int wgt;
public:
	LeafNode(const char& value, int freq)
	{
		data = value;
		wgt = freq;
	}
	int weight() {
		return wgt;
	}
	char val() {
		return data;
	}
	void setParent(HuffNode* p)
	{
		parent = p;
	}
	HuffNode* getParent()
	{
		return parent;
	}
	void setLeftC(bool c)
	{
		leftC = c;
	}
	bool isLeft() {
		return leftC;
	}
	bool isLeaf() {
		return true;
	}
	HuffNode* const leftChild()
	{
		return NULL;
	}
	HuffNode* const rightChild()
	{
		return NULL;
	}
};
