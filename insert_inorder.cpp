
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
        void insert(node *, node *);
        void inorder(node *);
        int num[100];
    public:
        BST();
        void insert();
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

void BST::insert()
{
    for(int i=0;i<5;i++)
    {
    node *temp;
    temp = new node;
    temp->data = num[i];
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


int main()
{
    BST bst;
    bst.read();
    bst.insert();
    cout<<"Inorder Traversal of BST:"<<endl;
    bst.inorder();
    return 0;
}
 
 