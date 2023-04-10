#pragma once
//
//  Uzbuve.h
//  GameBeta
//
//  Created by Mihails Bordjakovskis on 08/04/2023.
//

#ifndef Uzbuve_h
#define Uzbuve_h


#endif /* Uzbuve_h */
#include<iostream>
#include<string>
#include<sstream>
#include <map>
#include <list>
#include <set>
#include <iostream>
#include <fstream>



//======================darbibas ar skaitli======================== sakums
using namespace std;
class Dalis {
private:

    int sk, dal2, dal3, min5;
public:
    Dalis(int sk);
    Dalis(int dal2, int dal3, int min5);
    void Setdal2(int sk);
    void Setdal3(int sk);
    void Setmin5(int sk);
    int Getdal2()const;
    int Getdal3()const;
    int Getmin5()const;
    void Print() const;
};

inline void Dalis::Print() const {
    cout << " skaitlis spied:" << endl;
    if (dal2 != 0) { cout << "|1| sadalit to uz 2=" << dal2 << endl; }
    if (dal3 != 0) { cout << "|2| sadalit to uz 3=" << dal3 << endl; }
    cout << "|3|atniemt 5=" << min5 << endl;
}

inline Dalis::Dalis(int sk) {
    if (sk % 2 == 0) {
        dal2 = sk / 2;

    }
    else {
        dal2 = 0;
    }
    if (sk % 3 == 0) {
        dal3 = sk / 3;

    }
    else {
        dal3 = 0;
    }

    min5 = sk - 5;
}
inline Dalis::Dalis(int d2, int d3, int m5) {
    dal2 = d2;
    dal3 = d3;
    min5 = m5;

}

inline void Dalis::Setdal2(int sk) {
    dal2 = sk / 3;
    cout << dal2 << endl;
}

inline void Dalis::Setdal3(int sk) {
    dal3 = sk / 6;
    cout << dal3 << endl;
}

inline void Dalis::Setmin5(int sk) {
    min5 = sk - 7;
    cout << min5 << endl;
}

inline int Dalis::Getdal2() const {
    return dal2;
    cout << dal2 << endl;
}

inline int Dalis::Getdal3() const {
    return dal3;
    cout << dal3 << endl;
}

inline int Dalis::Getmin5() const {
    return min5;
    cout << min5 << endl;
}

//======================darbibas ar skaitli======================== beigas


//======================koka izvade pareiza ar vertibam============== sakums
//koka saglabashana faila 
class revers { 
public:

    revers(string location , int x, map<int, set<int> >& mapOfList)
    {
        ofstream out;
        out.open(location);

        if (out.is_open()) {
            out << "   limenis         Vertibas" << "\n\n";
            //cout << "   ";
            string text;
            int i = 0;
            for (; i < (mapOfList.size()); i++) {

                int key = i;
                out << key;
                string f = "";
                if (key % 2 == 0) { f = "max"; }
                else {
                    f = "min";
                }

                set<int> ourList = mapOfList[i];
                out << "   ";
                if (key >= 10)
                    out << key << "    " << f << "     ";
                else
                    out << key << "     " << f << "     ";
                for (auto it = ourList.begin();
                    it != ourList.end(); it++) {
                    if (key % 2 == 0) {
                        if (i < (mapOfList.size() - 1) && i >= 0 && (*it) == 10 && (*it) % 2 == 0 && (*it) % 3 != 0) {
                            if ((*it) == 10) out << (*it) << ":-1 ";
                            else out << (*it) << ":+1 ";
                        }
                        else {
                            if ((*it) > 15 && ((*it) - 5) % 2 == 0 && ((*it) - 5) % 3 != 0) {
                                out << (*it) << ":-1 ";

                            }
                            else {
                                if ((*it) >= 10 && (((*it) - 5) % 2 == 0 && ((*it) - 5) % 3 == 0)) {
                                    out << (*it) << ":-1 ";
                                }
                                else {
                                    out << (*it) << ":+1 ";
                                }
                            }
                        }
                    }
                    else {
                        if (i < (mapOfList.size() - 1) && i >= 0 && (*it) == 10 && (*it) % 2 == 0 && (*it) % 3 != 0) {
                            if ((*it) == 10) out << (*it) << ":+1 ";
                            else out << (*it) << ":-1 ";
                        }
                        else {
                            if ((*it) > 15 && ((*it) - 5) % 2 == 0 && ((*it) - 5) % 3 != 0) {
                                out << (*it) << ":+1 ";
                            }
                            else {
                                if ((*it) >= 10 && (((*it) - 5) % 2 == 0 && ((*it) - 5) % 3 == 0)) {
                                    out << (*it) << ":+1 ";
                                }
                                else {
                                    out << (*it) << ":-1 ";
                                }
                            }
                        }
                    }
                }
                out << endl;
            }
            out << endl;
        }
        out.close();
    }


};

