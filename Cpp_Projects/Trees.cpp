#include <iostream>
#include <queue>
using namespace std;


struct node{
    int val;
    node* left;
    node* right;
};

node* createNode(int x){
    node* new_node = new node;
    new_node->val = x;
    new_node->left = new_node->right = NULL;
    return new_node;
}


void insert(node* &root, int x){ 
    if(!root){
        root = createNode(x);
        return;
    }
    queue<node*> que;
    que.push(root);
    while(!que.empty()){
        if(!que.front()->left){
            que.front()->left = createNode(x);
            return;
        }if(!que.front()->right){
            que.front()->right = createNode(x);
            return;
        }
        que.push(que.front()->left);
        que.push(que.front()->right);
        que.pop();
    }
}

int treeSize(node* root){
    queue<node*> q;
    q.push(root);
    int size = 0;
    while(!q.empty()){
        if(q.front()->left)
            q.push(q.front()->left);
        if(q.front()->right)
            q.push(q.front()->right);
        q.pop();
        size++;
    }
    return size;
}


node* test(node* root){
    if(!root->left)
        return root;
    return test(root->left);
}


bool exist(node* root, int x){
    if(!root)
        return false;
    if(root->val == x)
        return true;
    return (exist(root->left, x) || exist(root->right, x)); 
}


node* parent(node* root, node* n){
    if(!root)
        return NULL;
    if(root->left == n)
        return root;
    if(root->right == n)
        return root;
    if(parent(root->left, n))
        return parent(root->left, n);
    return parent(root->right, n);
}


int leaves(node* root){
    if(!root)
        return 1;
    return leaves(root->left) + leaves(root->right);
}

int main(){
    node* root = NULL;
    insert(root, 4); insert(root, 7); insert(root, 9); insert(root, 2); insert(root, 11); insert(root, 18); 
    cout << leaves(root);


}