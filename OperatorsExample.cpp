//
// Created by edutilos on 20.09.17.
//

#include "OperatorsExample.h"

void OperatorsExample::arithmeticOps() {
    class SimpleDoubleMath {
    private:
        double x;
        double y;

    public:
        SimpleDoubleMath(double x, double y) {
            this->x = x ;
            this->y = y;
        }

        double add() {
            return this->x + this->y ;
        }
        double subtract() {
            return this->x - this->y;
        }

        double multiply() {
            return this->x * this->y;
        }

        double divide()  {
            return this->x / this->y;
        }

    };


    SimpleDoubleMath sdm(10, 3);
    cout << "<<SimpleDoubleMath>>" << endl;
    cout << "10 + 3 = " << sdm.add() << endl;
    cout << "10 - 3 = " << sdm.subtract() << endl;
    cout << "10 * 3 = " << sdm.multiply() << endl;
    cout << "10 / 3 = " << sdm.divide() << endl;
    cout << endl;



    class SimpleIntMath {
    private:
        int x ;
        int y ;
    public:
        SimpleIntMath(int x, int y) {
            this-> x = x ;
            this-> y = y ;
        }

        int add() {
            return this->x + this->y ;
        }

        int subtract() {
            return this->x - this->y;
        }

        int multiply() {
            return this->x * this->y ;
        }

        int divide() {
            return this->x / this->y;
        }

        int modulo() {
            return this->x % this->y;
        }
    };

    SimpleIntMath sim(10, 3);
    cout << "<<SimpleIntMath>>" << endl;
    cout << "10 + 3 = " << sim.add() << endl;
    cout << "10 - 3 = " << sim.subtract() << endl;
    cout << "10 * 3 = " << sim.multiply() << endl;
    cout << "10 / 3 = " << sim.divide() << endl;
    cout << "10 % 3 = " << sim.modulo() << endl;
    cout << endl;

}

void OperatorsExample::relationalOps() {
    double x = 10, y = 3 ;
    bool eq = x == y ,
    ne = x != y ,
    lt = x < y,
    le = x <= y ,
    gt = x > y ,
    ge = x >= y ;

    cout << "<<Relational Operators>>" << endl;
    cout << "x = " << x << " and y = " << y << endl;
    cout << "x == y = " << eq << endl;
    cout << "x != y = " << ne << endl;
    cout << "x < y = " << lt << endl;
    cout << "x <= y = " << le << endl;
    cout << "x > y = " << gt << endl;
    cout << "x >= y = " << ge << endl << endl;
}

void OperatorsExample::logicalOps() {
    bool x = true , y = false;
    bool resAnd = x && y ,
    resOr = x || y ,
    resNotX = !x,
    resNotY = !y ;
    cout << "<<Logical Operators>>" << endl;
    cout << "x = " << x << " and y = " << y << endl;
    cout << "x && y = " << resAnd << endl;
    cout << "x || y = " << resOr << endl;
    cout << "!x = " << resNotX << endl;
    cout << "!y = " << resNotY << endl << endl;
}
