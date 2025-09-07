#include <iostream>
using namespace std;

class NADRA {
private:
    int CNIC;

public:
    NADRA() { 
        CNIC = 0;
    }

    NADRA(int cnic) {
        CNIC = cnic;
    }

    void addCNIC(int cnic) {
        CNIC = cnic;
    }

    void updateCNIC(int cnic) {
        CNIC = cnic;
    }

    void deleteCNIC() {
        CNIC = 0;
    }

    void display() {
        if (CNIC == 0)
            cout << "No CNIC assigned yet." << endl;
        else
            cout << "CNIC: " << CNIC << endl;
    }
};

int main() {
    int n;
    cout << "Enter the total number of CNIC entries: ";
    cin >> n;

    NADRA *id = new NADRA[n]; 
    int choice, index, cnic;
    while (true) {
        cout << "\nChoose an option:\n";
        cout << "1. Add a CNIC number\n";
        cout << "2. Update a CNIC number\n";
        cout << "3. Delete a CNIC number\n";
        cout << "4. Display CNICs\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0)
            break;

        switch (choice) {
            case 1:
                cout << "Enter index (0 to " << n - 1 << "): ";
                cin >> index;
                if (index >= 0 && index < n) {
                    cout << "Enter CNIC: ";
                    cin >> cnic;
                    id[index].addCNIC(cnic);
                } else {
                    cout << "Invalid index!" << endl;
                }
                break;

            case 2:
                cout << "Enter index to update (0 to " << n - 1 << "): ";
                cin >> index;
                if (index >= 0 && index < n) {
                    cout << "Enter new CNIC: ";
                    cin >> cnic;
                    id[index].updateCNIC(cnic);
                } else {
                    cout << "Invalid index!" << endl;
                }
                break;

            case 3:
                cout << "Enter index to delete (0 to " << n - 1 << "): ";
                cin >> index;
                if (index >= 0 && index < n) {
                    id[index].deleteCNIC();
                } else {
                    cout << "Invalid index!" << endl;
                }
                break;

            case 4:
                cout << "CNIC Records:\n";
                for (int i = 0; i < n; i++) {
                    cout << "Index " << i << ": ";
                    id[i].display();
                }
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    delete[] id; 
    return 0;
}
