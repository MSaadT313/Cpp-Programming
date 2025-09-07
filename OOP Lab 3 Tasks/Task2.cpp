#include <iostream>
#include <string>

using namespace std;

class Shoes
{
private:
    string sandals;
    string joggers;
    string kidsShoes;

public:
    Shoes(const string &sandals = "", const string &joggers = "", const string &kidsShoes = "")
        : sandals(sandals), joggers(joggers), kidsShoes(kidsShoes) {}

    string getSandals()
    {
        return sandals;
    }

    string getJoggers()
    {
        return joggers;
    }

    string getKidsShoes()
    {
        return kidsShoes;
    }
    void setSandals(const string &newSandals)
    {
        sandals = newSandals;
    }

    void setJoggers(const string &newJoggers)
    {
        joggers = newJoggers;
    }

    void setKidsShoes(const string &newKidsShoes)
    {
        kidsShoes = newKidsShoes;
    }
};

int main()
{
    Shoes myShoes;

    myShoes.setSandals("Beach Sandals");
    myShoes.setJoggers("Running Joggers");
    myShoes.setKidsShoes("Playground Shoes");
    cout << "Sandals: " << myShoes.getSandals() << '\n';
    cout << "Joggers: " << myShoes.getJoggers() << '\n';
    cout << "Kids Shoes: " << myShoes.getKidsShoes() << '\n';

    return 0;
}
