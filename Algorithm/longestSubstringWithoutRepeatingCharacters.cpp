#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring_1(string s);
int lengthOfLongestSubstring_beta(string s);

int main(int argc, char *argv[]) {
    int substr_long_len = 0;
    string input_str("abcabcbb");
    substr_long_len = lengthOfLongestSubstring_1(input_str);
    cout << "max substr len: " << substr_long_len << endl;
    cout << "----------" << endl;
    input_str = "bbabcdb";
    substr_long_len = lengthOfLongestSubstring_1(input_str);
    cout << "max substr len: " << substr_long_len << endl;
    cout << "----------" << endl;
    input_str = "";
    substr_long_len = lengthOfLongestSubstring_beta(input_str);
    cout << "max substr len: " << substr_long_len << endl;
    cout << "----------" << endl;
    return 0;
}

/* optimizing */
/* specify case: "", " ", "ab" */
int lengthOfLongestSubstring_beta(string s) {
    /* init array that store each char's index */
    int m[256];
    memset(m, -1, sizeof(m));
    /* default length is zero */
    int len = 0;
    /* start index */
    int base = 0;
    for (int i=0; i<s.size(); ++i) {
        /* if the char found */
        if (m[s[i]] != -1) {
            /* update base value for a new substr */
            base = max(m[s[i]], base);
        }
        /* store char's index+1 */
        m[s[i]] = i + 1;
        /* i - base + 1 is calc current length */
        len = max(len, i - base + 1);
    }
    return len;
}

/* my first solution */
int lengthOfLongestSubstring_1(string s) {
    /* for store length, base */
    unordered_map<int, int> result_map;
    string tmp_str;
    /* store orgin str */
    string origin_str = s;
    int base = 0;
    /* store substr length */
    int str_len = 0;
    for (int i = 0; i < s.size(); ++i) {
        /* find repeat char in tmp_str */
        int pos = tmp_str.find(s[i]);
        /* if found */
        if (pos >= 0) {
            /* store length, base */
            result_map.insert({i, base});
            /* for the last substring */
            if (i > str_len) {
                str_len = i;
            }
            /* new base */
            base = base + pos + 1;
            /* set the s to new substr */
            s = origin_str.substr(base);
            /* clear the tmp_str that can be store the next substr */
            tmp_str.clear();
            /* rest the index, becase the next instruction is ++i */
            i = -1;
        } else {
            /* store the char that not found in tmp_str */
            tmp_str.push_back(s[i]);
        }
    }
    /* if the s is only one char */
    if (tmp_str.size() > str_len) {
        str_len = tmp_str.size();
    }
    cout << "max substr: " << origin_str.substr(result_map[str_len], str_len) << endl;
    return str_len;
}
