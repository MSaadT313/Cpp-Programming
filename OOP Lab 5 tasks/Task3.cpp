#include <iostream>
using namespace std;

class BloodSample {
private:
    string bloodType;
    int sampleID;

public:
    BloodSample(string type = "", int id = 0) {
        bloodType = type;
        sampleID = id;
    }

    void display() {
        cout << "Sample ID: " << sampleID << ", Blood Type: " << bloodType << endl;
    }
};

class BB_Laboratory {
private:
    BloodSample samples[5];
    int count;

public:
    BB_Laboratory() {
        samples[0] = BloodSample("A+", 101);
        samples[1] = BloodSample("B+", 102);
        samples[2] = BloodSample("O-", 103);
        samples[3] = BloodSample("AB+", 104);
        samples[4] = BloodSample("A-", 105);
        count = 5;
    }

    void displaySamples() {
        cout << "Blood Bank Laboratory Samples:\n";
        for (int i = 0; i < count; i++) {
            samples[i].display();
        }
    }
};

int main() {
    BB_Laboratory lab;
    lab.displaySamples();
    return 0;
}
