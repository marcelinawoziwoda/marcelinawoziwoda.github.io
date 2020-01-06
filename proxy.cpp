#include<iostream>
#include<cmath>
using namespace std;
class MiejsceZerowe{
	public:
		double x1, x2;
		MiejsceZerowe(double x1, double x2){
			this->x1 = x1;
			this->x2 = x2;
		}
		MiejsceZerowe(double x){
			x1=x;
			x2 = NULL;
		}
		MiejsceZerowe(){
		x1 = NULL;
		x2 = NULL;
		}
		
		void wypisz(){
			if(x1!=NULL){
				cout<<"x1 = "<<x1<<", ";
					if(x2!=NULL){
						cout<<"x2 = "<<x2<<endl;				
					}
				}
			else
				cout<<"Brak miejsc zerowych"<<endl;	
			}
};
class Funkcja{
	public:
		virtual MiejsceZerowe GetY0(int a, int b, int c) = 0; 
};
class LiczFunkcja :public Funkcja{
	private:
		MiejsceZerowe mz;
		double delta;
		double x1, x2;
	public:
		MiejsceZerowe GetY0(int a, int b, int c){
			cout<<"Licze"<<endl;
			
			delta = b*b - 4*a*c;
				if(delta<0){
					cout<<"Brak miejsc zerowych"<<endl;
				}
				else{
					if(delta == 0){
						cout<<"Jedno rozwiazanie: "<<endl;
						x1 = (-1.0 * b)/(2.0 * a);
						mz = MiejsceZerowe(x1);
					}
				else{
					double sqrt2 = sqrt(delta);
					cout<<"Dwa rozwiazanie: "<<endl;
					x1 = (-1.0*b - sqrt2)/(2.0*a);
                	x2 = (-1.0*b + sqrt2)/(2.0*a);
                	mz = MiejsceZerowe(x1, x2);
				}	
				}
			return mz;
		}
};
class ProxyFunkcja :public Funkcja{
	private:
		MiejsceZerowe mz;
		int a, b ,c;
	public:
		MiejsceZerowe GetY0(int a, int b, int c){
			if(this->a!=a || this->b !=b || this->c != c){
            	this->a=a; this->b=b; this->c=c;
				LiczFunkcja lf;
				mz = lf.GetY0(a, b, c);
				}
		mz.wypisz();
		return mz;
}
};
int main(){
	ProxyFunkcja funkcja;
	funkcja.GetY0(5,9,3);
	funkcja.GetY0(5,9,3);
	return 0;
}


