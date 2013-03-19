#include<iostream>

#define OVERTIME_RATE 50
#define STANDARD_HOURS 30

using namespace std;

class EmployeeStatus;

//We cannot have a simple hierarchy of employee classes
// as client code frequently needs to change the status of
// an employee and should not be burdened with calling
// copy constructors
class Employee {
	//The state classes will modify our data
	friend class PermanentStatus;
	friend class TemporaryStatus;
public:
	Employee(bool isPermanent,double monthlySalary);
	~Employee();
	void changeToPermanent();
	void changeToTemporary();
	double calculateNetSalary(int hoursWorked);
private:
	void changeStatus(EmployeeStatus *newStatus);
private:
	//The state object contains the behaviour appropriate
	// to the employees current status
	EmployeeStatus* currentStatus;
	double monthlySalary;
	int pensionContributions;
	double travelAllowance;
};

//This is the base of the state classes
// We use both variants of the state pattern here
// the methods 'beginNewStatus' and 'endCurrentStatus'
// change the members of the employee object whilst the 
// query method 'isEligableForOvertime' helps the employee
// object calculate its salary
class EmployeeStatus {
public:
	EmployeeStatus(Employee& e);
	virtual void beginNewStatus() = 0;
	virtual void endCurrentStatus() = 0;
	virtual bool isEligableForOvertime() = 0;
protected:
	Employee& employee;
};

class PermanentStatus : public EmployeeStatus {
public:
	PermanentStatus(Employee& e);
	void beginNewStatus();
	void endCurrentStatus();
	bool isEligableForOvertime(); 
};

class TemporaryStatus : public EmployeeStatus {
public:
	TemporaryStatus(Employee& e);
	void beginNewStatus();
	void endCurrentStatus();
	bool isEligableForOvertime(); 
};

Employee::Employee(bool isPermanent,double monthlySalary) : currentStatus(0) {
	if(isPermanent) {
		currentStatus = new PermanentStatus(*this);
	} else {
		currentStatus = new TemporaryStatus(*this);
	}
	this->monthlySalary = monthlySalary;
	currentStatus->beginNewStatus();
};

Employee::~Employee() {
	currentStatus->endCurrentStatus();
	delete currentStatus;
}

void Employee::changeToPermanent() {
	changeStatus(new PermanentStatus(*this));
}

void Employee::changeToTemporary() {
	changeStatus(new TemporaryStatus(*this));
}

void Employee::changeStatus(EmployeeStatus *newStatus) {
	currentStatus->endCurrentStatus();
	delete currentStatus;
	currentStatus = newStatus;
	currentStatus->beginNewStatus();
}

double Employee::calculateNetSalary(int hoursWorked) {
	double netSalary = monthlySalary;

	netSalary -= ((monthlySalary * pensionContributions)/100);

	netSalary += travelAllowance;

	if(currentStatus->isEligableForOvertime() && hoursWorked > STANDARD_HOURS) {
		netSalary += (hoursWorked - STANDARD_HOURS) * OVERTIME_RATE;
	}

	return netSalary;
}

EmployeeStatus::EmployeeStatus(Employee& e) : employee(e) {}

TemporaryStatus::TemporaryStatus(Employee& e) : EmployeeStatus(e) {}

//Set the members of Employee to appropariate values
// for a temporary worker. These are 'magic numbers' where
// in reality we would be performing calculations
void TemporaryStatus::beginNewStatus() {
	employee.pensionContributions = 0;
	employee.travelAllowance = 75;
}

void TemporaryStatus::endCurrentStatus() {}

bool TemporaryStatus::isEligableForOvertime() {
	return true;
}

PermanentStatus::PermanentStatus(Employee& e) : EmployeeStatus(e) {}

//Set the members of Employee to appropariate values
// for a temporary worker. These are 'magic numbers' where
// in reality we would be performing calculations
void PermanentStatus::beginNewStatus() {
	employee.pensionContributions = 20;
	employee.travelAllowance = 0;
}

void PermanentStatus::endCurrentStatus() {}

bool PermanentStatus::isEligableForOvertime() {
	return false;
}

void main() {

	Employee dave(false,50000);

	//dave works a month as a temp
	cout << "As a temporary dave earned " << dave.calculateNetSalary(40) << endl;

	//dave becomes full time staff
	dave.changeToPermanent();

	//dave works a month as permanent staff
	cout << "As full time dave earned " << dave.calculateNetSalary(50) << endl;
}