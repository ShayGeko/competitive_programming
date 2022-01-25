#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;
const int P = 1e9 + 7;
//vector<string> words = {"a", "bb\0x1b", "ab", "b"};
int main(){
    //ios_base::sync_with_stdio(false); cin.tie(NULL);

    unordered_map<string,int> hashmap;

    vector<string> words;


    string word;

    while(getline(cin,word)){

        string temp = "";
        for(int i=0;i<word.length();++i){

            if(word[i]==' '){

                words.push_back(temp);
                temp = "";
            }
            else{
                temp.push_back(word[i]);
            }

        }
        words.push_back(temp);

    }




    for(int i = 0; i < words.size(); i++) {

        string first = words[i];

        cout << "Before:  " << first << "\n";

        cout << "After : " << "|" << first << "|" << "\n";



//        for(int j = 0; j < words.size(); j++){
//
//            string second = words[j];
//
//            string temp = "";
//
//            temp.append(first);
//            temp.append(second);
//
//            cout << "temp = " << temp << endl;
//
//        }

    }


//
//    for (auto& set: hashmap) {
//        cout << (set.first) << endl;
//
//    }





    return 0;
}