

#include <iostream>
#include <vector>
using namespace std;

string _myStr = "GHGH";

int _res = 0;

vector<int> _toList;

void CParseIn () {
    int solo  = 0;
    int maxi = 0;

    cin >> maxi;
    cin >> _myStr;

    for (int i = 0; i < maxi; i++) {
        cin >> solo;

        _toList.push_back(solo);
    }
}

void Core () {
    int ifg = -1; //index (of) first G
    int ifh = -1; //index (of) first H
    int ilg = -1;
    int ilh = -1;
    int hlead = 0;
    int glead = 0;
    int gLeader = -1;
    int hLeader = -1;
    //guaranteed one pair

    //find ifg, ifh, ilg, ilh
    for (int i = 0; i < _myStr.length(); i++) {
        if (_myStr[i] == 'G' && ifg == -1) {
            ifg = i;    
        }
       
        if (_myStr[i] == 'H' && ifh == -1) {
            ifh = i;    
        }

        if (ifg != -1 && ifh != -1) {
             break;
        }
    }

    for (int i = _myStr.length(); i > -1; i--) {
        if (_myStr[i] == 'G' && ilg == -1) {
            ilg = i;    
        }
       
        if (_myStr[i] == 'H' && ilh == -1) {
            ilh = i;    
        }

        if (ilg != -1 && ilh != -1) {
             break;
        }
    }

    //index found. 
    //cout << _toList[ifg] << " " << _toList[ifg] << endl;

    if (_toList[ifg] > ilg - 1) {
        glead ++;
        gLeader = ifg;
    }
    if (_toList[ifh] > ilh - 1) {
        hlead++;
        hLeader = ifh;
    }
    
    if (glead == 0) {
        for (int i = 0; i < _myStr.length(); i++) {
            if (_myStr[i] == 'G' && i < hLeader && _toList[i] > hLeader) {
                glead++;
                
                if (gLeader == -1) {
                    gLeader = i;
                }
            }
        }

        for (int i = 0; i < _myStr.length(); i++) {
            if (_myStr[i] == 'H' && i < gLeader && _toList[i] > gLeader) {
                hlead++;
            }
        }

        _res = hlead * glead;
    }


    if (hlead == 0) {
        for (int i = 0; i < _myStr.length(); i++) {
            if (_myStr[i] == 'H' && i < gLeader && _toList[i] > gLeader) {
                hlead++;

                if (hLeader == -1) {
                    hLeader = i;
                }
            }
        }

        for (int i = 0; i < _myStr.length(); i++) {
            if (_myStr[i] == 'G' && i < hLeader && _toList[i] > hLeader) {
                glead++;
            }
        } 

        _res = hlead * glead;       
    } 

    for (int i = 0; i < _myStr.length(); i++) {
        if (_myStr[i] == 'H' && i < gLeader && _toList[i] > gLeader) {
            hlead++;

            if (hLeader == -1) {
                hLeader = i;
            }
            }
    }

    for (int i = 0; i < _myStr.length(); i++) {
        if (_myStr[i] == 'G' && i < hLeader && _toList[i] > hLeader) {
            glead++;
        }
    } 

    if (_res == 0) {
        _res = glead * hlead;
    }
    // cout << hlead << endl;
    // cout << glead << endl;
}

void CWriteOut () {
    cout << _res << endl;
}

int main () {
    CParseIn ();
    Core ();
    CWriteOut ();

    return 0;
}
