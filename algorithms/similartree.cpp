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


bool areidentical(node* main, node* temp)
{
	if (temp == NULL && main == NULL)
		return true;

	if (temp == NULL || main == NULL)
		return false;

	return (main->data == temp->data && areidentical(main->left, temp->left) && areidentical(main->rgt, temp->rgt));
}

bool isssame(node* main, node* temp)
{
	if (temp == NULL)
		return true;
	if (main == NULL)
		return false;

	if (areidentical(main, temp))
		return true;

	return (isssame(main->left, temp) || isssame(main->rgt, temp));
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
	root->left->left->rgt = newNode(15);

	node* temp = newNode(1);
	temp->left = newNode(5);
	temp->rgt = newNode(6);
	temp->left->left = newNode(11);
	temp->left->rgt = newNode(152);


	cout << isssame(root, temp);

	
	return 0;

}