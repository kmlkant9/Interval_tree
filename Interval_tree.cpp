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

void delete_search(Node* root,Interval x){
	
	if(root==NULL)
		return;

	Interval* p=new Interval();
	p=search(root,x);
	if(p==NULL)
	{cout<<"no such interval found"<<endl;return;}
		
	delete(root,x);
}

void delete(Node* root,Interval x){
	if(root->p->low == x.high && root->p->high == x.low){
		Node* temp=root->right;
		root=root->left;
		root->right=temp;
		if(root->max < root->right->max)
			root->max=root->right->max;
		return;
	}
	if(root->left!=NULL && root->left->max >= x.low)
		delete(root->left, x);
	else
		delete(root->right,x);
}

void print(Node* root){
	if(root==NULL) return;
	
	print(root->left);
	cout<<root->p->low<<","<<root->p->high<<" max= "<<root->max<<endl;
	print(root->right);
}

int main(){
	Interval arr[]={{15,20},{10,30}{17,19},{5,20},{12,15},{30,40}};
	int l=arr.length();
	Node* root=NULL;
	Node* temp=root;
	for(int i=0;i<l;i++){
		temp=insert(root,arr[i]);
	}
	cout<<"Original Tree:"<<endl;
	print(root);
	
	Interval x=new Interval();
	cout<<"enter search interval"<<endl;
	cin>>x.low>>x.high;
	Interval* x_tree=search(root,x);
	if(x_tree ==NULL)
		cout<<"No such Interval"<<endl;
	else
		cout<<x_tree->low<<","<<x_tree->high<<endl;
	
	cout<<"enter deletion interval"<<endl;
	cin>>x.low>>x.high;
	delete_search(root,x);
	cout<<"After Deletion:"<<endl;
	print(root);
	
	
}
