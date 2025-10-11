#include <iostream>
using namespace std;

int secret = (int)((unsigned)time(0) % 100 + 1);

void play(int player) {
    int g;
    cout << "Player " << player << ", enter your guess: ";
    cin >> g;
    if (g == secret) {
        cout << "Player " << player << " wins!" << endl;
        return;
    }
    if (g < secret) cout << "Too low!" << endl;
    else cout << "Too high!" << endl;
    play(player % 2 + 1);
}

int main() {
    play(1);
    return 0;
}
