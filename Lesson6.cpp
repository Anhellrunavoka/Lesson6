#include <iostream>
#include <vector>
using namespace std;
class MNOZH {
    vector <int> A;
public:
    MNOZH(): A(0){}
    static const MNOZH add(int e, MNOZH result) {
        result.A.push_back(e);
        return result;
    }

    static const MNOZH addmn(MNOZH mn1, MNOZH mn2) {
        MNOZH mn3;
        for (int i = 0; i < mn1.A.size();i++) {
            int c = 0;
            for (int j = 0; j < mn2.A.size(); j++) {
                if (mn1.A[i] == mn2.A[j]) c += 1;
                else {
                    if (i < 1) {
                        mn3.A.push_back(mn2.A[j]);
                    }
                }
            }
            if (c == 0) {
                mn3.A.push_back(mn1.A[i]);
            }
        }
        return mn3;
    }

    friend const MNOZH operator+(int element, const MNOZH& mnozh) {
        return mnozh.add(element, mnozh);
    }
    bool Perevirka(int element, const MNOZH& mnozh) {
        int c = 0;
        for (int i : mnozh.A)
        {
            if (i == element) c += 1;
        } 
        if (c == 1) return true;
        else return false;
    }
    friend const MNOZH operator+(const MNOZH& mnozh1, const MNOZH& mnozh2) {
        return mnozh1.addmn(mnozh1, mnozh2);
    }

    static const MNOZH delet(int e, MNOZH result) {
        auto it = find(result.A.begin(), result.A.end(), e);
        if (it != result.A.end()) {
            result.A.erase(it);
        }
        return result;
    }

    static const MNOZH riznmn(MNOZH mn1, MNOZH mn2) {
        MNOZH mn3;
        for (int i = 0; i < mn1.A.size(); i++) {
            int c = 0;
            for (int j = 0; j < mn2.A.size(); j++) {
                if (mn1.A[i] == mn2.A[j]) c += 1;
            }
            if (c == 0) {
                mn3.A.push_back(mn1.A[i]);
            }
        }
        return mn3;
    }

    friend const MNOZH operator-(int element, const MNOZH& mnozh) {
        return mnozh.delet(element, mnozh);
    }

    friend const MNOZH operator-(const MNOZH& mnozh1, const MNOZH& mnozh2) {
        return mnozh1.riznmn(mnozh1, mnozh2);
    }  

    static const MNOZH peret(MNOZH mn1, MNOZH mn2) {
        MNOZH mn3;
        for (int i = 0; i < mn1.A.size(); i++) {
            int c = 0;
            for (int j = 0; j < mn2.A.size(); j++) {
                if (mn1.A[i] == mn2.A[j]) c += 1;
            }
            if (c == 1) {
                mn3.A.push_back(mn1.A[i]);
            }
        }
        return mn3;
    }

    friend const MNOZH operator*(const MNOZH& mnozh1, const MNOZH& mnozh2) {
        return mnozh1.peret(mnozh1, mnozh2);
    }

    void print() const {
        for (int i : A) {
            cout << i << " ";
        }
        cout << endl;
    }

    void Zapovnennya(){
        int kil;
        cout << "Kilkist elements in massive: ";
        cin >> kil;
        cout << endl;
        for (short i = 0; i < kil; i++) {
            int value,c=0;
            cin >> value;
            for (int i : A) {
                if (i == value) c += 1;
            }
            if(c==0) A.push_back(value);
        }
        cout << endl;
    }

    ~MNOZH() {}
};
int main()
{
    MNOZH A;
    MNOZH B;
    MNOZH C;
    A.Zapovnennya();
    B.Zapovnennya();
    A = 45 + A;
    B = 23 - B;
    if(A.Perevirka(2, A)==true){ cout <<"2 in A mnozhina"<<endl; }
    else { cout << "2 isn`t in A mnozhina" << endl; }
    if (B.Perevirka(45, A) == true) { cout << "45 in B mnozhina" << endl; }
    else { cout << "45 isn`t in B mnozhina" << endl; }
    A.print();
    B.print();
    C=A + B;
    C.print();
    C = A - B;
    C.print();
    C = B - A;
    C.print();
    C = A * B;
    C.print();
}
