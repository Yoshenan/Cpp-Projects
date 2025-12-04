#include <iostream>
using namespace std;

class Player {
protected:
    int shirtNumber;
    string players;

public:
    virtual int calculateOvr() = 0;
    virtual void input() = 0;
    virtual void display() = 0;

    Player(string p = "", int s = 0) {
        players = p;
        shirtNumber = s;
    }
};

class Overall : public Player {

protected:
    int pass, shot, drible, pace, physique;

public:
    int calculateOvr() override {
        return ((pass + shot + drible + pace + physique) / 5);
    }

    void input() override {
        cout << "Enter Player Name: " << endl;
        cin.ignore();
        getline(cin, players);
        cout << "Enter pass : "; cin >> pass;
        cout << "Enter shot : "; cin >> shot;
        cout << "Enter drible : "; cin >> drible;
        cout << "Enter pace  : "; cin >> pace;
        cout << "Enter physique : "; cin >> physique;
    }

    void display() override {
        int n;
        cout << "How many players do you want to enter? ";
        cin >> n;

        Overall playerList[100];

        for (int i = 0; i < n; i++) {
            playerList[i].input();
        }

        cout << "\n===== PLAYER DETAILS =====\n";
        for (int i = 0; i < n; i++) {
            cout << "\nPlayer Name: " << playerList[i].players;
            cout << "\nOverall Rating: " << playerList[i].calculateOvr() << endl;
        }
    }
};

int main() {
    Overall p;
    p.display();
    return 0;
}
