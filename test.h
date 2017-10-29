#pragma once
#include"HuffTree.h"
#include<iostream>
#include<ctime>
#include<cmath>

struct HuffList
{
	HuffTree* node;
	HuffList* next;
};
struct TestData
{
	char chars;
	int freq;
};

HuffList* getTestData(){
	srand(time(0));
	int size = 0 + rand() % 300;
	int count = 0;
	char value = 'A';
	TestData* data = new TestData[26];
	for (int i = 0; i < 26; i++)
	{
		data[i].chars = value + i;
		data[i].freq = 0;
	}
	for (int i = 0; i < size; i++)
	{
		int f = 0 + rand() % 26;
		data[f].freq++;
	}
	//****************************************************测试***************************************************//
	for (int i = 0; i < 26; i++)
	{
		cout << i<<' '<<data[i].chars << ' ' << data[i].freq << endl;
	}
	//***********************************************************************************************************//
	for (int i = 1; i < 26; i++)
	{
		for (int j = i; (j > 0) && (data[j].freq < data[j - 1].freq); j--)
		{
			TestData temp = data[j];
			data[j] = data[j - 1];
			data[j - 1] = temp;
		}
	}
	int c = 0 + rand() % 5;
	for (int i = 0; i < c; i++) {
		int f = 0 + rand() % 26;
		data[f].freq = 0;
	}
	HuffList* head = new HuffList;
	int begin = 0;
	for (int i = 0; i < 26; i++) {
		if (data[i].freq != 0)
		{
			begin = i;
			head->node = new HuffTree(data[i].chars, data[i].freq);
			head->next = NULL;
			break;
		}
	}
	//******************************************测试************************************************//
	for (int i = 0; i < 26; i++)
	{
		cout << i << ' ' << data[i].chars << ' ' << data[i].freq << endl;
	}
	//************************************************************************************************//
	HuffList* temp = head;
	for (int i = begin+1; i < 26; i++)
	{
		if (data[i].freq != 0)
		{
			temp->next = new HuffList;
			temp->next->node = new HuffTree(data[i].chars, data[i].freq);
			temp = temp->next;
		}
	}
	temp->next = NULL;
	//**************************************************测试***********************************************//
	/*HuffList* testptr = head;
	cout << "***************************************************************************************************" << endl;
	for (; testptr != NULL; testptr = testptr->next)
	{
		cout << testptr->node->weight() << endl;
	}*/
	return head;
}

HuffList* insert(HuffList* head, HuffTree* node)
{
	HuffList* mark;
	mark = head;
	HuffList* memer = head;
	HuffList* fin = head;
	for (; head != NULL; head = head->next)
	{
		if (node->weight() <= head->node->weight())
		{
			for (; mark->next!= NULL; mark = mark->next)
			{
				if (mark->next== head)
				{
					HuffList*temp = new HuffList;
					temp->node = node;
					temp->next = head;
					mark->next = temp;
					return mark;
				}
			}
		}
		if (head->next == NULL)
		{
			memer = head;
		}
	}
	if (memer == NULL)
	{
		memer = new HuffList; memer->node = new HuffTree(*node);
		memer->next = NULL;
		return memer;
	}
	HuffList*temp = new HuffList;
	temp->node = node;
	temp->next = head;
	memer->next = temp;
	return temp;
}

HuffTree* buildHuffTree()
{
	HuffList* head = getTestData();
	HuffTree* temp = NULL;
	while ((head!=NULL)&&(head->next != NULL))
	{
		temp = new HuffTree(head->node, head->next->node);
		head = head->next->next;
		HuffList* out=insert(head, temp);
		HuffList* testptr = head;
		cout << "***************************************************************************************************" << endl;
		for (; testptr != NULL; testptr = testptr->next)
		{
		cout << testptr->node->weight() << endl;
		}
	}
	HuffList* out= insert(head, temp);
	return out->node;
}

void printCode(HuffNode* root)
{
	if ((root->leftChild() == NULL)&&(root->rightChild()==NULL))
	{
		cout <<root->getCode()<<' '<<root->val()<<endl;
		return;
	}
	printCode(root->leftChild());
	printCode(root->rightChild());
	cout << root->getCode();
}
void test()
{
	HuffTree* tree = buildHuffTree();
	printCode(tree->root());
}
