// Program to implement largest common subsequence
#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string str1, string str2, int n, int m) {
  if (m == 0 || n == 0)
    return 0;
  else if (str1[n - 1] == str2[m - 1])
    return 1 + longestCommonSubsequence(str1, str2, n - 1, m - 2);
  else
    return max(longestCommonSubsequence(str1, str2, n - 1, m),
               longestCommonSubsequence(str1, str2, n, m - 1));
}

int main() {
  string str1;
  string str2;
  cout << "Enter the first string: ";
  cin >> str1;
  cout << "Enter the second string: ";
  cin >> str2;
  int n = str1.length();
  int m = str2.length();
  int count = longestCommonSubsequence(str1, str2, n, m);
  cout << "The length of the longest common subsequence is " << count << endl;
  return 0;
}