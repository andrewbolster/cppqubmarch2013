#pragma warning(disable: 4786)

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<list>

using namespace std;

//This class contains details of the event that occured
// Typically there would be a hierarchy of these classes
class ChangeEvent {
public:
	ChangeEvent(string msg);
	string getMessage() const;
private:
	string message;
};

//This is the interface that will be implemented by all
// Observer classes
class Observer {
public:
	virtual void notify(const ChangeEvent& e) = 0;
};

//Instances of this class will be observed
class Observed {
public:
	void stateChange();
	void addListener(Observer* observer);
private:
	void notifyAll(const ChangeEvent& e);
	list<Observer*> observers;
};

//Helper class to notify an observer
class NotifyFunctor {
public:
	NotifyFunctor(const ChangeEvent& e);
	void operator()(Observer* obj);
private:
	const ChangeEvent& event;
};

//Sample observer
class ObserverOne : public Observer {
public:
	void notify(const ChangeEvent& e);
};

//Sample observer
class ObserverTwo : public Observer {
public:
	void notify(const ChangeEvent& e);
};

//Create a ChangeEvent with a message
ChangeEvent::ChangeEvent(string msg) : message(msg) {}

//Access the message
string ChangeEvent::getMessage() const {
	return message;
}

//The functor class takes the event it will pass to all observers
NotifyFunctor::NotifyFunctor(const ChangeEvent& e) : event(e) {}

//Each observer is notified and passed the event object
void NotifyFunctor::operator()(Observer* obj) {
	obj->notify(event);
}

//Trivial implementation of notify
void ObserverOne::notify(const ChangeEvent& e) {
	cout << "ObserverOne notified with event: " << e.getMessage() << endl;
}

//Trivial implementation of notify
void ObserverTwo::notify(const ChangeEvent& e) {
	cout << "ObserverTwo notified with event: " << e.getMessage() << endl;
}

//Add an observer to our list
void Observed::addListener(Observer* observer) {
	observers.push_back(observer);
}

//When clients change the state of the observed
// object we need to notify all observers
void Observed::stateChange() {
	ChangeEvent e("state changed by client");
	notifyAll(e);
}

//Notify all observers
void Observed::notifyAll(const ChangeEvent& e) {
	NotifyFunctor f(e);
	for_each(observers.begin(),observers.end(),f);
}

void main() {

	//Create observers
	ObserverOne obj1;
	ObserverOne obj2;
	ObserverTwo obj3;
	ObserverTwo obj4;
	ObserverOne obj5;
	ObserverTwo obj6;

	//Create the observed object
	Observed observedObject;

	//Add the listeners
	observedObject.addListener(&obj1);
	observedObject.addListener(&obj2);
	observedObject.addListener(&obj3);
	observedObject.addListener(&obj4);
	observedObject.addListener(&obj5);
	observedObject.addListener(&obj6);

	//Trigger notification
	observedObject.stateChange();
}