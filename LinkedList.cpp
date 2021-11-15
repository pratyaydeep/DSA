#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

class linked_list{
public:
    ll data;
    linked_list *next;
    linked_list(){
        this->next=NULL;
    }
    linked_list(ll data){
        this->data=data;
        this->next=NULL;
    }
    linked_list *add(ll data, linked_list *head){
        if(head==NULL){
            linked_list *temp=new linked_list(data);
            head=temp;
        }else{
            linked_list *temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=new linked_list(data);
        }
        return head; 
    }

    void print(linked_list *head){
        linked_list *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

    ll middle_element(linked_list *head){
        linked_list *sp=head,*fp=head;
        while(fp!=NULL and fp->next!=NULL){
            sp=sp->next;
            fp=fp->next->next;
        }
        return sp->data;
    }
};

signed main(){
    // TODO: start from slow pointers and fast pointers

    linked_list *head=NULL;
    head=head->add(1,head);
    head=head->add(2,head);
    head=head->add(3,head);
    head=head->add(4,head);
    head=head->add(5,head);
    head=head->add(6,head);

    head->print(head);
    cout<<nl;

    cout<<head->middle_element(head)<<nl;

    return 0;
}