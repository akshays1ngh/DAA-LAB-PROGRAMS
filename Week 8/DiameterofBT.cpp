/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;
class node{
    public:
        int data;
        node *left;
        node *right;
        
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node *buildTree(node* root){
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;
    
    root=new node(data);
    
    if(data==-1)
        return NULL;
    
    cout<<"Enter data for inserting in left of : "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for inserting in right of : "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
    
}

int check(node* root,int &maxi){
        if(root==NULL)return 0;
        int l=check(root->left,maxi);
        int r=check(root->right,maxi);

        maxi=max(maxi,l+r);// maximum addition of left and right height at any node.

        return 1+max(l,r);
    }

int main()
{
   node *root=NULL;
   //creating the Binary Tree
    root=buildTree(root);
    int maxi=0;
    check(root,maxi);
    cout<<"Diameter of BT is: "<<maxi;
    return 142;
}