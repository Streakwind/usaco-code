

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Routes {
    int _price;
    int _ccRoute;
    vector<int> _myList;
};

int _cityA = 0;
int _cityB = 0;
int _res = 0;
vector<Routes> _routeList;
vector<Routes> _resList;
//Time complexity: O[N*M]^2 or something

void DisplayList () {
    cout << "In DisplayList" << endl;

    for (int i = 0; i < _routeList.size(); i++) {
        cout << "Price -> " << _routeList[i]._price << " Routes -> " << _routeList[i]._ccRoute << endl;

        for (int m = 0; m < _routeList[i]._myList.size(); m++) {
            cout << _routeList[i]._myList[m] << ", ";
        }

        cout << endl;
    }
}

void ParseIn () {
    int maxi = 0;
    int myInt = 0;
    Routes solo;

    ifstream inFile ("cowroute.in");

    inFile >> _cityA >> _cityB >> maxi;

    for (int i = 0; i < maxi; i++) {
        inFile >> solo._price >> solo._ccRoute;

        for (int m = 0; m < solo._ccRoute; m++) {
            inFile >> myInt;

            solo._myList.push_back(myInt);
        }

        _routeList.push_back(solo);

        solo._myList.clear();
    }

//    DisplayList ();
}

bool findCheapest (Routes a, Routes b) {
    return a._price < b._price;
}

void Backup (int routeIndex) {
    Routes solo;

    solo._price = _routeList[routeIndex]._price;
    solo._ccRoute = _routeList[routeIndex]._ccRoute;

    for (int i = 0; i < _routeList[routeIndex]._myList.size(); i++) {
        solo._myList.push_back(_routeList[routeIndex]._myList[i]);
    }

    _resList.push_back(solo);
}

void Core () {
    bool foundOne = false;

    for (int i = 0; i < _routeList.size(); i++) {

        for (int m = 0; m < _routeList[i]._myList.size(); m++) {
            //cout << "thing -> " << _routeList[i]._myList[m] << "\n\n" << endl;

            if (_routeList[i]._myList[m] == _cityA) {
                foundOne = true;
   
            //    cout << "foundOne >>> TRUE >>> " << _routeList[i]._myList[m] << " >>> " << i << ", " << m << endl;
            }   

            if (_routeList[i]._myList[m] == _cityB && !foundOne) {
            //    cout << "foundTwo >>> TRUE >>> not foundOne >>> " << _routeList[i]._myList[m] << " >>> " << i << ", " << m << endl;
            }
            
            if (_routeList[i]._myList[m] == _cityB && foundOne) {
                Backup(i);

            //    cout << "foundTwo >>> TRUE >>> foundOne >>> " << _routeList[i]._myList[m] << " >>> " << i << ", " << m << endl;
            }
        }

        foundOne = false;
    }

    if (_resList.size() == 0) {
        _res = -1;

        return;
    }

    sort(_resList.begin(), _resList.end(), findCheapest);

    _res = _resList[0]._price;
}

void WriteOut () {
    ofstream outFile ("cowroute.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {
    ParseIn ();
    Core ();
    WriteOut ();

    return 0;
}
