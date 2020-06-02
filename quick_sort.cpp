
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

class BTree
{
  private:  node *root;
            int num[100], count=0, value;
            void insert(int key, node *leaf);
            void deleteNode(int d);

  public:   BTree();
            void introduction(void);
            void readFile();
            void insert();
            void readAValue();
            void print();
            void deleteNode();
    
}; //class


BTree::BTree()
{
    root = NULL; // initializing root pointing NULL pointer
} // constructor

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
    ifstream in("file1.dat");
    if(!in)
    {
        cout<<"Error in opening a file!"<<endl;
        exit(1);
    }
    while(in)
    {
        num[j]>>in;
        ++cout;
    }
    in.close();
    cout<<"File has been successfully read. "<<endl<<endl;
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


void BTree::inorder()
{
    inorder(root);
}

void BTree::inorder(node *current)
{
    if(current == NULL)
        {
        cout<<"Tree is empty !";
        exit(1);
        }
    
    if (current != NULL)
    {
        inorder(current->left);
        cout<<current->key_value<<"\t";
        inorder(current->right);
    }
 }
 
 

void BTree::deleteNode()
{
    deleteNode(value);
}

void BTree::deleteNode(int d)
{
    //Locate the element
    
    bool found;
    node* curr;
    node* parent;
    curr = root;
    
    while(curr != NULL)
    {
         if(curr->key_value == d)
         {
            found = true;
            break;
         }
         else
         {
             parent = curr;
             if(d>curr->key_value) 
             curr = curr->right;
             else 
             curr = curr->left;
         }
    }
    
    if(!found)
		 {
        cout<<" Data not found! "<<endl;
        return;
    }


    
    // Node with single child
    if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL&& curr->right == NULL))
    {
       if(curr->left == NULL && curr->right != NULL)
       {
           if(parent->left == curr)
           {
             parent->left = curr->right;
             delete curr;
           }
           else
           {
             parent->right = curr->right;
             delete curr;
           }
       }
       else // left child present, no right child
       {
          if(parent->left == curr)
           {
             parent->left = curr->left;
             delete curr;
           }
           else
           {
             parent->right = curr->left;
             delete curr;
           }
       }
     return;
    }

		 //looking at a leaf node
	if( curr->left == NULL && curr->right == NULL)
        {
            if(parent->left == curr) 
            parent->left = NULL;
                else 
                parent->right = NULL;
		        
		       delete curr;
		       return;
        }


    //Node with 2 children
    // replace node with inorder successor i.e. smallest value in right subtree
    if (curr->left != NULL && curr->right != NULL)
    {
        node* chkr;
        chkr = curr->right;
        if((chkr->left == NULL) && (chkr->right == NULL))
        {
            curr = chkr;
            delete chkr;
            curr->right = NULL;
        }
        else // right child has children
        {
    
            if((curr->right)->left != NULL)
            {
                node* lcurr;
                node* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != NULL)
                {
                   lcurrp = lcurr;
                   lcurr = lcurr->left;
                }
                
		    curr->key_value = lcurr->key_value;
            delete lcurr;
            lcurrp->left = NULL;
           }
           else
           {
               node* tmp;
               tmp = curr->right;
               curr->key_value = tmp->key_value;
	           curr->right = tmp->right;
               delete tmp;
           }

        }
		 return;
    }

}




int main()
{
    BTree obj;
    obj.introduction();
    obj.readFile();
    obj.insert(0);
    obj.inorder();
    cout<<"Enter a value to insert into the BST: "<<endl;
    obj.readAValue();
    obj.insert(1);
    obj.inorder();
    cout<<"Enter a value to delete from the BST: "<<endl;
    obj.readAValue();
    obj.deleteNode();
    obj.inorder();
    
    
    
    
    return 0;
}


