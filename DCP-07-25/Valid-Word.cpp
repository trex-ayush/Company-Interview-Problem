class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        if (n < 3) return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (char ch : word) {
            if (!isalnum(ch)) return false;

            if (isalpha(ch)) {
                char lowerCh = tolower(ch);
                if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }

        return hasVowel && hasConsonant;
    }
};
