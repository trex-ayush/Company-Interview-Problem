class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        string maxStr = "";
        string minStr = "";
        int n = str.size();
        char digitToReplaceForMax = ' ';

        for (int i = 0; i < n; i++) {
            if (str[i] != '9') {
                digitToReplaceForMax = str[i];
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (str[i] == digitToReplaceForMax) maxStr += '9';
            else maxStr += str[i];
        }

        char digitToReplaceForMin = str[0];
        for (int i = 0; i < n; i++) {
            if (str[i] == digitToReplaceForMin) minStr += '0';
            else minStr += str[i];
        }

        return stoi(maxStr) - stoi(minStr);
    }
};
