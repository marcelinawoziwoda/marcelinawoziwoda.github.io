#include <iostream>

using namespace std;

class Handler{
	public:
		virtual void ShowHelp()=0;
		virtual void HandleHelp()=0;
};

class aPrintButton :public Handler{
	public:
		void ShowHelp(){}
		
		void HandleHelp(){
			cout<<"aPrintButton: odebralem zadanie wyswietlania pomocy"<<endl;
			if(false){
				ShowHelp();
			}
			else{
				cout<<"aPrintButton: nie potafie obslugiwac zadania i wysylam je dalej"<<endl;			
			}
		}
};

class anOKButton :public Handler{
	public:
		void ShowHelp(){}
		
		void HandleHelp(){
			cout<<"anOKButton: odebralem zadanie wyswietlania pomocy"<<endl;
			if(false)
				ShowHelp();
			else{
				cout<<"anOKButton: nie potafie obsluzyc zadania i przekazuje je dalej"<<endl;
			}
		}
};

class aPrintDialog: public Handler{
	public:
		void ShowHelp(){}
		
		void HandleHelp(){
			cout<<"aPrintDialog: odebralem zadanie wyswietlania pomocy"<<endl;
			if(false)
				ShowHelp();
			else{
				cout<<"aPrintDialog: nie potrafie obsluzyc zadania i przekazuje je dalej"<<endl;
			}
		}
};

class aSaveDialog :public Handler{
	public:
		void ShowHelp(){
		}
		
		void HandleHelp(){
			cout<<"aSaveDialog: odebralem zadanie wyswietlania pomocy"<<endl;
				if(false)
					ShowHelp();
				else{
					cout<<"aSaveDialog: nie potafie obslugiwac zadania i przekazuje je dalej"<<endl;
				}
		}
};

class anApplication :public Handler{
	public:
		void ShowHelp(){
			cout<<"anApplication: potrafie obsluzyc zadanie, wyswietlam pomoc"<<endl;
		}
		void HandleHelp(){
			cout<<"AnApplication: odebralem zadanie wyswietlania pomocy"<<endl;
				if(true){
					ShowHelp();
				}
		}
};

class NullHandler :public Handler{
	public:
		void HandleHelp(){
			cout<<"Pusty obiekt"<<endl;
		}
		void ShowHelp(){
			cout<<"Pusty obiekt"<<endl;
		}
};


int main(){
	aPrintButton b1;
	b1.HandleHelp();

}
