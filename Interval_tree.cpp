#include <iostream>
#include <math.h>
using namespace std;

struct Interval{
	int low;
	int high;
};

struct Node{
	interval *p;
	int max;
	Node *left;
	Node *right;
};

Node* insert(Node* root,Interval p){
	if(root == NULL){
		Node* temp=new Node;
		temp->p = new Interval(p);
		temp->max = p.high;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
	
	int left= root->p->low;
	if(p.low<l)
		root->left = insert(root->left, i);
    else
        root->right = insert(root->right, i);
    
    if(root->max < p.high)
    	root->max=p.high;
    return root;
}



int main(){
	Interval arr[]={{15,20},{10,30}{17,19},{5,20},{12,15},{30,40}};
	int l=arr.length();
	Node* root=NULL;
	Node* temp=root;
	for(int i=0;i<l;i++){
		temp=insert(root,arr[i]);
	}
	
	
}
