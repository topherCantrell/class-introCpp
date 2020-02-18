
#include <iostream>
#include <string>

using namespace std;

class Motor {
private:

	bool running;
	int fuelLevel;
	int serialNumber;

public:

	Motor(int serialNumber) {
		this->serialNumber = serialNumber; // Incoming parameter has the same name (could change it)
		cout << "Motor " << serialNumber << " has been built with recycled parts." << endl;
		running = false; // Motors aren't running when you buy them
		fuelLevel = 0;   // Motors don't ship from the factory with gas
	}

	~Motor() {
		cout << "Please take motor " << serialNumber << " to the recycler." << endl;
	}

	void start() {
		// Rules on starting are enforced here. Can't already be running. Get be empty.
		if(running) {
			cout << "Motor " << serialNumber << " is already running." << endl;
			return;
		}
		if(fuelLevel==0) {
			cout << "Motor " << serialNumber << " is out of gas." << endl;
			return;
		}
		if(fuelLevel==1) {
			cout << "Motor " << serialNumber << " running low on gas." << endl;
		}
		fuelLevel = fuelLevel - 1; // Starting takes fuel
		running = true;
		cout << "Vrmmm, Vrmmmm ... motor " << serialNumber << " starts." << endl;
	}

	void stop() {
		// Rules on stopping. Can't already be stopped.
		if(!running) {
			cout << "Motor " << serialNumber << " isn't running." << endl;
			return;
		}
		running = false;
		cout << "Cough, Cough ... motor " << serialNumber << " sputters to a stop." << endl;
	}

	int getFuelLevel() {
		return fuelLevel; // Simple getter (fillTank to set)
	}

	bool isRunning() {
		return running; // Simple getter (no setter)
	}

	int getSerialNumber() {
		return serialNumber; // Simple getter. Can't change serialNumber.
	}

	void fillTank() {
		// Rules on filling. Can't be running. Can't be full.
		if(running) {
			cout << "You should stop motor " << serialNumber << " before filling up with fuel." << endl;
			return;
		}
		if(fuelLevel==4) {
			cout << "Motor " << serialNumber << " tank is already full." << endl;
			return;
		}
		fuelLevel = 4;
		cout << "Motor " << serialNumber << " tank is now full." << endl;
	}

};

void testMotor() {

	Motor motor(123);

	while(true) {
		cout << "1:Start  2:Stop  3:FillTank  4:CheckFuel  5:IsRunning  *:Done" << endl;
		int inp;
		cin >> inp;
		switch(inp) {
		case 1: // Start
			motor.start();
			break;
		case 2: // Stop
			motor.stop();
			break;
		case 3: // fillTank
			motor.fillTank();
			break;
		case 4: // Get fuel level 
			cout << "Motor " << motor.getSerialNumber() << " fuel level: " << motor.getFuelLevel() << endl;
			break;
		case 5: // Is running
			cout << "Motor is running: " << motor.isRunning() << endl;
			break;
		default: // Done
			cout << "Ending motor test." << endl;
			return;
		}
	} 
}




class Truck {
private:

	Motor motor; // A truck has a motor ... it isn't a motor-plus-stuff in my view
	int x; // X location of truck
	int y; // Y location of truck

public:

	Truck() : motor(123), x(0), y(0)
	{
		cout << "This truck has been created." << endl;
		motor.fillTank(); // Truck's come full of gas
	}

	~Truck() {
		cout << "Please give this truck to a needy volunteer department." << endl;
	}

	void start() {
		// This is called "delegation". Passing work on to the motor.
		// We are paritally exposing the motor methods.
		motor.start();
	}

	void stop() {
		motor.stop();
	}

	// Note that motor methods are missing here. You can't do that if you
	// inherit from motor.

	int topOffTank() {
		// Work with the motor's tank to figure out how much fuel we add.
		int fuelLevel = motor.getFuelLevel();
		if(fuelLevel==4) {
			return 0;
		}
		motor.fillTank();
		int newLevel = motor.getFuelLevel();
		return newLevel = fuelLevel;
	}	

