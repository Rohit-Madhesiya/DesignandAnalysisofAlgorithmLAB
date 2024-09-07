#include <iostream>
#include <string>
using namespace std;

void naiveStringMatch(string txt, string pat) {
    int M = pat.length();
    int N = txt.length();

    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
        if (j == M)
            cout << "Pattern found at index " << i << endl;
    }
}

int main() {
    string txt = "AABAACAADAABAAABAA";
    string pat = "AABA";
    naiveStringMatch(txt, pat);
    return 0;
}