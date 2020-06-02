
# include <iostream>
# include <cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

 
class BST
{
    private:
        node *root;
        int value;
        void insert(node *, node *);
        void inorder(node *);
        void deleteNode(int);
        int num[100];
    public:
        BST();
        void insert(int);
        void getValue();
        void deleteNode();
        void inorder();
        void display(node *, int);
        void read();
        
};

BST::BST()
{
    root = NULL;
}

void BST::read()
{
    cout<<"ENter any five integer value:";
    for(int i=0;i<5;i++)
    cin>>num[i];
}

void BST::insert(int flag)
{
    if(flag == 1) // insert records from file
    {
    for(int i=0;i<5;i++)
    {
    node *temp;
    temp = new node;
    temp->data = num[i];
    insert(root, temp);
    }
    }
    
    else //insert a single input value from user
    {
    node *temp;
    temp = new node;
    temp->data = value;
    insert(root, temp);
    }
    
}

void BST::insert(node *tree, node *newnode)
{
    if (root == NULL)
    {
        node *head = new node;
        head->data = newnode->data;
        head->left = NULL;
        head->right = NULL;
        root = head;
    }
   
    else if (tree->data > newnode->data)
    {
        if (tree->left != NULL)
        {
            insert(tree->left, newnode);
        }
        else
        {
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
        }
    }
    
    else if(tree->data < newnode->data)
    {
        if (tree->right != NULL)
        {
            insert(tree->right, newnode);
        }
        else
        {
            tree->right = newnode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
        }
    }
    
    else if(tree->data == newnode->data)
    {
        cout<<"Duplicate node! Can not construct BST ";
        exit(0);
    }

}

void BST:: inorder()
{
    inorder(root);
}
 // In Order Traversal

void BST::inorder(node *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->left);
        cout<<ptr->data<<"  ";
        inorder(ptr->right);
    }

}


void BST:: getValue()
{
    cin>>value;
}

// delete node
void BST::deleteNode()
{
    deleteNode(value);
}

void BST::deleteNode(int d)
{
    //Locate the element
    
    bool found = false;
    node* curr;
    node* parent;
    curr = root;
    
    while(curr != NULL)
    {
         if(curr->data == d)
         {
            found = true;
            break;
         }
         else
         {
             parent = curr;
             if(d>curr->data) 
             curr = curr->right;
             else 
             curr = curr->left;
         }
    }
    
    if(!found)
		 {
        cout<<" Data not found! Delete unsuccessful! "<<endl;
        exit(0);
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
                
		    curr->data = lcurr->data;
            delete lcurr;
            lcurrp->left = NULL;
           }
           else
           {
               node* tmp;
               tmp = curr->right;
               curr->data = tmp->data;
	           curr->right = tmp->right;
               delete tmp;
           }

        }
		 return;
    }

}

// delete node end



int main()
{
    BST bst;
    bst.read();
    bst.insert(1);
    cout<<"Records are inserted successfully! "<<endl;
    cout<<"-----------------------------------"<<endl<<endl;
    cout<<"Inorder Traversal of BST:"<<endl;
    bst.inorder();
    cout<<endl<<endl;
    cout<<"Enter a value to insert into the tree: "<<endl;
    bst.getValue();
    bst.insert(0);
    cout<<"Inorder Traversal after insertion: "<<endl;
    bst.inorder();
    cout<<endl<<endl;
    cout<<"Enter a value to delete from the tree: "<<endl;
    bst.getValue();
    bst.deleteNode();
    cout<<"Inorder traversal after deletion: "<<endl;
    bst.inorder();
    cout<<endl<<endl;
    return 0;
}
 
 