	void moveTo(int x, int y) {
		if(x<0 || x>10 || y<0 || y>10) {
			cout << "This truck must stay in the city between (0,0) and (10,10)." << endl;
			return;
		}
		motor.start();
		if(motor.isRunning()) {
			this->x = x;
			this->y = y;
			motor.stop();
		}
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

};

void testTruck() {

	Truck truck;

	while(true) {
		cout << "1:WhereIsTruck   2 x y:Move to X/Y   3:RefuelTruck" << endl;
		int amount, x, y; // Save lines with "," ... all same type
		int inp;
		cin >> inp;
		switch(inp) {
		case 1: // where is the truck?
			cout << "Truck is at " << truck.getX() << "," << truck.getY() << endl;
			break;
		case 2: // move to X,Y
			cin >> x;
			cin >> y;
			truck.moveTo(x,y);
			break;
		case 3: // refuel
			if(truck.getX()!=0 || truck.getY()!=0) {
				cout << "You can only refill truck at station (0,0)." << endl;
				return;
			}
			amount = truck.topOffTank();
			cout << "Truck took " << amount << " units of fuel to fill." << endl;
			break;
		default:
			cout << "Truck test has ended." << endl;
			return;
		}		

	}

}


/**
 * This class encapulates the information about a fireman. A fireman has a name and a possible truck.
 * One a fireman has been given a truck he or she can be sent to fires and back to base for refueling.
 */
class Fireman 
{
private:

	string name;  // Fireman's name
	Truck* truck; // Fireman's truck (or null if none)

	// Think about the memory management of Fireman and truck here. What happens if you delete a fireman?
	// Should the truck be automatically deleted (This class takes ownership)? 
	// Or could several firemen share a truck? (The caller maintains ownership)?
	// You should carefully make comments in the methods where appropriate.
	// (The memory management of trucks below is NOT very thought out. Find the problems.)

public:

	/**
	 * This creates a new Fireman.
	 * @param myName the fireman's name
	 */
	Fireman(string myName) : name(myName), truck(nullptr) // truck(0) for 2008
	{		
		cout << "Fireman " << name << " joins the force." << endl;
	}

	/**
	 * This destroys a Fireman. Be sure to remove the truck first or it will be leaked.
	 */
	~Fireman() {
		cout << "Fireman " << name << " has retired. Thank you for your service." << endl;
	}

	/**
	 * This method assigns a new truck to the fireman.
	 * @param myTruck pointer to the new truck
	 */
	void setTruck(Truck* myTruck) {
		if(truck!=nullptr) {
			cout << "Fireman " << name << " already has a truck." << endl;
			cout << "(Old truck was leaked.)" << endl;
		}
		truck = myTruck;
	}

	void removeTruck() {
		if(truck==nullptr) {
			cout << "Fireman " << name << " has no truck." << endl;
			return;
		}
		delete truck;
	}

	void handleFire(int x, int y) {
		if(truck==nullptr) {
			cout << "Fireman " << name << " has no truck assigned." << endl;
			return;
		}
		truck->moveTo(x,y);
		if(truck->getX()==x && truck->getY()==y) {
			cout << "The fire has been contained." << endl;
		} else {
			cout << name << " couldn't get to the fire." << endl;
		}
	}

	void returnToBase() {
		if(truck==nullptr) {
			cout << "Fireman " << name << " has no truck assigned." << endl;
			return;
		}
		if(truck->getX()==0 && truck->getY()==0) {
			cout << "Fireman " << name << " is already at the base." << endl;
			return;
		}
		truck->moveTo(0,0);
		if(truck->getX()==0 && truck->getY()==0) {
			truck->topOffTank();
			cout << "Ready for another fire." << endl;
		} else {
			cout << name << " couldn't get back to base." << endl;
		}
	}

};

void testFireman() {

	Fireman fireman("Sam");  // Welsh animated TV series

	while(true) {
		cout << "1:GiveTruck  2:RemoveTruck  3 x y:HandleRire  4:returnToBase" << endl;
		int inp,x,y;
		Truck* truck;
		cin >> inp;
		switch(inp) {
		case 1: // give truck
			truck = new Truck();
			fireman.setTruck(truck);
			break;
		case 2: // remove truck
			fireman.removeTruck();
			break;
		case 3: // handle fire
			cin >> x;
			cin >> y;
			fireman.handleFire(x,y);
			break;
		case 4: // return to base
			fireman.returnToBase();
			break;
		default:
			// Did you remove any truck? If you didn't then it gets leaked here.
			return;
		}
	}
}

int main() {


	//testMotor();
	//testTruck();
	testFireman();

			
}