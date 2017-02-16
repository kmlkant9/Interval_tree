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

Interval* search(Node* root, Interval p){
	if(root==NULL) 
		return NULL;
	
	if(root->p->low <= p.high && root->p->high >= p.low)
		return root->p;
	
	if(root->left!=NULL && root->left->max >= p.low)
		return search(root->left, p);
	else
		return search(root->right,p);
}


int main(){
	Interval arr[]={{15,20},{10,30}{17,19},{5,20},{12,15},{30,40}};
	int l=arr.length();
	Node* root=NULL;
	Node* temp=root;
	for(int i=0;i<l;i++){
		temp=insert(root,arr[i]);
	}
	
	Interval x=new Interval();
	cout<<"enter search interval"<<endl;
	cin>>x.low>>x.high;
	Interval* x_tree=search(root,x);
	if(x_tree ==NULL)
		cout<<"No such Interval"<<endl;
	else
		cout<<x_tree->low<<","<<x_tree->high<<endl;
	
}
