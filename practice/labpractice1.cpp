#include<iostream>
using namespace std;
class SamsungSmartAppliance{
    string modelName;
    bool powerOn = 0;
    int currentMode;
    int numberofmodes;
    public:
    SamsungSmartAppliance(string m, int x, int y): modelName(m), currentMode(x), numberofmodes(y){}
    void setModelName(const string& name) {
        modelName = name;
    }

    string getModelName() const {
        return modelName;
    }
    void setPowerOn(bool status) {
        powerOn = status;
    }

    bool getPowerOn() const {
        if(powerOn==1){
            return true;
        }
        return false;
    }
    void setCurrentMode(int mode) {
        currentMode = mode;
    }

    int getCurrentMode() const {
        return currentMode;
    }
    void setNumberOfModes(int num) {
        numberofmodes = num;
    }

    int getNumberOfModes() const {
        return numberofmodes;
    }
    void setPower(bool state){
        if(state){
            cout<<"The application is ON"<<endl;
            powerOn=1;
        }
        else{
        cout<<"the application is OFF"<<endl;
        powerOn = 0;}
    }
    bool setPowerOn() const{
        return powerOn;
    }
    void displayStatus(){
        cout<<"Model Number: "<<modelName<<endl;
        cout<<"Power State: "<<powerOn<<endl;
        if(powerOn){
            cout<<"Index of current Mode: "<<currentMode<<endl;
        }
    }
    SamsungSmartAppliance& operator++(){
        if(powerOn)
        ++currentMode;
        return *this;
    }
};
class SamsungSmartTV: public SamsungSmartAppliance{
    public:
    SamsungSmartTV(string name):SamsungSmartAppliance(name,0,5)
    {
        setModelName(name);
    }
    void displaystatus() const{
        cout<<"Smart TV"<<endl;
        cout<<getModelName()<<endl;
        cout<<"Power Status: "<<getPowerOn()<<endl;
        cout<<getCurrentMode()<<endl;
    }
};
class SamsungWashingMachine: public SamsungSmartAppliance{
    public:
    SamsungWashingMachine(string name):SamsungSmartAppliance(name,0,7){
        setModelName(name);
    }
    void displayStatus()const{
        cout<<"Washing MAchine"<<endl;
        cout<<getModelName()<<endl;
        cout<<setPowerOn()<<endl;
        cout<<getCurrentMode()<<endl;
    }
};
int main(){
    SamsungSmartAppliance machine("opera", 3,7);
    SamsungWashingMachine washingmachine("naylon");
    machine.displayStatus();
    washingmachine.displayStatus();
    washingmachine.setPower(1);
    ++machine;
    ++washingmachine;
    machine.displayStatus();
    washingmachine.displayStatus();

 
return 0;
}