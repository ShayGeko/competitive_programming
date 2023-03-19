#include "testlib.h"
using namespace std;

const int max_testcount = 30000;
const int max_n = 30000;
const int max_val = 1'000'000;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);

    stringstream ss;
    
    char next_c;

    while(true){
        ss << inf.readLine();
        next_c = inf.readChar();
        if(next_c != EOF) inf.unreadChar(next_c);
        else {
            inf.unreadChar(next_c);
            break;
        }
    }

    string s;
    s = ss.str();

    int cnt = 0;
    for(auto c : s){
        if(isalpha(c)) ++cnt;
    }

    ensure(s.length() <= 10000);
    ensure(cnt <= 5000);

    inf.readEof();
    return 0;
}