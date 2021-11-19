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

    void print_bottom_view(tree* root){
        map<int,int> mp;
        queue<pair<tree*, int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int hd=temp.second;
            auto node=temp.first;
            mp[hd]=node->val;
            if(node->left)
                q.push({node->left,hd-1});
            if(node->right)
                q.push({node->right,hd+1});
        }
        for(auto i:mp)
            cout<<i.second<<" ";
    }

    int get_tree_height(tree* root){
        if(root==NULL) return 0;
        int l=get_tree_height(root->left);
        int r=get_tree_height(root->right);
        return 1+max(l,r);
    }

    tree* array_to_bst(ll *a, ll st, ll end){
        if(st>end) return NULL;
    
        ll middle=(st+end)>>1;
        tree* root=new tree(a[middle]);
        root->left=array_to_bst(a, st, middle-1);
        root->right=array_to_bst(a, middle+1, end);
        return root;
    }

    tree* create_tree_preorder_inorder(int &pre_idx, int st, int end, int* pre, auto &mp){
        if(st>end) return NULL;

        tree *root=new tree(pre[pre_idx]);
        int idx=mp[pre[pre_idx]];
        pre_idx++;
        root->left=create_tree_preorder_inorder(pre_idx,st,idx-1,pre,mp);
        root->right=create_tree_preorder_inorder(pre_idx,idx+1,end,pre,mp);

        return root;
    }

    bool is_identical(tree *root1, tree *root2){
        if(root1==NULL and root2==NULL)
            return true;
        if(root1==NULL or root2==NULL)
            return false;
        if(root1->val!=root2->val)
            return false;
        return is_identical(root1->left, root2->left) and is_identical(root1->right,root2->right);
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

    // root=root->insert(7,root);
    // root=root->insert(2,root);
    // root=root->insert(8,root);
    // root=root->insert(1,root);
    // root=root->insert(5,root);
    // root->print_top_view(root);
    // cout<<nl;
    // root->print_bottom_view(root);
    // cout<<nl;
    // cout<<root->max_depth(root);

    // ll a[]={1,2,3,4,5};
    // //tree* root=NULL;
    // root=root->array_to_bst(a, 0, 4);
    // root->inorder(root);
    // cout<<nl;
    // root->preorder(root);
    
    // int in[]={3,1,4,0,5,2};
    // int pre[]={0,1,3,4,2,5};
    // unordered_map<int,int> mp;
    // for(int i=0;i<6;i++)
    //     mp[in[i]]=i;
    // int pre_idx=0;
    // root=root->create_tree_preorder_inorder(pre_idx,0,5,pre,mp);
    // root->inorder(root);
    // cout<<nl;
    // root->preorder(root);
    // cout<<nl;
    // root->postorder(root);

    tree *root1=NULL, *root2=NULL;
    root1=root->insert(7,root1);
    root1=root->insert(2,root1);
    root1=root->insert(8,root1);
    root1=root->insert(1,root1);
    root1=root->insert(5,root1);

    root2=root2->insert(7,root2);
    root2=root2->insert(2,root2);
    root2=root2->insert(8,root2);
    root2=root2->insert(1,root2);
    root2=root2->insert(4,root2);

    cout<<root1->is_identical(root1,root2);
    return 0;
}