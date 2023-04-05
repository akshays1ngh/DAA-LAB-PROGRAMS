#include<bits/stdc++.h>
using namespace std;



struct Node{
 int data;
 Node *left,*right;
};



Node* insert(Node *root,int data){
 Node *newnode=new Node;

 if(root==NULL){
 newnode->data=data;
 newnode->left=NULL;
 newnode->right=NULL;
 root=newnode;
 return root;
 }
if(data<=root->data)
 root->left=insert(root->left,data);
 else
 root->right=insert(root->right,data);
 return root;
}



Node* constructBST(int arr[],int n){
if(n==0)
return NULL;

 Node *root=NULL;
 for(int i=0;i<n;i++)
 root=insert(root,arr[i]);

 return root;
}



void inorder(Node *root){
 if(root==NULL)return;

inorder(root->left);
cout<<root->data<<" ";
 inorder(root->right);
}



void preorder(Node *root){
 if(root==NULL)return;
 cout<<root->data<<" ";
 preorder(root->left);
 preorder(root->right);


}



void postorder(Node *root){
 if(root==NULL)return;

 postorder(root->left);
 postorder(root->right);
 cout<<root->data<<" ";
}



bool searchBST(Node *root,int key){
 Node *temp=root;
 if(temp==NULL)return false;

 while(temp){

 if(temp->data==key)
 return true;
if(key<=temp->data)
 temp=temp->left;
 else
 temp=temp->right;

}
}



int main(){
 cout<<"Enter N: ";
 int n;
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++)
 cin>>arr[i];

Node *root=constructBST(arr,n);
 cout<<"Enter key to find: ";
int key;
 cin>>key;
 if(searchBST(root,key))
 cout<<"key found!!"<<endl;

 else{
 cout<<("Not found!!!!...So inserting it :)");
 insert(root,key);
 }




 cout<<"Inorder traversal: "<<endl;
inorder(root);
 cout<<endl;
 cout<<"Preorder traversal: "<<endl;
 preorder(root);
 cout<<endl;
 cout<<"Postorder traversal: "<<endl;
 postorder(root);
 cout<<endl;

 return 0;
}