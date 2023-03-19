class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string transformations[] = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };
        
        unordered_set<string> unique_transform;
        
        for(string word: words){
            string tr = "";
            for(auto c : word){
                tr += transformations[c-'a'];
            }
            unique_transform.insert(tr);
        }
        
        return unique_transform.size();
    }
};