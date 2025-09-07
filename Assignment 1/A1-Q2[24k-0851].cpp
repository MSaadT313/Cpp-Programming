#include <iostream>
#include <string>
#include <tuple>
using namespace std;

class Ball {
private:
    int x, y;

public:
    Ball() {
        x = 0;
        y = 0;
    }

    void resetBall() {
        x = 0;
        y = 0;
    }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    int getX() { return x; }
    int getY() { return y; }

    tuple<int, int> getPosition() {
        return make_tuple(x, y);
    }
};

class Robot {
private:
    string name;
    int hits;

public:
    Robot(string n) {
        name = n;
        hits = 0;
    }

    void hitBall(Ball &ball, const string &direction) {
        if (direction == "up") {
            ball.move(0, 1);
        } else if (direction == "down") {
            ball.move(0, -1);
        } else if (direction == "right") {
            ball.move(1, 0);
        } else if (direction == "left") {
            ball.move(-1, 0);
        }
        hits++;
    }

    int getHits() { return hits; }
};

class Goal {
private:
    int x, y;

public:
    Goal() {
        x = 3;
        y = 3;
    }

    bool isGoalReached(int ballX, int ballY) {
        return (ballX == x && ballY == y);
    }
};

class Team {
private:
    string teamName;
    Robot *robot;

public:
    Team(string name, Robot *r) {
        teamName = name;
        robot = r;
    }

    string getTeamName() { return teamName; }
    Robot *getRobot() { return robot; }
};

class Game {
private:
    Team *teamOne;
    Team *teamTwo;
    Ball ball;
    Goal goal;

public:
    Game(Team *t1, Team *t2) : teamOne(t1), teamTwo(t2) {}

    void startGame() {
        cout << "Football Game Simulation Starts!" << endl;
        play(teamOne);
        play(teamTwo);
        declareWinner();
    }

    void play(Team *team) {
        string direction;
        ball.resetBall();
        Robot *robot = team->getRobot();
        cout << team->getTeamName() << "'s Turn!" << endl;

        while (!goal.isGoalReached(ball.getX(), ball.getY())) {
            cout << "Enter direction (up, down, left, right): ";
            cin >> direction;
            robot->hitBall(ball, direction);
            cout << "Ball is now at (" << ball.getX() << ", " << ball.getY() << ")" << endl;
        }

        cout << team->getTeamName() << " scored a goal in " << robot->getHits() << " hits!" << endl;
    }

    void declareWinner() {
        int hitsTeamOne = teamOne->getRobot()->getHits();
        int hitsTeamTwo = teamTwo->getRobot()->getHits();

        cout << teamOne->getTeamName() << " made " << hitsTeamOne << " hits." << endl;
        cout << teamTwo->getTeamName() << " made " << hitsTeamTwo << " hits." << endl;

        if (hitsTeamOne < hitsTeamTwo) {
            cout << teamOne->getTeamName() << " wins!" << endl;
        } else if (hitsTeamTwo < hitsTeamOne) {
            cout << teamTwo->getTeamName() << " wins!" << endl;
        } else {
            cout << "It's a tie!" << endl;
        }
    }
};

int main() {
    Robot robot1("Robot 1");
    Robot robot2("Robot 2");

    Team teamOne("Team Alpha", &robot1);
    Team teamTwo("Team Beta", &robot2);

    Game game(&teamOne, &teamTwo);
    game.startGame();

    return 0;
}