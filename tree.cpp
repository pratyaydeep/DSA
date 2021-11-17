#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define nl '\n'

class tree{
private:
    ll val;
    tree *left, *right;
public:
    tree(ll value){
        this->val=value;
        this->left=NULL;
        this->right=NULL;
    }

    tree *insert(ll value, tree *root){
        if(root==NULL)
            return new tree(value);
        else if(value<root->val)
            root->left=insert(value,root->left);
        else
            root->right=insert(value,root->right);
        return root;
    }

    void inorder(tree* root){ //output is sorted in order
        if(root==NULL)
            return;
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }

    void preorder(tree* root){
        if(root==NULL)
            return;
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(tree* root){
        if(root==NULL)
            return;
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }
};

signed main(){
    tree *root=NULL;
    root=root->insert(10,root);
    root=root->insert(11,root);
    root=root->insert(6,root);
    root=root->insert(4,root);
    root->inorder(root);
    cout<<nl;
    root->preorder(root);
    cout<<nl;
    root->postorder(root);
    cout<<nl;


    return 0;
}