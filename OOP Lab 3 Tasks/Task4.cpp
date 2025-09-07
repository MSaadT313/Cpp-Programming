#include <iostream>
#include <string>

using namespace std;

class ChatBot
{
private:
    string words[3] = {"hello", "world", "chatbot"};
    string meanings[3] = {"A greeting", "The earth, together with all of its countries, peoples, and natural features.", "A computer program designed to simulate conversation with human users."};
    int numWords = 3;

public:
    string getMeaning(const string &word)
    {
        for (int i = 0; i < numWords; ++i)
        {
            if (words[i] == word)
            {
                return meanings[i];
            }
        }
        return "Word not found.";
    }

    string correctSpelling(const string &word)
    {
        string correctedWord = word;
        int minDistance = word.length();
        for (int i = 0; i < numWords; ++i)
        {
            int distance = levenshteinDistance(word, words[i]);
            if (distance < minDistance)
            {
                minDistance = distance;
                correctedWord = words[i];
            }
        }
        return correctedWord;
    }

    int levenshteinDistance(const string &s1, const string &s2)
    {
        int m = s1.length();
        int n = s2.length();
        int dp[m + 1][n + 1];

        for (int i = 0; i <= m; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
        return dp[m][n];
    }
};

int main()
{
    ChatBot *myChatBot = new ChatBot();

    string word;

    while (true)
    {
        cout << "Enter a word (or type 'exit' to quit): ";
        cin >> word;

        if (word == "exit")
        {
            break;
        }

        string correctedWord = myChatBot->correctSpelling(word);
        string meaning = myChatBot->getMeaning(correctedWord);

        if (word != correctedWord)
        {
            cout << "Did you mean: " << correctedWord << "?\n";
        }

        cout << "Meaning: " << meaning << '\n';
    }

    delete myChatBot;
    return 0;
}
