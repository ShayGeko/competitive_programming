import java.util.HashMap;
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.length() == 0) return 0;

        // last locations of each previously encountered characters
        HashMap<Character, Integer> lastPosition = new HashMap<>();
        int[] maxSubstringLengthEndingAt = new int[s.length()];


        // preprocess the first character
        int maxLength = 1;
        maxSubstringLengthEndingAt[0] = 1;
        lastPosition.put(s.charAt(0), 0);

        // iterate through all characters starting from second
        for(int i = 1; i < s.length(); ++i){
            char c = s.charAt(i);
            // if the character was not found before, add it to the hashtable
            // substring continues, so current max length is previous + 1
            if(!lastPosition.containsKey(c)){
                maxSubstringLengthEndingAt[i] = maxSubstringLengthEndingAt[i - 1] + 1;
                lastPosition.put(c, i);
            }
            else{
                // character was found before, so max length at given location is either
                // 1) the distance between the duplicates
                // 2) the distance to some other character duplicate in between, if there are such
                // so its either the distance between the duplicates, or previous maxLength + 1
                int previousPos = lastPosition.get(c);
                maxSubstringLengthEndingAt[i] = Math.min(maxSubstringLengthEndingAt[i - 1] + 1, i - previousPos);
                lastPosition.replace(c, i);
            }
            if(maxSubstringLengthEndingAt[i] > maxLength) maxLength = maxSubstringLengthEndingAt[i];
        }

        return maxLength;
    }
}