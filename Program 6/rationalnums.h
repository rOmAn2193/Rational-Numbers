#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

class RationalNums
{
   public:
    RationalNums(int, int);
    //RationalNums(int numerator);
    RationalNums();
	int getn();
	int getd();
	void setn(int num);
	void setd(int den);
    void reducem();
    friend RationalNums operator+(RationalNums x, RationalNums y);
	friend RationalNums operator-(RationalNums x, RationalNums y);
    friend RationalNums operator*(RationalNums x, RationalNums y);
    friend RationalNums operator/(RationalNums x, RationalNums y);
    friend ofstream& operator <<(ofstream &outf, RationalNums&);
    friend ifstream& operator >>(ifstream &inf, RationalNums&);
	void printem(ofstream &outf);
private:
    int n;
    int d;
    int min(int num, int den);
};
