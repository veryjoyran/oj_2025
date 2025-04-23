#include<bits/stdc++.h>

using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    Node *parent;

    Node(int k):key(k),left(nullptr),right(nullptr),parent(nullptr){}
};

Node* root=nullptr;

void Insert(int key)
{
    Node *newNode=new Node(key);
    if(root==nullptr)
    {
        root=newNode;
        return;
    }

    Node* current =root;
    Node* parent=nullptr;

    while(current!=nullptr)
    {
        parent=current;
        if(key<current->key) current=current->left;
        else current=current->right;

    }

    newNode->parent=parent;
    if(key<parent->key) parent->left=newNode;
    else parent->right=newNode;
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

void Delete(int key)
{
    Node* z=Search(key);
    if(z==nullptr) return;
    if(z->left&&z->right)
    {
        Node* y=z->right;
        while(y->left!=nullptr)
        {
            y=y->left;
        }

        z->key=y->key;
        if(y->right==nullptr)
        {
            Node* p=y->parent;
            if(p->left==y) p->left=nullptr;
            else p->right=nullptr;
            delete y;
        }
        else
        {
            Node* child=y->right;
            Node* p=y->parent;
            if(p->left==y) p->left=child;
            else p->right=child;

            child->parent=p;

            delete y;

        }
    }
    else
    {
        Node* child=(z->left!=nullptr)?z->left:z->right;

        Node* p=z->parent;

        if(p!=nullptr)
        {
            if(p->left==z) p->left=child;
            else p->right=child;
            if(child!=nullptr) child->parent=p;
        }
        else
        {
            root =child;
            if(child!=nullptr)
            {
                child->parent=nullptr;
            }
        }
        delete z;
    }
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
            cin>>key;
            Insert(key);
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
            Delete(key);
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