

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

struct Person {
    int _milk;
    int _time;
};

int _res = INT32_MIN;
int _people = 0;
int _milkTypes = 0;
int _maxD = 0;
int _maxS = 0;
map<int, vector<Person>> _personMap;
map<int, int> _badMap;

void ParseIn () {
    int curPerson = 0;
    int curTime = 0;
    Person solo;

    ifstream inFile ("badmilk.in");

    inFile >> _people >> _milkTypes >> _maxD >> _maxS;

    for (int i = 0; i < _maxD; i++) {
        inFile >> curPerson >> solo._milk >> solo._time;

        _personMap[curPerson].push_back(solo);
    }

    for (int i = 0; i < _maxS; i++) {
        inFile >> curPerson >> curTime;

        _badMap[curPerson] = curTime;
    }

    inFile.close();

}

//what: true-> seen, false-> not seen
bool Seen (int typeMilk, vector<int> seen) {
    for (int i = 0; i < seen.size(); i++) {
        if (seen[i] == typeMilk) {return true;}
    }

    return false;
}

void Core () {
    map<int, int> eliminateMap;
    map<int, int> possibleMap;
    map<int, vector<int>> seenMap;
    vector<int> toErase;

    for (int i = 1; i < _people+1; i++) {
        if (_badMap.count(i) == 0) {continue;}

        for (int m = 0; m < _personMap[i].size(); m++) {
            if (_personMap[i][m]._time < _badMap[i] && !Seen(_personMap[i][m]._milk, seenMap[i])) { //drank milk before sick
                seenMap[i].push_back(_personMap[i][m]._milk);
                possibleMap[_personMap[i][m]._milk]++;
            }

            // if (_personMap[i][m]._time > _badMap[i]) { //drank milk after sick.. not needed?
            //     eliminateMap[_personMap[i][m]._milk]++;
            // }
        }
    }

    for (auto i : possibleMap) {
        cout << i.first << "->" << i.second << endl;

        if (i.second < _maxS) {
            toErase.push_back(i.first);
        }
    }

    for (int i = 0; i < toErase.size(); i++) {
        possibleMap.erase(toErase[i]);
    }

    for (int i = 1; i < _people+1; i++) {
        if (_badMap.count(i) != 0) {continue;}

        for (int m = 0; m < _personMap[i].size(); m++) {
            if(possibleMap.count(_personMap[i][m]._milk) != 0 && !Seen(_personMap[i][m]._milk, seenMap[i])) {
                seenMap[i].push_back(_personMap[i][m]._milk);
                possibleMap[_personMap[i][m]._milk]++;
            }
        }
    }

    for (auto i : possibleMap) {
        _res = max(_res, i.second);
    }
}

void WriteOut () {
    ofstream outFile ("badmilk.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    WriteOut ();

    return 0;
}