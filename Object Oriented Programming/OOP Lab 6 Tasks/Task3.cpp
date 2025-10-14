#include <iostream>
#include <string>
using namespace std;

class Words {
protected:
    string input;
public:
    void getInput() {
        cout << "Enter a word: ";
        cin >> input;
    }
    string getWord() const {
        return input;
    }
};

class Palindrome : public Words {
public:
    bool isPalindrome() {
        string reversed = "";
        for (int i = input.length() - 1; i >= 0; i--) {
            reversed += input[i];
        }
        return input == reversed;
    }

    void displayResult() {
        if (isPalindrome()) {
            cout << input << " is a palindrome." << endl;
        } else {
            cout << input << " is not a palindrome." << endl;
        }
    }
};

int main() {
    Palindrome p;
    p.getInput();
    p.displayResult();
    return 0;
}
