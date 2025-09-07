#include<iostream>
using namespace std;
class Vehicle{
    protected:
    string modelid;
    public:
    virtual void assembleVehicle(){
        cout<<"assembly intitialization starts. "<<endl;
    }
};
class QualityCOntrolSystem{
    void inspectCar(Car *car1){
        cout<<car1->modelid<<endl;
        cout<<car1->enginePower<<endl;
    }
    void inspectMotorcycle(Motorcycle *motor1){
        cout<<motor1->modelid<<endl;
        cout<<motor1->torque<<endl;
    }
};
class Car: public Vehicle{
    float enginePower;
    public:
    float getenginepower(){
        return enginePower;

    }
    void assembleVehicle() override{
        cout<<"Engine Power: "<<enginePower<<endl;
    }
    friend QualityCOntrolSystem;
    friend void CalibrateEngine(Car &c, float newpower);
};
class Motorcycle: public Vehicle{
    float torque;
    public:
    void assembleVehicle() override{
        cout<<"Torque: "<<torque<<endl;
    }
    float gettorque(){
        return torque;
    }
    friend QualityCOntrolSystem;
    friend void CalibrateMotorcycle(Motorcycle &m, float torq)
};
class HybridVehicle:public Car, public Motorcycle{
    public:
    void assembleVehicle()override{
        float sum;
        sum= gettorque()+getenginepower();
        cout<<"Total Engine Power: "<<sum<<endl;
    }
};

void CalibrateEngine(Car &c,float newpower){
    c.enginePower = newpower;
    cout<<"Power updated to: "<<c.enginePower<<endl;
}
void CalibrateMotorcycle(Motorcycle &m, float torq){
    m.torque = torq;
    cout<<"Torque updated to: "<<endl;
}
int main(){
    Car mycar("c001", 103.2);
    
 
return 0;
}