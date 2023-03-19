#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;

map<string, set<int>> symbol_table;

enum node_type {
    ASSIGNMENT,
    CONDITIONAL,
    ASSERTION,
    BLOCK,
    MAIN
};

bool isDigit(char c){
    return c >= '0' && c <= '9';
}
class Node {
public:
    bool firstIsVar = true, secondIsVar = true;
    int left, right;
    char var_left, var_right;
    bool questionMark = false;
    bool assertionsHold = true;
    vector<Node*> children;
    node_type type;
};
Node* parse_assignment(stringstream &buffer);
Node* parse_assertion(stringstream &buffer);

Node* parse_block(stringstream &buffer){
    Node* node = new Node();
    node->type = BLOCK;
    char next_char;
    next_char = buffer.peek();
    while(next_char != '}') {
        buffer >> next_char;
        if (next_char == '[') node->children.push_back(parse_assignment(buffer));
        else if(next_char == '<') node->children.push_back(parse_assertion(buffer));
    }
}
Node* parse_assignment(stringstream &buffer){
    Node* node = new Node();
    node->type = ASSIGNMENT;
    char var1, assignSymbol;
    buffer >> node->var_left >> assignSymbol;

    char next_symbol = buffer.peek();
    int value;

    if(isDigit(next_symbol)) {
        buffer >> value;
        node->secondIsVar = false;
    }
    else if(next_symbol == '?'){
        buffer >> next_symbol;
        node -> secondIsVar = false;
    }
    else{
        buffer >>  node->var_right;
    }
    return node;
}
Node* parse_conditional(stringstream &buffer){
    Node* node = new Node();
    node->type = CONDITIONAL;

    char next_char;
    next_char = buffer.peek();
    if(isDigit(next_char)){
        int value;
        buffer >> value;
        node->firstIsVar = false;
        node->left = value;
    }
    else{
        buffer >> node->var_left;
    }

    buffer >> next_char; // comparison sign is always <

    next_char = buffer.peek();
    if(isDigit(next_char)){
        int value;
        buffer >> value;
        node->secondIsVar = false;
        node->right = value;
    }
    else{
        buffer >> node->var_right;
    }

    node->children.push_back(parse_block(buffer));

    buffer >> next_char; // )
    return node;
}
Node* parse_assertion(stringstream &buffer){
    Node* node = new Node();
    node->type = ASSERTION;
    char next_char;
    char var1, var2;
    buffer >> node->var_left >> next_char >> node->var_right;

    return node;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    string str;
    while(t--){

        Node* main = new Node();
        main->type = MAIN;
        getline(cin, str);
        stringstream buffer;
        buffer << str;
        char c;
        while(buffer){
            if(c == '['){
                main->children.push_back(parse_assignment(buffer));
            }
            else if(c == '('){
                main->children.push_back(parse_conditional(buffer));
            }
            else {
                main->children.push_back(parse_assertion(buffer));
            }
        }
    }
    return 0;
}