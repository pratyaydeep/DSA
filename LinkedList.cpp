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
        linked_list *sp=head,*fp=head; //slow pointer and fast pointer
        while(fp!=NULL and fp->next!=NULL){
            sp=sp->next;
            fp=fp->next->next;
        }
        return sp->data;
    }

    linked_list *delete_middle(linked_list *head){
        linked_list *sp=head,*fp=head; //slow pointer and fast pointer
        linked_list *pre=sp; //pevious of slow pointer
        while(fp!=NULL and fp->next!=NULL){
            pre=sp;
            sp=sp->next;
            fp=fp->next->next;
        }
        pre->next=sp->next;
        delete sp;
        return head;
    }

    linked_list *delete_liked_list(linked_list *head){
        linked_list *pre=head;
        while(head!=NULL){
            pre=head;
            head=head->next;
            delete pre;
        }
        return head;
    }

    void print_reverse(linked_list *head){
        if(head==NULL) return;
        else{
            print_reverse(head->next);
            cout<<head->data<<" ";
        }
    }

    linked_list *reverse_linked_list(linked_list *head){
        linked_list *cur=head, *next=head, *pre=NULL;
        while(cur!=NULL){
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }

    bool is_palindrome(auto &left, auto right){
        if(right==NULL) return true;
        bool first=is_palindrome(left, right->next);
        if(first==false) return false;
        bool second=(right->data==left->data);
        left=left->next;
        return second;
    }

    linked_list *remove_duplicates_sorted(auto head){
        auto cur=head;
        while(cur->next!=NULL){
            if(cur->data==cur->next->data){
                auto temp=cur->next;
                cur->next=temp->next;
                delete temp;
            }else{
                cur=cur->next;
            }
        }
        return head;
    }

    auto remove_duplicates_unsorted(auto head){
        set<ll> vis;
        auto cur=head,pre=cur;
        while(cur!=NULL){
            if(vis.count(cur->data)){
                pre->next=cur->next;
                delete cur;
            }
            else{
                vis.insert(cur->data);
                pre=cur;
            }
            cur=pre->next;
        }
    }
};

signed main(){
    // TODO: start from slow pointers and fast pointers

    linked_list *head=NULL;
    head=head->add(1,head);
    head=head->add(3,head);
    head=head->add(2,head);
    head=head->add(4,head);
    head=head->add(3,head);
    head=head->add(4,head);

    head->print(head);
    cout<<nl;

    // cout<<head->middle_element(head)<<nl;

    // head=head->delete_middle(head);
    // head->print(head);
    // cout<<nl;

    // head=head->delete_liked_list(head);

    // if(head==NULL) cout<<"Empty Linked List";
    // else head->print(head);

    // head->print_reverse(head);

    // head=head->reverse_linked_list(head);
    // head->print(head);

    //head=head->remove_duplicates_sorted(head);

    head->remove_duplicates_unsorted(head);
    head->print(head);

    return 0;
}