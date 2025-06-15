class Solution {
public:
    int maxDiff(int num) {
        string str = to_string(num);
        string maxStr = str;
        string minStr = str;
        int n = str.size();

        // Create maxStr by replacing first non-'9' digit with '9'
        char digitToReplaceForMax = ' ';
        for (int i = 0; i < n; i++) {
            if (str[i] != '9') {
                digitToReplaceForMax = str[i];
                break;
            }
        }

        if (digitToReplaceForMax != ' ') {
            for (int i = 0; i < n; i++) {
                if (maxStr[i] == digitToReplaceForMax) {
                    maxStr[i] = '9';
                }
            }
        }

        // Create minStr with careful logic to avoid leading zero
        char digitToReplaceForMin = ' ';
        for (int i = 0; i < n; i++) {
            char ch = str[i];
            if (i == 0) {
                if (ch != '1') {
                    digitToReplaceForMin = ch;
                    for (int j = 0; j < n; j++) {
                        if (minStr[j] == digitToReplaceForMin) {
                            minStr[j] = '1';
                        }
                    }
                    break;
                }
            } else if (ch != '0' && ch != str[0]) {
                digitToReplaceForMin = ch;
                for (int j = 0; j < n; j++) {
                    if (minStr[j] == digitToReplaceForMin) {
                        minStr[j] = '0';
                    }
                }
                break;
            }
        }

        return stoi(maxStr) - stoi(minStr);
    }
};
