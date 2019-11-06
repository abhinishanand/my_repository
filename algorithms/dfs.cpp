#include<iostream>
#include<queue>
using namespace std;

int max(int a, int b)
{
	return a >= b ? a : b;
}


struct node
{
	int data;
	node* left = NULL;
	node* rgt = NULL;
};

node* newNode(int data)
{
	node* temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->rgt = NULL;

	return temp;
}

void dfs(node* root)
{
	if (root == NULL)
		return;

	queue<node*> q;
	q.push(root);
	while (!q.empty())
	{
		node* ctr = q.front();
		if(ctr!=NULL)
		cout << ctr->data<<"  ";
		q.pop();

		if(ctr->left!=NULL)
		q.push(ctr->left);

		if(ctr->rgt!=NULL)
		q.push(ctr->rgt);
		

	}
}


int height(node* root)
{
	if (root == NULL)
		return -1;
	else
		return max (height(root->left),height(root->rgt)) + 1;
}

bool issubtreelesser(node* root, int value)
{
	if (root == NULL)
		return true;

		if (root->data < value && issubtreelesser(root->left, value) && issubtreelesser(root->rgt, value))
			return true;
		else
			return false;

}

bool issubtreegreater(node* root, int value)
{
	if (root == NULL)
		return true;

	if (root->data > value && issubtreegreater(root->left, value) && issubtreegreater(root->rgt, value))
		return true;
	else
		return false;

}


bool isBST(node* root)
{
	if (root == NULL)
		return true;

	if (isBST(root->left) && isBST(root->rgt) && issubtreegreater(root->rgt, root->data) && issubtreelesser(root->left, root->data))
		return true;
	else
		return false;

}
int main()
{
	node* root = newNode(2);

	root->left = newNode(1);
	root->rgt = newNode(3);
	root->left->left = newNode(5);
	root->left->rgt = newNode(6);
	root->rgt->left = newNode(7);
	root->rgt->rgt = newNode(8);
	root->left->left->left = newNode(11);
	root->left->left->left->left = newNode(15);

	int treeheight = height(root);
	//cout << treeheight;

	cout << isBST(root);
	return 0;

}