#include <iostream>
using namespace std;
class BG1{
	public:
	void rysuj_linie (double x1, double y1, double x2, double y2){
	cout<<"Rysuje linie za pomoca biblioteki graficznej BG1"<<endl;
	}
	void rysuj_okrag (double x, double y,double z){
	cout<<"Rysuje okrag za pomoca biblioteki graficznej BG1"<<endl;
}
};
class BG2{
	public:
	void narysuj_linie (double x1, double y1, double x2, double y2){
	cout<<"Rysuje linie za pomoca biblioteki graficznej BG2"<<endl; 
	}
	void narysuj_okrag (double x, double y,double z){
	cout<<"Rysuje okrag za pomoca biblioteki graficznej BG2"<<endl;
	}
};
class Biblioteka {
public:	
	virtual void rysujLinie (double x1, double y1, double x2, double y2)=0;
	virtual void rysujOkrag (double x, double y,double z)=0;
};
class BibliotekaV1 :public Biblioteka{
	public:
		BG1 *BG1;
		void rysujLinie (double x1, double y1, double x2, double y2){
			BG1->rysuj_linie(x1,y1,x2,y2);
		} 
		void rysujOkrag (double x, double y,double z){
			BG1->rysuj_okrag (x,y,z);
		}	
};
class BibliotekaV2 :public Biblioteka{
	public:
		BG2 *BG2;
		void rysujLinie (double x1,double y1,double x2,double y2){
			BG2->narysuj_linie(x1,y1,x2,y2);
		} 
		void rysujOkrag (double x, double y, double z){
			BG2->narysuj_okrag (x,y,z);
		}	
};
class Figura {
	protected:
			Biblioteka *bg;
	void RysujLinie(double x1, double y1, double x2, double y2){
		bg->rysujLinie(x1,y1,x2,y2);
	}
	void RysujOkrag(double x, double y,double z){
		bg->rysujOkrag(x,y,z);
	}
	public:
	virtual void rysuj()=0;
};
class Prostokat :public Figura{
	private:
		double x1,y1,x2,y2;
	public:
		Prostokat(Biblioteka *b, double x1, double y1, double x2, double y2){
			this->bg = b;
			this->x1  = x1;
			this->y1 = y1;
			this->x2 = x2;
			this->y2 = y2;
		}
		void rysuj(){
			RysujLinie(x1,y1,x2,y2);
		}
};
class Okrag :public Figura{
	private:
		double x,y,z;
	public:
		Okrag(Biblioteka *b, double x, double y, double z){
			this->bg = b;
			this->x  = x;
			this->y = y;
			this->z = z;
		}
		void rysuj(){
			RysujOkrag(x,y,z);
		}
};
int main(){

	Biblioteka *bg1;
	bg1= new BibliotekaV1;
	Biblioteka *bg2;
	bg2 = new BibliotekaV2;
	Figura *f1;
	Figura *f2;
	f1 = new Prostokat(bg1, 2, 3, 4, 2);
	f2 = new Okrag(bg2, 3, 2, 5);
	f1->rysuj();
	f2->rysuj();
	return 0;
}

