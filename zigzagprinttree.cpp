#include <iostream>
#include<queue>
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

void levelOrderTranversal(node* root){
    queue<node*> q;
    q.push(root);
     q.push(NULL);// separator
    while(!q.empty()){
       node* temp = q.front();
       q.pop();
    
     if(temp == NULL){// this means puarana level khtam ho gya hai
         cout <<endl;
         if(!q.empty()){// q still has child nodes
            q.push(NULL);
         }
     }

     else {
         cout << temp->data <<" ";
       if(temp->left){
           q.push(temp->left);
       }

       if(temp->right){
           q.push(temp->right);
    }
}
    }
}
int main() {
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    //creating a tree
    root = buildTree(root);
   

   //levelorder:
   levelOrderTranversal(root);
return 0;
}