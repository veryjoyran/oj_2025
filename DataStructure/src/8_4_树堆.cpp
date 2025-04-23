#include<bits/stdc++.h>

using namespace std;

struct Node{
    int key;
    int priority;
    Node *left;
    Node *right;
    Node(int k,int p):key(k),priority(p),left(nullptr),right(nullptr){}
};

Node* root=nullptr;

Node* rightRotate(Node* t)
{
    Node* s=t->left;
    t->left=s->right;
    s->right=t;

    return s;
}

Node* leftRotate(Node* t)
{
    Node* s=t->right;
    t->right=s->left;
    s->left=t;
    return s;
}

Node* Insert(Node* t,int key,int priority)
{
    if(t==nullptr)
    {
        Node* newNode=new Node(key,priority);
        return newNode;
    }

    if(key==t->key) return t;

    if(key<t->key)
    {
        t->left=Insert(t->left,key,priority);
        if(t->priority<t->left->priority)
            t=rightRotate(t);
    }
    else
    {
        t->right=Insert(t->right,key,priority);
        if(t->priority<t->right->priority)
            t=leftRotate(t);
    }
    return t;

}

Node* _Delete(Node*,int);

Node* Delete(Node* t,int key)
{
    if(t==nullptr) return nullptr;
    if(key<t->key) t->left=Delete(t->left,key);
    else if(key>t->key) t->right=Delete(t->right,key);
    else
        return _Delete(t,key);
    return t;
}

Node* _Delete(Node* t,int key)
{
    if(t->left==nullptr&&t->right==nullptr) return nullptr;

    else if(t->left==nullptr) t=leftRotate(t);
    else if(t->right==nullptr) t=rightRotate(t);

    else
    {
        if(t->left->priority>t->right->priority) t=rightRotate(t);
        else t=leftRotate(t);
    }

    return Delete(t,key);
}

bool Find(int key)
{
    Node* current=root;
    while(current!=nullptr)
    {
        if(key==current->key) return true;
        else if(key<current->key) current=current->left;
        else current=current->right;
    }
    return false;
}


Node* Search(int key)
{
    Node* current=root;
    while(current!=nullptr)
    {
        if(key==current->key) return current;
        else if(key<current->key) current=current->left;
        else current=current->right;
    }
    return nullptr;
}


void Preorder(Node* u)
{
    if(u==nullptr) return;

    cout<<u->key<<" ";
    Preorder(u->left);
    Preorder(u->right);

}

void Inorder(Node *u)
{
    if(u==nullptr) return;

    Inorder(u->left);
    cout<<u->key<<" ";
    Inorder(u->right);
}




int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string op;
        cin>>op;
        if(op=="insert")
        {
            int key;
            int priority;
            cin>>key>>priority;
            root=Insert(root,key,priority);
        }
        else if(op=="find")
        {
            int key;
            cin>>key;
            cout<<((Find(key))?"yes":"no")<<endl;

        }
        else if(op=="delete")
        {
            int key;
            cin>>key;
            root=Delete(root,key);
        }
        else
        {
            Inorder(root);
            cout<<endl;
            Preorder(root);
            cout<<endl;
        }
    }



    return 0;
}



