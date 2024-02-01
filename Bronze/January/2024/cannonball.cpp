

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Type {
    int _type;  //1 for target, 0 for jumppad
    int _power;
};

int main () {
    int length = 0;
    int curPos = 0;
    int power = 1;
    int res = 0;
    int dir = 1; //-1 is backwards, 1 is forwards
    int cc = 0;
    Type solo;
    vector<Type> myList;
    map<int, int> seenTarget;
    
    cin >> length >> curPos;
    
    solo._type = 0;
    solo._power = 0;
    myList.push_back(solo);

    for (int i = 0; i < length; i++) {
        cin >> solo._type >> solo._power;
        myList.push_back(solo);
    }

    //cout << curPos << endl;

    while (true) {
        cc++;
        if (myList[curPos]._type == 1 && seenTarget[curPos] != 1) {
            if (myList[curPos]._power <= power) {
                //cout << "target broken->" << curPos << endl; 
                res++; 
                seenTarget[curPos] = 1;
            }
        }
        if (myList[curPos]._type == 0) {
            dir *= -1;
            power += myList[curPos]._power;

            //cout << "new power->" << power << endl;
        }

        curPos += power*dir;

        //cout << curPos << endl;

        if (seenTarget.size() == myList.size() || curPos > length || curPos < 1 || cc == 1000000) {break;}
    }   

    cout << res << endl;

    return 0;
}