//======================koka izvade ar vertibam====================== beigas



//==========================koka izvade bez vertibam================= sakums

class printMapContent1 {
public:

    printMapContent1(int x, map<int, set<int> >& mapOfList)
    {

        cout << "   limenis         Vertibas" << "\n\n";
        cout << "   ";
        cout << 0 << "     max      " << x << endl;

        for (auto p : mapOfList) {

            int key = p.first;
            string f = "";
            if (key % 2 == 0) { f = "max"; }
            else {
                f = "min";
            }

            set<int> ourList = p.second;
            cout << "   ";
            if (key >= 10)
                cout << key << "    " << f << "     ";
            else
                cout << key << "     " << f << "     ";
            for (auto it = ourList.begin();
                it != ourList.end(); it++) {
                cout << (*it) << ' ';

            }
            cout << endl;
        }
    }
};


//==========================koka izvade bez vertibam================= beigas



//==========================pashlaiciga koka atgrieshana================= sakums

inline map<int, set<int>> test(map<int, set<int>> Koks,int m_Area) {
    set<int> virs;
    virs.insert(m_Area);
    Koks[0] = virs;
    for (int i = 0, m = 0;;) {
        virs = Koks[i];
        m--;
        i++;
        set<int> virs2;
        for (auto it = virs.begin(); it != virs.end(); it++) {
            Dalis* L2 = new Dalis(*it);

            if (L2->Getdal2() > 0) {
                virs2.insert(L2->Getdal2());
            }

            if (L2->Getdal3() > 0) {
                virs2.insert(L2->Getdal3());
            }

            if (L2->Getmin5() > 0) {
                virs2.insert(L2->Getmin5());
            }

        }

        if (virs2.empty()) { break; }
        Koks[i] = virs2;
    }
    return Koks;

}//==========================pashlaiciga koka atgrieshana================= beigas

//==========================datora parbaudes algoritms ================= sakums

inline int logika(int x) {
    map<int, set<int>> Koks;

    int cmd;
    int m = 0;
    Koks = test(Koks, x);
    set<int> ourList = Koks[1];
    Dalis* Cip = new Dalis(x);
    for (auto it = ourList.begin();
        it != ourList.end(); it++) {
        if ( (*it) == 10 && (*it) % 2 == 0 && (*it) % 3 != 0) {
            if ((*it) == 10) m=1;
            else m=0;
        }
        else {
            if ((*it) > 15 && ((*it) - 5) % 2 == 0 && ((*it) - 5) % 3 != 0) {
                m = 1;
            }
            else {
                if ((*it) >= 10 && (((*it) - 5) % 2 == 0 && ((*it) - 5) % 3 == 0)) {
                    m = 1;
                }
                else {
                    m = 0;
                }
            }
        }

        if (m == 1 && Cip->Getdal2() == *it) { cmd = *it; break; }
        else if (m == 1 && Cip->Getdal3() == *it) { cmd = *it; break; }
        else if (m == 1 && Cip->Getmin5() == *it) { cmd = *it; break; }
        else {
            cmd = *it;

        }


    }
    return cmd;


}
//==========================datora parbaudes algoritms ================= sakums