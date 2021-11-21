#include "bits/stdc++.h"
using namespace std;

#define nl '\n'

class LRUCache{
public:
    class node{
    public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int key, int val){
            this->key=key;
            this->val=val;
        }
    };

    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);

    int cap;
    unordered_map<int, node*> m;

    LRUCache(int cap){
        this->cap=cap;
        head->next=tail;
        tail->prev=head;
    }

    void addnode(node* newnode){
        node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }

    void removenode(node* oldnode){
        node* pre=oldnode->prev;
        node* nex=oldnode->next;
        pre->next=nex;
        nex->prev=pre;
    }

    int get(int key){
        if(m.count(key)){
            node* resnode=m[key];
            removenode(resnode);
            addnode(resnode);
            return resnode->val;
        }
        return -1;
    }

    void put(int key, int val){
        if(m.count(key)){
            node* resnode=m[key];
            removenode(resnode);
            resnode->val=val;
            addnode(resnode);
        }else if(m.size()==cap){
            node* temp=tail->prev;
            m.erase(temp->key);
            removenode(temp);
            delete temp;
            node* newnode=new node(key, val);
            addnode(newnode);
            m[key]=newnode;
        }else{
            node* newnode=new node(key, val);
            addnode(newnode);
            m[key]=newnode;
        }
    }
};

signed main(){
    //LRUCache* cache=new LRUCache(3);
    LRUCache cache(3);
    cout<<cache.get(1)<<nl;
    cout<<cache.get(2)<<nl;
    cout<<cache.get(3)<<nl;
    cache.put(1,10);
    cache.put(2,20);
    cache.put(3,30);
    cache.put(3,40);
    cache.put(4,50);
    cout<<cache.get(1)<<nl;
    cout<<cache.get(2)<<nl;
    cout<<cache.get(3)<<nl;
    cout<<cache.get(4)<<nl;
    cout<<cache.get(1)<<nl;
    return 0;
}