#include <bits/stdc++.h>

using namespace std;


int fib(int n) { // 2^40 ~ 1e12
    if(n <= 0) return 0;
    if(n == 1) return 1;

    // a_i = a_i-1 + a_i-2
    return fib(n-1) + fib(n-2);
}

// list of numbers: 1 2 3 4 5
// recursive function to print in reverse


// no for or while loops
// no extra variables or arrays

//

struct node {
    int val;
    node* nxt = NULL;
}; 

// (a, ) -> (b, ) -> (c, ) -> nullptr
// a ( b ( c ( null )))
void rev_print(node* list) {
    if(list == nullptr) return;
    
    cout << "we are in " << list->val << '\n';
    rev_print(list->nxt);
    
    
    cout << "and back to " << list->val << '\n';

    // return cout << rev_print()
}

/*

                fib(6)
        fib(4)                              fib(5)
    fib(2)  fib(3)    
fib(0) fib(1) fib(1) fib(2)
                    fib(0) fib(1)

                    n 2^n

        1
    2      3
4   5    6   7
*/

int main(){

    node* c = new node(); 
    c->val = 0; c->nxt = NULL;

    node* b = new node(); 
    b->val = 1; b->nxt = c;

    node* a = new node(); 
    a->val = 2; a->nxt = b;

    rev_print(a);



    return 0;
}