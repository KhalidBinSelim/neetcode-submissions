class Solution {
public:
    string convertToTitle(int columnNumber) {
        string title;
        while (columnNumber) {
            columnNumber--;
            int offset = columnNumber % 26;
            title += ('A' + offset);
            columnNumber /= 26;
        }
        reverse(title.begin(), title.end());
        return title;
    }
};