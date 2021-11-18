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

    void level_order_traversal(tree* root){
        queue<tree*> q;
        q.push(root);
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            cout<<temp->val<<" ";
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
    }

    void left_view(tree* root){
        queue<tree*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=1;i<=sz;i++){
                auto temp=q.front();
                q.pop();
                if(i==1)
                    cout<<temp->val<<" ";
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
    }

    void right_view(tree* root){
        queue<tree*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            for(int i=1;i<=sz;i++){
                auto temp=q.front();
                q.pop();
                if(i==sz)
                    cout<<temp->val<<" ";
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
    }

    void print_top_view(tree* root){
        map<int,int> mp;
        queue<pair<tree*, int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int hd=temp.second;
            auto node=temp.first;
            if(mp.count(hd)==0)
                mp[hd]=node->val;
            if(node->left)
                q.push({node->left,hd-1});
            if(node->right)
                q.push({node->right,hd+1});
        }
        for(auto i:mp)
            cout<<i.second<<" ";
    }
};

signed main(){
    tree *root=NULL;
    // root=root->insert(10,root);
    // root=root->insert(11,root);
    // root=root->insert(6,root);
    // root=root->insert(4,root);
    // root->inorder(root);
    // cout<<nl;
    // root->preorder(root);
    // cout<<nl;
    // root->postorder(root);
    // cout<<nl;

    // root=root->insert(7,root);
    // root=root->insert(5,root);
    // root=root->insert(8,root);
    // root=root->insert(4,root);
    // root=root->insert(6,root);
    // root=root->insert(9,root);
    
    //root->level_order_traversal(root);

    //root->left_view(root);
    // root->right_view(root);

    root=root->insert(7,root);
    root=root->insert(2,root);
    root=root->insert(8,root);
    root=root->insert(1,root);
    root=root->insert(5,root);
    root->print_top_view(root);

    return 0;
}