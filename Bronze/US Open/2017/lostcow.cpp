

#include <iostream>
#include <fstream>

using namespace std;

int abs (int a) {
    if (a > 0) {
        return a;
    }

    return a*-1;
}

int main () {
    int curPos = 0;
    int startPos = 0;
    int prevPos = 0;
    int end = 0;
    int res = 0;
    int dis = 1;

    ifstream inFile ("lostcow.in");
    
    inFile >> startPos >> end;

    inFile.close();

    curPos = startPos;

    while (true) {
        //cout << curPos << ", " << prevPos << endl;
        curPos = startPos + dis;

        //cout << curPos << ", " << prevPos << endl;

        if (end <= curPos && dis > 0 && startPos < end) {
            res += abs(end - startPos);

            break;
        }

        if (end >= curPos && dis < 0 && startPos > end) {
            res += abs(end - startPos);

            break;
        }
        
        res += abs(dis*2);
        
        dis*=-2;
    }

    ofstream outFile ("lostcow.out");

    outFile << res << endl;

    outFile.close();

    cout << res << endl;

    return 0;
}
