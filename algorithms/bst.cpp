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

bool search(node* root, int element)
{
	if (root == NULL)
		return false;

	if (root->data == element)
		return true;

	if (element > root->data)
		return search(root->rgt, element);
	else
		return search(root->left, element);
}

node* insert(node* root, int element)
{
	if (root == NULL)
		return newNode(element);

	if (element > root->data)
		root->rgt =  insert(root->rgt, element);
	else
		root->left = insert(root->left, element);

	return root;
		
}

node* inorder_successor(node* root)
{
	node* current = root;
	while (current != NULL && current->left != NULL)
		current = current->left;


	return current;
}
node* deletenode(node* root, int element)
{
	if (root == NULL)
		return root;

	if (element > root->data)
		root->rgt = deletenode(root->rgt, element);
	else if (element < root->data)
		root->left = deletenode(root->left, element);
	else //element == root->data
	{
		
		if (root->left == NULL)   // 1 rgt child
		{
			node* temp = root->rgt;
			delete(root);
			return temp;
		}
		else if (root->rgt == NULL) // 1 left child
		{
			node* temp = root->left;
			delete(root);
			return temp;
		}
		else //2 child
		{
			node* temp = inorder_successor(root->rgt);
			root->data = temp->data;
			root->rgt = deletenode(root->rgt, temp->data);
			
		}
		

	}
	return root;


}


void inorder(node* root)
{
	if (root == NULL)
		return;

	inorder(root->left);
	cout << root->data << "  ";
	inorder(root->rgt);
}

void findpresuc(node* root, node*& pre, node*& suc, int key)
{
	if (root == NULL)
		return;
	
	if (root->data == key)
	{

		if (root->left != NULL)
		{
			node* temp = root->left;
			while (temp != NULL && temp->rgt != NULL)
				temp = temp->rgt;

			pre = temp;
		}

		if (root->rgt != NULL)
		{
			node* temp = root->rgt;

			while (temp != NULL && temp->left != NULL)
				temp = temp->left;

			suc = temp;
		}
		return;
			   		 
	}

	if (key > root->data)
	{
		suc = root;
		findpresuc(root->rgt, pre, suc, key);
	}

	if (key < root->data)
	{
		pre = root;
		findpresuc(root->left, pre, suc, key);
	}
		
}

int main()
{
	node* root = newNode(8);

	root->left = newNode(3);
	root->rgt = newNode(10);
	root->left->left = newNode(1);
	root->left->rgt = newNode(6);
	root->rgt->rgt = newNode(14);
	root->left->rgt->left = newNode(4);
	root->left->rgt->rgt = newNode(7);

	//node* temp = newNode(1);
	//temp->left = newNode(5);
	//temp->rgt = newNode(6);
	//temp->left->left = newNode(11);
	//temp->left->rgt = newNode(152);

	
	root = insert(root, 1764);
	root = insert(root, 53);
	root = insert(root, 12);
	inorder(root);
	//root = deletenode(root, 8);
	//cout << "\n after deleting \n";
	//inorder(root);


	node* pre = NULL, *suc = NULL;

	int key = 8;
	findpresuc(root, pre, suc, key);
	if (pre != NULL)
		cout << "\nPredecessor is " << pre->data << endl;
	else
		cout << "\nNo Predecessor";

	if (suc != NULL)
		cout << "\nSuccessor is " << suc->data;
	else
		cout << "\nNo Successor";


	return 0;

}