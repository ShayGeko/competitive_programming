
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        if(root->right) setRight(root->right, root);
        if(root->left) setRight(root->left, root);
        
        return root;
    }
    void setRight(Node* v, Node* p){
        if(v == p->left && p->right){
            v->next = p->right;
        }
        else{   
            Node* pnext = p->next;
            
            while(pnext != NULL){
                if(pnext->left){
                    v->next = pnext->left;
                    break;
                }
                else if(pnext->right){
                    v->next = pnext->right;
                    break;   
                }
                pnext = pnext->next; 
            }
            
        }
        
        if(v->right) setRight(v->right, v);
        if(v->left) setRight(v->left, v);
    }
};