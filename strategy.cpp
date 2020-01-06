#include <iostream>
#include <string>
using namespace std;

class ObliczPodatek{
	public:
		virtual double kwotaPodatku(double *tab, int size)=0;
};
class PodatekPolska :public ObliczPodatek{
	private:
		double podatek=1.23;
	public:
		double kwotaPodatku(double *tab, int size){
			double cena_netto =0;
			double cena_brutto =0;
			int i=0;
			while(i<size){
				
				cena_netto+=tab[i];
				cena_brutto+=tab[i]*podatek;
				i++;
			}
			cout<<"cena netto wszystkich elementow:"<<cena_netto<<endl;
			cout<<"cena brutto wszystkich elementow:"<<cena_brutto<<endl;			
			return cena_brutto;
		}
};
class PodatekNiemcy :public ObliczPodatek{
	private:
		double podatek=500.5;
	public:
		double kwotaPodatku(double *tab, int size){
			double cena_netto =0;
			double cena_brutto =0;
			int i=0;
			while(i<size){
				
				cena_netto+=tab[i];
				cena_brutto+=tab[i]+podatek;
				i++;
			}
			cout<<"cena netto wszystkich elementow:"<<cena_netto<<endl;
			cout<<"cena brutto wszystkich elementow:"<<cena_brutto<<endl;			
			return cena_brutto;
		}		
};
class Zamowienie{
	private:
		int size;
		double *tablica;
	protected:
		ObliczPodatek *op;
	public:
		Zamowienie(ObliczPodatek *op, double *tablica, int size){
			this->op = op;
			this->tablica = tablica;
			this->size = size;
		}
		double obliczPodatek(){
			double wynik;
			wynik = op->kwotaPodatku(tablica, size);
			return wynik;
		}		
};
int main(){
	double tab[5]={2.99,4.59,6.10,8.22,10.35};
	ObliczPodatek *op1 = new PodatekPolska;
	ObliczPodatek *op2 = new PodatekNiemcy;
	Zamowienie z1(op1, tab, sizeof tab/sizeof tab[0]);
	z1.obliczPodatek();
}
