
#include <iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

struct node
{
  int key_value;
  node *left;
  node *right;
}; // struct

node *root = NULL;
class BTree
{
  private: 
            int num[100], count=0, value;
            void insert(int key, node *leaf);
            node* deleteNode (node* current, int data);
            void printInorder(node *current);
            node* findMin(node *current);
  public: 
            void introduction(void);
            void readFile();
            void insert(int index);
            void readAValue();
            void print();
            void deleteNode();
    
}; //class



void BTree::introduction()
{
    system("clear");
    cout<<"Write a C++ Object Oriented Programming to read a set of values from a text file and perform the following operations:"<<endl;
    cout<<"1. Insert the values into a Binary Search Tree - to create a tree."<<endl;
    cout<<"2. Insert a given value into this tree."<<endl;
    cout<<"3. Delete a given value from the tree."<<endl;
    cout<<"4. Using quick sort, sort the BST values."<<endl;
    cout<<"5. Write the BST values after sorting into another text file."<<endl;
    cout<<"6. Read sorted values from a text file and print on the screen."<<endl;
    cout<<endl<<endl;
} //introduction

void BTree:: readFile()
{
    for(int i=0;i<5;i++)
    cin>>num[i];
} //read

void BTree::readAValue()
{
    cout<<"Enter a value: "<<endl;
    cin>>value;
}//read

void BTree::insert(int index )
{
    if(index == 0) // from file multiple values
    {
        for(int i=0;i<count;i++)
        insert(num[i],root);
    }
    else
    {
        insert(value, root);
    }
     
}

void BTree::insert(int key, node *current)
{
  if(key< current->key_value)
  {
    if(current->left == NULL)
    {
        current->left=new node;
        current->left->key_value=key;
        current->left->left=NULL;    //Sets the left child of the child node to null
        current->left->right=NULL;   //Sets the right child of the child node to null
        if(root == NULL)
        root = current; //setting top value as root of the tree
    }
     
    else
    {
        insert(key, current->left); 
    }  
    
  } // condition for left 
  
  else if(key>=current->key_value)
  {
    if(current->right == NULL)
    {
        current->right=new node;
        current->right->key_value=key;
        current->right->left=NULL;  //Sets the left child of the child node to null
        current->right->right=NULL; //Sets the right child of the child node to null
        if(root == NULL)
        root = current; // setting top value as root of the tree
    }
    
    else
    {
        insert(key, current->right);  
    }
  } // condition for right
} //insert


void BTree::deleteNode()
{
    deleteNode(root,value);
}

node* BTree:: deleteNode (node* current, int data)
{

if(current == NULL) cout<<"Tree empty";
else if(data < current->key_value) 
    current->left = deleteNode(current->left,data);
else if(data > current->key_value) 
    current->right = deleteNode(current->right,data);
else // found data 
	{ // case 1: leaf node deletion
	if(current->left == NULL && current->right == NULL) 
	{
	delete current;
	current = NULL;
	}
	//case 2 : deletion of the node with a single child
	else if(current->left == NULL) {
	node * temp = current;
	current= current->right;
	delete current;
	}
	else if(current->right == NULL) {
	node * temp = current;
	current= current->left;
	delete current;
	}
	
	else // case 3: with both child
	{
	node *temp = findMin(current->right);
	current->key_value = temp->key_value;
	current->right = deleteNode(current->right, temp->key_value);
	}
	}
}


node* findMin(node *ptr)
{
    node *temp = ptr;
    while(temp->left != NULL)
    {
        temp= temp->left;
    }
    return temp;
}	
	
void BTree:: print()
 {
    printInorder(root);   
 }

void printInorder(node *current)
{
    if(current != NULL)
    {
        if(current->left != NULL)
        {
            printInorder(current->left);
        }
        cout<<current->key_value<<"\t";
        if(current->right != NULL)
        {
            printInorder(current->right);
        }
    }
}


	

int main()
{
    BTree obj;
    obj.introduction();
    obj.readFile();
    obj.insert(0);
    obj.print();
    cout<<"Enter a value to insert into the BST: "<<endl;
    obj.readAValue();
    obj.insert(1);
    obj.print();
    cout<<"Enter a value to delete from the BST: "<<endl;
    obj.readAValue();
    obj.deleteNode();
    obj.print();
    
    
    
    
    return 0;
}




