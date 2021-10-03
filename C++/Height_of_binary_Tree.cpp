
/* Method to solve this problem is to do Level Order Traversal. 
  While doing the level order traversal, while adding Nodes at each level to Queue, 
we have to add NULL Node so that whenever it is encountered,
we can increment the value of variable and that level get counted. */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node
{
	int key;
	struct Node* left, *right;
};


Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

/*Function to find the height(depth) of the tree*/
int height(struct Node* root){

	//Initialising a variable to count the
	//height of tree
	int depth = 0;

	queue<Node*>q;

	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
	
		//When NULL encountered, increment the value
		if(temp == NULL){
			depth++;
		}
		
		//If NULL not encountered, keep moving
		if(temp != NULL){
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	
		//If queue still have elements left,
		//push NULL again to the queue.
		else if(!q.empty()){
			q.push(NULL);
		}
	}
	return depth;
}

// Driver program
int main()
{
//creating a binary tree
	Node *root = newNode(1);
	root->left = newNode(12);
	root->right = newNode(13);

	root->right->left = newNode(14);
	root->right->right = newNode(15);

	root->right->left->left = newNode(21);
	root->right->left->right = newNode(22);
	root->right->right->left = newNode(23);
	root->right->right->right = newNode(24);

	cout<<"Height(Depth) of tree is: "<<height(root);
}


//Most optimal solution 
//Time complexity is O(N).
//Space complexity O(N).
