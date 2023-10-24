//24-10-2023
//KshitizSachan

//Checking if a binary tree is balanced or not
// O(n^2) and O(n)
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
	
	TreeNode(int value){
		data=value;
		left=NULL;
		right=NULL;
	}
};

void level(TreeNode* root){
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	int lev=0;
	while(!q.empty()){
		if(q.front()==NULL){
			q.pop();
			lev++;
		}
		else{
			while(q.front()!=NULL){
				TreeNode* curr=q.front();
				q.pop();
				cout<<curr->data<<" ";
				
				if(curr->left)
				q.push(curr->left);
				if(curr->right)
				q.push(curr->right);
			}
			q.push(NULL);
			cout<<endl;
			
		}
	}
}

int height(struct TreeNode* root){
	if(root==NULL)
	return 0;
	
	return max(height(root->left), height(root->right))+1;
}

// O(n^2)
bool checkBalance(struct TreeNode* root){
	if(root==NULL)
	return true;
	
	if(!checkBalance(root->left))
	return false;
	
	if(!checkBalance(root->right))
	return false;
	
	return (abs(height(root->left) - height(root->right))<=1);
}

//O(n)
bool optimizedCheckBalance(TreeNode* root, int* height){
	int lh=0, rh=0;
	if(root==NULL)
	return true;
	if(!optimizedCheckBalance(root->left, &lh))
	return false;
	if(!optimizedCheckBalance(root->right, &rh))
	return false;
	
	*height=max(lh, rh)+1;
	if(abs(lh-rh)<=1)
	return true;
	else
	return false;
}



int main(){
	TreeNode* root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	root->right->left=new TreeNode(6);
	root->right->right=new TreeNode(7);
	
	level(root);
//	cout<<height(root);

	cout<<"Is the tree balanced: "<<checkBalance(root)<<endl;
	int height=0;
	cout<<"Is the tree balanced(Optimized): "<<optimizedCheckBalance(root, &height);

}











