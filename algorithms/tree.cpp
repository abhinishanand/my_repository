#include<iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* rgt;
};

node* newNode(int data)
{
	node* temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->rgt = NULL;

	return temp;
}


void inorder(node* root)
{
	if (root == NULL)
		return;

	inorder(root->left);
	cout << root->data<<endl;
	inorder(root->rgt);
}


int main()
{
	node* root = newNode(1);
	
	root->left = newNode(2);
	root->rgt = newNode(3);
	root->left->left = newNode(5);
	root->left->rgt = newNode(6);
	root->rgt->left = newNode(7);
	root->rgt->rgt = newNode(8);

	inorder(root);
	return 0;

}