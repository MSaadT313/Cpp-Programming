#include <iostream>
#include <string>
using namespace std;

class ghost {
protected:
    string worker;
    int scarelvl;
public:
    ghost(string w, int s) : worker(w), scarelvl(s) {}
    virtual void haunt() {
        cout << worker << " does something little scarry and spooky at level " << scarelvl << endl;
    }
    virtual ~ghost() {}
    int getscare() { return scarelvl; }

    friend ostream& operator<<(ostream &o, const ghost &g) {
        o << "ghost played by: " << g.worker << ", scare level: " << g.scarelvl;
        return o;
    }

    ghost operator+(const ghost& other) {
        return ghost(worker + " & " + other.worker, scarelvl + other.scarelvl);
    }
};

class poltergeist : public ghost {
public:
    poltergeist(string w, int s) : ghost(w, s) {}
    void haunt() override {
        cout << worker << " throws chairs and stuff at level " << scarelvl << endl;
    }
};

class banshee : public ghost {
public:
    banshee(string w, int s) : ghost(w, s) {}
    void haunt() override {
        cout << worker << " screams like crazy at level " << scarelvl << endl;
    }
};

class shadowghost : public ghost {
public:
    shadowghost(string w, int s) : ghost(w, s) {}
    void haunt() override {
        cout << worker << " whispers in shadows at level " << scarelvl << endl;
    }
};

class shadowpoltergeist : public shadowghost {
public:
    shadowpoltergeist(string w, int s) : shadowghost(w, s) {}
    void haunt() override {
        shadowghost::haunt();
        cout << worker << " also moving stuff in shadows." << endl;
    }
};

class visitor {
private:
    string vname;
    int bravery;
public:
    visitor(string n, int b) : vname(n), bravery(b) {}

    void react(int scare) {
        if (scare < bravery) {
            cout << vname << " laughs at the ghost,but is not scared." << endl;
        } else if (scare > bravery) {
            cout << vname << " screams and runs away!" << endl;
        } else {
            cout << vname << " gets slow voice and looks around." << endl;
        }
    }
};

class hauntedhouse {
private:
    string hname;
    ghost* gh[10];
    int gcount;
public:
    hauntedhouse(string n) : hname(n), gcount(0) {}
    ~hauntedhouse() {
        for (int i = 0; i < gcount; i++) delete gh[i];
    }
    void addghost(ghost* g) {
        if (gcount < 10) gh[gcount++] = g;
    }
    void simulate(visitor vs[], int vcount) {
        cout << "--- visiting " << hname << " ---" << endl;
        for (int i = 0; i < gcount; i++) {
            gh[i]->haunt();
            for (int j = 0; j < vcount; j++) {
                vs[j].react(gh[i]->getscare());
            }
        }
    }
};

void visit(visitor vs[], int vcount, hauntedhouse& h) {
    h.simulate(vs, vcount);
}

int main() {
    hauntedhouse h1("karsaz haunted house");
    hauntedhouse h2("Gulshan Block 14");

    h1.addghost(new poltergeist("Saad", 6));
    h1.addghost(new banshee("Ali", 9));

    h2.addghost(new shadowghost("Ahsan", 5));
    h2.addghost(new shadowpoltergeist("Umer", 8));

    visitor friends[3] = {
        visitor("ali", 3), 
        visitor("sara", 6), 
        visitor("omar", 9) 
    };

    visit(friends, 3, h1);
    visit(friends, 3, h2);

    return 0;
}
