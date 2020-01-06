#include <iostream>
#include <List>
using namespace std;
class Subject;
class Observer{
	public:
		virtual void Update(Subject* changed) = 0;
};
class Subject{ 
	public:
		list<Observer*> observers;
		void Attach(Observer* observer){
			observers.push_back(observer);
		}
		void Notify(){
			for (list<Observer*>::iterator it=observers.begin(); it != observers.end(); ++it)
				(*it)->Update(this);
			
		}
		virtual int GetState() = 0;
		virtual void SetState(int s) = 0;
};

class ConcreteSubject :public Subject{
	private:
		int subjectState;
	public:

		int GetState(){
			return subjectState;
		}
		void SetState(int s){
			subjectState = s;
		}
};

class ConcreteObserver :public Observer{
	private:
		int observerState;
	public:

		void Update(Subject* changed){
			int tmp = changed->GetState();
			cout<<"Zaaktualizowano stan z "<<observerState<<" na: "<<tmp<<endl;
			observerState = tmp;
		}
};
int main(){
	
		ConcreteObserver co;
        ConcreteObserver co2;
        ConcreteObserver co3;
        
        ConcreteSubject cs;
        cs.Attach(&co);
        cs.Attach(&co2);
        cs.Attach(&co3);
        
        cs.SetState(13);
        cs.Notify();
        cs.SetState(4);
        cs.SetState(6);
        cs.Notify();
	return 0;
}
