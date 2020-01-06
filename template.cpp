#include <iostream>
#include <string>
using namespace std;
class BazaDanych{
	public:
		virtual void wykonajZapytanie(string zapytanie) =0;
};
class SQLServer :public BazaDanych{
	public:
		void wykonajZapytanie(string zapytanie){
			cout<<"SQLServer: "<<zapytanie<<endl;
		}
};
class Oracle :public BazaDanych{
	public:
		void wykonajZapytanie(string zapytanie){
			cout<<"Oracle: "<<zapytanie<<endl;
		}
};
class SzablonZapytania{
	private:
		BazaDanych *bd;
	protected:
		virtual string formatujSelect(string specZapyt)=0;
	public:
		virtual BazaDanych* utworzBD()=0;
		void wykonajZapytanie(string specZapyt){
			string komendaBD;
			komendaBD=formatujSelect(specZapyt);
			
			bd = utworzBD();
			bd->wykonajZapytanie(komendaBD);	
		}
};
class ZapytanieSQLServer :public SzablonZapytania{
	public:
		string formatujSelect(string specZapyt){
			return specZapyt;
		}
		BazaDanych* utworzBD(){
			BazaDanych *sql = new SQLServer;
			return sql;
			}
};
class ZapytanieOracle :public SzablonZapytania{
	public:
		string formatujSelect(string specZapyt){
			string sformatowany = specZapyt+";";
			return sformatowany;
		}
		BazaDanych* utworzBD(){
			return (new Oracle);
			}
};
int main(){
	string select = "CREATE TABLE Heroes (id int, name varchar(25), siblings int)";
	SzablonZapytania *szablonzap1;
	SzablonZapytania *szablonzap2;
	szablonzap1 = new ZapytanieSQLServer;
	szablonzap2 = new ZapytanieOracle;
	
	szablonzap1->wykonajZapytanie(select);
	szablonzap2->wykonajZapytanie(select);
	
	return 0;
}
