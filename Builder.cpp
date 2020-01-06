#include <iostream>
#include <string>
#include <cctype>
using namespace std;
class Builder{
	public:
		virtual void znakiZwykle(char c) = 0;
		virtual void znakiSformatowane(string s) = 0;
};

class Builder1 : public Builder{
	public:
		void znakiZwykle(char c){
			cout<<c;
		}
		
		void znakiSformatowane(string s){
			string x = s.substr(s.find(">")+1, s.find(">")-1);
			cout<<x;
		}
};

class Builder2 : public Builder{
	public:
		void znakiZwykle(char c){
			putchar(tolower(c));
		}
		
		void znakiSformatowane(string s){
			string x = s.substr(s.find(">")+1, s.find(">")-1);
			putchar(toupper(x.at(0)));
		}
};

class Builder3 : public Builder{
	public:
		void znakiZwykle(char c){
			cout<<c;
		}
		
		void znakiSformatowane(string s){
			char x = toupper(s.substr(s.find(">")+1, s.find(">")-1).at(0));
			cout<<s.replace(s.find(">")+1, 1, &x);
		}
};
class Builder4 : public Builder{
	public:
		void znakiZwykle(char c){
			cout<<c;
		}
		
		void znakiSformatowane(string s){
			string x = s.substr(s.find("<")+1, s.find(">")-1);
			string y = s.substr(s.find(">")+1, s.find(">")-1);
			cout<<"{"<<x<<"#"<<y<<"}";
		}
};
class HTMLReader{
	private:
		Builder *builder;
	public:
		void SetBuilder(Builder* b){
			builder = b;
		}
		
		void parseHTML(string plik){
			string sformatowany = "";
			bool czySformatowany = false;
			int licznikZamkniec = 0;
			
			for(int i=0; i<plik.length(); i++){
            if(czySformatowany){
                sformatowany += plik.at(i);
                
                if(plik.at(i)=='>')
                    licznikZamkniec++;
                
                if(licznikZamkniec==2){
                    builder->znakiSformatowane(sformatowany);
                    
                    licznikZamkniec =0;
                    czySformatowany = false;
                    sformatowany = "";
                }
            } else if(plik.at(i)=='<'){
                sformatowany += plik.at(i);
                czySformatowany = true;
            } else
                builder->znakiZwykle(plik.at(i));
            }
            
		}
};
int main(){
	string plik = "A<b>l</b>a ma <i>k</i>o<u>t</u>a";
        
    HTMLReader reader;
    reader.SetBuilder(new Builder1());
    reader.parseHTML(plik);
	
	cout<<endl;
    reader.SetBuilder(new Builder2());
    reader.parseHTML(plik);
	        
	cout<<endl;
    reader.SetBuilder(new Builder3());
    reader.parseHTML(plik);
    
    cout<<endl;
    reader.SetBuilder(new Builder4());
    reader.parseHTML(plik);
	        
	return 0;
}
