#include<iostream>
using namespace std;
class node{
 public:
  int data;
  node* left;
  node* right;

  node(int d){  // constructor
      this -> data = d;
      this -> left = NULL;
      this -> right = NULL;
  }
};
node* buildTree(node* root){
    cout <<"enter the data:"<<endl;
    int data ;
    cin >> data;
    root = new node(data);//constructor called

    if(data == -1){
        return NULL;
    }

    //left side:
    cout <<"enter the data for left side of "<<data<<endl;
    root->left = buildTree(root->left);

    //right side:
    cout <<"enter the data for right side of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}
int main() {
    node* root = NULL;
    //creating a tree
    root = buildTree(root);

return 0;
}