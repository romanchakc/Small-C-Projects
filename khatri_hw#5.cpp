// Romancha Khatri
// khatri_hw#5.cpp
// Due October 20, 2017
// Implementation of stack using an array


#include <iostream>
#include<cstdlib>
using namespace std;
struct node
{
    int data;
    node* next;
    node* previous;
};

void introduction(void);
void readData(int x[], int &n); // reading values
void insert(int x[],int n);
void show();
void showReverse();
void copy(int stackData[],int &top);
void readStack(int stackData[],int top);
void removeList();

node *head = NULL; // intializing head to NULL

int main()
{
    int n, x[100],stackData[100],top;
    introduction();
    readData(x,n);
    insert(x,n);
    show();
    showReverse();
    copy(stackData, top);
    readStack(stackData,top);
    removeList();
    return 0;
} //main

void introduction()
{
    system("clear");
    cout<<"Write a program in c++ to: "<<endl;
    cout<<"Create a doubly linked list."<<endl;
    cout<<"1. Use a function to insert following items in the list: 4, 5, 14, 13, 21, 45, 46, 37, 40"<<endl;
    cout<<"2. Use a print function to print the data in order inserted."<<endl;
    cout<<"3. Use a print function to print the data in Reverse order inserted."<<endl;
    cout<<"4. Use a function to copy the linked Elements into a stack."<<endl;
    cout<<"5. Use a function to print the elements in the stack."<<endl;
    cout<<"6. Use a function to delete the nodes in the linked list."<<endl;
    cout<<"---------------------------------------------------------------------------------------------"<<endl<<endl;
} // introduction


void readData(int x[], int &n)
{
    cout<<"Enter the number of items to be inserted :";
    cin>>n;
    cout<<"Enter items to insert in the linked list: "<<endl;
    for(int i=0;i<n;i++)
    cin>>x[i];
	cout<<endl<<endl;
} // readData

void insert(int x[],int n)
{
    node *current = head;
    
    for(int i=0;i<n;i++)
    {
        node* newnode = new node();
        newnode->data = x[i];
        if(head == NULL)
        {
            newnode->previous = NULL;
            newnode->next = NULL;
            head = newnode;
            current = newnode;
        } //if
        
        else
        {
            newnode->next = NULL;
            newnode->previous = current;
            current->next = newnode;
            current = newnode;
        } //else
        
    } //for
    
}//insert


void show()
{
    
    node* current = head;
    if(current == NULL) // check if list is empty
        {
            cout<<"Empty linked list !"<<endl;
            return;
        }
    cout<<"Items in the linked list in inserting order: (Head to Tail):  "<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    while(current) 
    {
        cout<<current->data<<"\t";
        current = current->next;
    } // while
    cout<<endl<<endl<<endl;
} // show

void showReverse()
{
   
    node* current = head;
    
    if(current == NULL) // check if list is empty
        {
            cout<<"Empty linked list !"<<endl;
            return;
        }
    
    
    while(current->next != NULL) // moving into last node
        {
            current= current->next;
        }
    
    cout<<"Displaying items in the linked list in reverse order: ( Tail to Head): "<<endl;
    cout<<"-------------------------------------------------------------------------"<<endl;
    while(current != NULL) // traversing backward
        {
            cout<<current->data<<"\t";
            current= current->previous;
        }
   
    cout<<endl<<endl<<endl;

} // showReverse


void copy(int stackData[], int &top)
{
    top = -1;
    node* current = head;
    while(current)
    {
        ++top; //increasing top by 1
        stackData[top] = current->data;
        current = current->next;
    }
    
    cout<<"Items from the linked list are successfully copied into the stack. "<<endl<<endl<<endl;
    
} // copy

void readStack(int stackData[], int top)
{
    if(top == -1)
        {
            cout<<"Stack is Empty ! "<<endl;
            return;
        } //if
    cout<<"Items in the stack: (LIFO) - Accessing/Popping in reverse order as inserted  "<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl;
    while(top != -1)
    {
        cout<<stackData[top]<<"\t";
        --top;
    } //while
    cout<<endl<<endl<<endl;
} // readStack

void removeList()
{
    node* current  = head;
    node* temp;
    while(current)
    {
        temp = current->next; //creating new link
        if(temp != NULL)
	    temp->previous = NULL; //breaking previous link
        delete current; // delete node
        current = temp;
    }
    cout<<"Nodes are successfully deleted. "<<endl<<endl<<endl;
} // removeList
