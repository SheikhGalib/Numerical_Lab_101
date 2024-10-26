#include "Jacobi_Iterative.h"
#include "iostream"

using namespace std;

void Iterative::create_eqn(int a, int b, int c, int d, int e, int f) {
    ca = a;
    cb = b;
    cc = c;
    cd = d;
    ce = e;
    c = f;
}

void Jacobi_Iterative_Equation::assign_val(void) {
    cout << "Coefficient of a in equation 1: ";
    cin >> e1.ca;
    cout << "Coefficient of b in equation 1: ";
    cin >> e1.cb;
    cout << "Coefficient of c in equation 1: ";
    cin >> e1.cc;
    cout << "Coefficient of d in equation 1: ";
    cin >> e1.cd;
    cout << "Coefficient of e in equation 1: ";
    cin >> e1.ce;
    cout << "Coefficient equation 1: ";
    cin >> e1.c;

    cout << "Coefficient of a in equation 2: ";
    cin >> e2.ca;
    cout << "Coefficient of b in equation 2: ";
    cin >> e2.cb;
    cout << "Coefficient of c in equation 2: ";
    cin >> e2.cc;
    cout << "Coefficient of d in equation 2: ";
    cin >> e2.cd;
    cout << "Coefficient of e in equation 2: ";
    cin >> e2.ce;
    cout << "Coefficient equation 2: ";
    cin >> e2.c;

    cout << "Coefficient of a in equation 3: ";
    cin >> e3.ca;
    cout << "Coefficient of b in equation 3: ";
    cin >> e3.cb;
    cout << "Coefficient of c in equation 3: ";
    cin >> e3.cc;
    cout << "Coefficient of d in equation 3: ";
    cin >> e3.cd;
    cout << "Coefficient of e in equation 3: ";
    cin >> e3.ce;
    cout << "Coefficient equation 3: ";
    cin >> e3.c;

    cout << "Coefficient of a in equation 4: ";
    cin >> e4.ca;
    cout << "Coefficient of b in equation 4: ";
    cin >> e4.cb;
    cout << "Coefficient of c in equation 4: ";
    cin >> e4.cc;
    cout << "Coefficient of d in equation 4: ";
    cin >> e4.cd;
    cout << "Coefficient of e in equation 4: ";
    cin >> e4.ce;
    cout << "Coefficient equation 4: ";
    cin >> e4.c;

    cout << "Coefficient of a in equation 5: ";
    cin >> e5.ca;
    cout << "Coefficient of b in equation 5: ";
    cin >> e5.cb;
    cout << "Coefficient of c in equation 5: ";
    cin >> e5.cc;
    cout << "Coefficient of d in equation 5: ";
    cin >> e5.cd;
    cout << "Coefficient of e in equation 5: ";
    cin >> e5.ce;
    cout << "Coefficient equation 5: ";
    cin >> e5.c;
}

int Jacobi_Iterative_Equation::Jacobi(double a, double b, double c, double d, double e) {
    static int t = 0;
    er1 = er2 = er3 = er4 = er5 = erm = 0;

    double ai = a;
    double bi = b;
    double ci = c;
    double di = d;
    double ei = e;

    double af = (e1.c - e1.cb * bi - e1.cc * ci - e1.cd * di - e1.ce * ei) / e1.ca;
    double bf = (e2.c - e2.ca * ai - e2.cc * ci - e2.cd * di - e2.ce * ei) / e2.cb;
    double cf = (e3.c - e3.cb * bi - e3.ca * ai - e3.cd * di - e3.ce * ei) / e3.cc;
    double df = (e4.c - e4.ca * ai - e4.cc * ci - e4.cb * bi - e4.ce * ei) / e4.cd;
    double ef = (e5.c - e5.cb * bi - e5.ca * ai - e5.cd * di - e5.cc * ci) / e5.ce;

    t++;

    if (ai != 0 && bi != 0 && ci != 0 && di != 0 && ei != 0) {
        er1 = abs(af - ai);
        er2 = abs(bf - bi);
        er3 = abs(cf - ci);
        er4 = abs(df - di);
        er5 = abs(ef - ei);
        erm = (er1 + er2 + er3 + er4 + er5) / 5;
    }

    cout << "\nIteration " << t << " results:\n";
    cout << "a: " << af << ", b: " << bf << ", c: " << cf << ", d: " << df << ", e: " << ef << endl;
    cout << "Errors: " << er1 << ", " << er2 << ", " << er3 << ", " << er4 << ", " << er5 << endl;
    cout << "Mean Error: " << erm << endl;

    if (t > 1 && erm < 0.00001) {
        return 0;
    } else {
        return Jacobi(af, bf, cf, df, ef);
    }
}

void Jacobi_Iterative_Equation::Jacobi_Iterative_Solve(void) {
    assign_val();
    Jacobi(0, 0, 0, 0, 0);
}
