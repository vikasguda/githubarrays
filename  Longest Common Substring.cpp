#include <iostream>
#include <vector>

std::string longestCommonSubstring(const std::string& str1, const std::string& str2) {
    int m = str1.length();
    int n = str2.length();

    // Initialize a 2D table to store lengths of common suffixes
    std::vector<std::vector<int>> table(m + 1, std::vector<int>(n + 1, 0));

    // Variables to store the length of the longest common substring and its ending index
    int max_length = 0;
    int end_index = 0;

    // Fill the table using dynamic programming
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
                if (table[i][j] > max_length) {
                    max_length = table[i][j];
                    end_index = i - 1;
                }
            } else {
                table[i][j] = 0;
            }
        }
    }

    // Extract the longest common substring
    return str1.substr(end_index - max_length + 1, max_length);
}

int main() {
    std::string str1 = "ABABC";
    std::string str2 = "BABCA";

    std::string result = longestCommonSubstring(str1, str2);

    std::cout << "String 1: " << str1 << std::endl;
    std::cout << "String 2: " << str2 << std::endl;
    std::cout << "Longest Common Substring: " << result << std::endl;

    return 0;
}
