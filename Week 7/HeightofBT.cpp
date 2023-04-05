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

void countofnodes(node *root,int &cnt){
    if(root){
        countofnodes(root->left,cnt);
        cnt++;
        countofnodes(root->right,cnt);
    }
}

int main()
{
   node *root=NULL;
   //creating the Binary Tree
    root=buildTree(root);
    int cnt=0;
    countofnodes(root,cnt);
    cout<<"Number of nodes is: "<<cnt;
    return 142;
}
