#include<iostream>
using namespace std;

int cvar=0;
int rvar[100];
int rvar1=0;
// Class for the structure of the node
class node
{
	public:
	int data;
	node * parent;
	node * left;
	node * right;
		
	node()
	{ data=0;
	parent=NULL;
	left=NULL;
	right=NULL;
}
} *root;

//Insertion function
void insert()
{
	int dat;
	cout<<"\nEnter data";
	cin>>dat;
	//1. temporary node for traversal
	node *temp=new node;
	//2. node to be added
	node *add=new node;
	add->data=dat;
	add->left=NULL;
	add->right=NULL;
	add->parent=NULL;
	temp->data=0;
	temp->left=NULL;
	temp->right=NULL;
	temp->parent=NULL;
	
	//basecase
	if(root==NULL)
	{
		root=add;
		root->parent=NULL;
		root->left=NULL;
		root->right=NULL;
		
	}
	
	else
	{	
		temp=root;
		//Finding the leaf
	
		while(1)
		{
		//	temp=root;
			if(temp->data > dat)
			{
				if(temp->left==NULL)
				{
				       
			temp->left=add;
			add->parent=temp;
			break;
				}
				else
				{
					temp=temp->left;
				}
			}
			else if(temp->data < dat)
			{

				if(temp->right==NULL)
				{
				       
			temp->right=add;
			add->parent=temp;
			break;
				}
				else
				{
					temp=temp->right;
				}
			}
			else if(temp->data == dat)
			{
				NULL;
			}
		}
		
		//Once found the node is installed in correct position
		
	}
}

//search function
node *search(int data)
{
	int dat;
	dat=data;
	int b=1;
	//Temporary variable for traversal
	node *temp=new node;
	temp=root;
	//while loop for searching node by node 
	while(1)
		{
		//	temp=root;
			if(temp->data > dat)
			{
				if(temp->left==NULL)
				{
				       break;
				}
				else
				{
					temp=temp->left;
				}
			}
			else if(temp->data < dat)
			{

				if(temp->right==NULL)
				{
				       
		
			break;
				}
				else
				{
					temp=temp->right;
				}
			}
			else if(temp->data == dat)
			{
			b=0;
			break;
			}
		}
		
		//Once found the node is installed in correct position
		
if(b==0)
cout<<"\nData is present";
else
cout<<"\nData is not present";

return temp;
}

void deletenode(int d)
{
      node *amma=new node;
      node *temp=new node;
      node *child=new node;
      node *grandchild=new node;
      child=NULL;
      grandchild=NULL;
      temp=search(d);
      //cout<<"idiot......"<<temp->data;
      amma=temp->parent;
     // cout<<"idiot......"<<amma->data;
      if(temp->left ==NULL && temp->right == NULL)
      {
      	if(amma->left->left==NULL)
      	{
      		amma->left=NULL;
      	}
      	else if(amma->right->right==NULL)
      	{
      		amma->right=NULL;
      	}
      }
      else if(temp->left==NULL || temp->right==NULL)
      {
      	
      	if(temp->left!=NULL)
      	{
      		child=temp->left;
      		if(amma->left==temp)
      		{
      			amma->left=child;
      		}
      		else if(amma->right==temp)
      		{
      			amma->right=child;
      		}
      	   	child->parent=amma;
      		temp->parent=NULL;
      		temp->left=NULL;
      		delete temp;
      		//cout<<"\nchild"<<child->data;
      	}
      	else if(temp->right!=NULL)
      	{
      		child=temp->right;
      		if(amma->right==temp)
      		{
      			amma->right=child;
      		}
      		else if(amma->left==temp)
      		{
      			amma->left=child;
      		}
      	   	child->parent=amma;
      		temp->parent=NULL;
      		temp->right=NULL;
      		delete temp;
      		//	cout<<"\nchild"<<child->data;
      	}
      	
      }
      else
      {
      	child=temp->left;
      	if(child->right==NULL)
      	{
      		temp->data=child->data;
      		temp->left=NULL;
      		delete child;
      	}
      	else
      	{
      	while(child->right->right!=NULL)
      	{
      		child=child->right;
      	}
      	grandchild=child->right;
      	temp->data=grandchild->data;
      	child->right=NULL;
      	delete grandchild;
      //	cout<<"\n idiot....."<<grandchild->data;
      //	cout<<"\n eruma......"<<temp->data;
      }
      }
      cout<<" and deleted\n";
}
//In order display function
int display(node *temp)
{
	if(temp==NULL)
	{
		return 0;
	}
	display(temp->left);
	cout<<temp->data<<"-->";
	
	display(temp->right);
	//cout<<"\t"<<temp->data<<"--";
}

int range(node *temp,int k1,int k2)
{
	if(temp==NULL)
	{
		return 0;
	}
	range(temp->left,k1,k2);
	if(temp->data<=k2 && temp->data>=k1)
	{
		rvar[rvar1]=temp->data;
		rvar1++;
	}
	
	range(temp->right,k1,k2);
	//cout<<"\t"<<temp->data<<"--";
}

int count(node *temp)
{
	if(temp==NULL)
	{
		return 0;
	}
	count(temp->left);
	cvar++;
	
	count(temp->right);
	//cout<<"\t"<<temp->data<<"--";
}
int main()
{
int a,n,k,achoice,bchoice,s,d,k1,k2,m;
	cout<<"\nEnter the initial tree";
	cout<<"\n enter the number of nodes";
            cin>>n;
	cout<<"\n enter the node keys";
	for(int i=0;i<n;i++)
	{
		insert();
	}
	cout<<"\n";
	a=display(root);
	do{
		cout<<"\nEnter option\t1)Insert\t2)Search\t3)Delete\t4)Count\t5)Range";
		cin>>achoice;
		switch(achoice)
		{
			case 1: insert();
				break;
			case 2:	cout<<"\n Enter the element to be searched";
				cin>>s;
				search(s);
				break;
			case 3: cout<<"\n Enter the element to be deleted";
				cin>>d;
				deletenode(d);
				break;
			case 4:	m=count(root);
				cout<<"\n The number of nodes in the BST is\t"<<cvar;
				break;
				
			case 5: 
				cout<<"\n Enter the lower limit and upper limit of values to be found in the BST and printed";
			            cin>>k1>>k2;
				range(root,k1,k2);
				cout<<"\n";
				for(int i=0;i<rvar1;i++)
				{
					cout<<rvar[i]<<"-->";
				}

			cout<<"\n";
				break;
		}
	cout<<"\n Do you wanna do somemore actions?  If yes press 1 if no press 0";
	cin>>bchoice;
	}while(bchoice==1);
	cout<<"\n\n The BST at the end of all operations is \n ";
	a=display(root);
	cout<<"*$*";
	
	
	return 0;
}
