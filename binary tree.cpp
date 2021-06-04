#include <iostream>
#include <stack>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
// Inorder Recusrsive // O(n)-time  O(h)- space
void inorder(Node* root)
{
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
// in=terative
void inorderIt(Node *root){
	stack<Node*> st;
	Node* cur=root;
	while(!st.empty()||cur){
		
		if(cur){
			st.push(cur);
			cur=cur->left;
		}else{
			Node* temp=st.top();
			st.pop();
			cout<<temp->data<<" ";
			cur=temp->right;
		}
	}
}



// Preorder 
void preorder(Node* root)
{
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void preorderIt(Node* root){
	stack<Node*> st;
	Node* cur=root;
	st.push(cur);
	while(!st.empty()){
		Node *temp=st.top();
		st.pop();
		cout<<temp->data<<" ";
		if(temp->right){
			st.push(temp->right);
		}
		if(temp->left){
			st.push(temp->left);
		}
	}
}

// PostOrder
void postorder(Node* root)
{
    if (root == NULL) {
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void postorderIt(Node* root){
	stack<Node*> s;
    s.push(root);
    stack<int> out;
    while (!s.empty())
    {
        Node* curr = s.top();
        s.pop();
 
        out.push(curr->data);
        if (curr->left) {
            s.push(curr->left);
        }
 
        if (curr->right) {
            s.push(curr->right);
        }
    }
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
}
int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    postorderIt(root);
 
    return 0;
}