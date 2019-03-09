#include<iostream>




using namespace std;






	class Node{

	public:
		int data;
		Node *left;
		Node *right;

		Node(int val){
			left=NULL;
			right=NULL;
			data=val;
	}
	};



	class BST{

	public:
		Node *root;
		
		BST(){
		root=NULL;
		}	
		
		void insert(int data){
			insertHelper(root,data);
		}

		void insertHelper(Node *current, int value){
			//base case
				if(root==NULL){
					root=new Node(value);
				}
				
			
			else if(value<current->data){
				if(current->left==NULL) {current->left=new Node(value);}
				else {insertHelper(current->left,value);}
			}			

			else{
				if(current->right==NULL) {current->right=new Node(value);}
				else {insertHelper(current->right,value);}
			}

		}
		void display(){display2(root);
				cout<<endl;}
		
		void display2(Node * curr){
			//Base case
			if(curr==NULL) return;
			//display left
			else{
			//display left
			display2(curr->left);
			//display current
			cout<<curr->data<<",";
			//display right
			display2(curr->right);
			}
			
		}

		Node *search(int value){
			 search2(root,value);
		}
		Node *search2(Node *current, int value){
			if (current==NULL || current->data==value) return current;
			else if(value<current->data) search2(current->left, value);
			else search2(current->right, value);
		}


	};





	int main(){

		BST b;

		b.insert(5);
		b.insert(7);
		b.insert(8);
		b.insert(4);
		b.insert(6);

		if (b.search(6)!=NULL){cout<<"Found!"<<endl;}

		if (b.search(9)!=NULL){cout<<"Found!"<<endl;}
		else cout<<"Not in here!"<<endl;
					
		
		b.display();

	}




























































