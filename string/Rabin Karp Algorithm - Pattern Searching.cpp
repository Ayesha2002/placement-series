class Solution {
  public:
    void searchPattern(string & text, string & pattern) {

      int n = text.length();
      int m = pattern.length();

      int j;
      for (int i = 0; i <= n - m; i++) {

        for (j = 0; j < m; ++j) {
          if (pattern[j] != text[i + j]) {
            break;
          }
        }

        if (j == m) {
          cout << "index = " << i << "\n";
        }
      }
    }
};
