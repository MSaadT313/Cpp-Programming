#include <iostream>
#include <string>
using namespace std;

#define d 256  // number of possible characters (ASCII)

// Rabin-Karp string matching
void rabinKarp(string text, string pattern, int q) {
    int n = text.length();    // length of text
    int m = pattern.length(); // length of pattern

    if (m == 0 || m > n) {
        cout << "No valid pattern to search.\n";
        return;
    }

    int p = 0;  // hash value for pattern
    int t = 0;  // hash value for current window of text
    int h = 1;

    // The value of h = pow(d, m-1) % q
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate the initial hash of pattern and first window of text
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over text
    for (int i = 0; i <= n - m; i++) {

        // If hash values match, then check characters one by one
        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Compute hash for next window of text:
        // Remove leading char, add trailing char
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            // In C++, modulus can become negative, fix it:
            if (t < 0)
                t = t + q;
        }
    }
}

int main() {
    string text = "Data structures and algorithms are fun. Algorithms make tasks easier.";
    string pattern = "Algorithms";

    int q = 101; // a prime number

    rabinKarp(text, pattern, q);

    return 0;
}