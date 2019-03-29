#include<iostream>





using namespace std;






	class Node{
		public:
		int data;
		Node *parent;
		Node *left;
		Node *right;
		
		Node(int val){
			data=val;
			parent=NULL;
			left=NULL;
			right=NULL;
		}

	};



	class BiST{
		public:
		int count=0;
		Node *root;
		BiST(){
			root=NULL;
		}
	
		void insert(int n) {
			count++;
			insert2(n,root);
		}

		void insert2(int val,Node *temp) {
			
			if(root==NULL){
				root=new Node(val);
			}

			else if(val<temp->data) {
				if(temp->left==NULL){
					temp->left =new Node(val);
					temp->left->parent=temp;
				}

				else insert2(val,temp->left);
				

			}		

			else {
				if(temp->right==NULL){
					temp->right=new Node(val);
					temp->right->parent=temp;
				}

				else insert2(val,temp->right);
				
			
			}
	
		}

		

		void del(int number){
			count--;
			Node *current=search(number);
			Node *temp;
			Node *min;
			int l;
			if(current->left==NULL&&current->right==NULL){
				if(current==root){
					root=NULL;
					delete current;
				}
				else{
				temp=current;		
				replace(current,NULL);
				delete temp;
				}
			}
			
			else if(current->right!=NULL&&current->left==NULL){
				if(current==root) {
					root=current->right;
					temp=current;
					root->parent=NULL;
					delete temp;
				}
				else{
				temp=current;
				replace(current,current->right);
				delete temp;
				}
			}
			
			else if(current->left!=NULL&&current->right==NULL){
				if(current==root) {
					root=current->left;
					temp=current;
					root->parent=NULL;
					delete temp;
				}
				else{
				temp=current;
				replace(current,current->left);
				delete temp;
				}
			}

			else if(current->left!=NULL&&current->right!=NULL){

				min=find_min(current);
				temp=min;
				l=min->data;
				min->data=current->data;
				current->data=l;

				min->parent->left=min->right;
				delete temp;

			}
			

		}
		


		void sp_display(){
			sp_display2(root,0);
		}

		void sp_display2(Node *current, int space){
			
			if(current==NULL) return;
			space+=10;
		
			sp_display2(current->right,space);
			cout<<endl;
		
			for(int i=0;i<space;i++){
				cout<<" ";
			}
			cout<<current->data<<endl;

			sp_display2(current->left,space);
			
		}			


		void display(){
			display2(root);
			cout<<endl;
		}

		void display2(Node *current){
			if(current==NULL) return;
			else{
				display2(current->left);
				cout<<current->data<<"->";
				display2(current->right);
			}
		}

		void replace (Node *current, Node *temp){
			
			if(current->data<current->parent->data) {
				current->parent->left=temp;
				//temp->parent=current->parent;
			}		
			else {
				current->parent->right=temp;
				//temp->parent=current->parent;
			}

		}
		
		Node *find_min(Node *current){
			while(current->left!=NULL){
				current=current->left;
			}

			return current;
		}

		
		Node * search(int value){
			search2(root,value);
		}

		Node *search2(Node *current, int value){
			if(current==NULL||current->data==value) return current;
			else if(current->data<value) search2(current->right,value);
			else search2(current->left,value);
		}

		
		
		int Count(){
			return count;
		};	

		int rangeSearch(int a, int b){
			rangeSearch2(root,a,b);
			cout<<endl;
		}	
		
		void rangeSearch2(Node * current,int a,int b){
			if(current==NULL) return;
		
			else {
				rangeSearch2(current->left,a,b);
				if(current->data>=a && current->data<=b) cout<<current->data<<"->";
				rangeSearch2(current->right,a,b);
			}
			
		} 
	
		int height(){
			return height2(root);
			
		}

		int height2(Node *current){
			if(current==NULL) return 0;

			int lh = height2(current->left);
			int rh = height2(current->right);
			
			if(lh>rh) return (lh+1);
			else return (rh+1);
		}
		
				
	
	};






	int main(){
	
	BiST b1;

	b1.insert(6);
	b1.insert(10);
	b1.insert(4);
	b1.insert(5);
	b1.insert(7);
	b1.insert(9);
	b1.insert(1);
	b1.insert(3);
	b1.insert(2);

	cout<<b1.Count()<<endl;
	
	b1.rangeSearch(2,9);

	cout<<b1.height()<<endl;

	b1.sp_display();



	return 0;

	}












