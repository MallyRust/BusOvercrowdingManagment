#include<iostream>

using namespace std;

struct Bus {
	int quantityOfPeople;
	int numberOfBus;
	Bus* next;
	Bus(int busNumber = 0) : numberOfBus(busNumber) {
		this->quantityOfPeople = 0;
		this->next = NULL;
	}
};

class BusApplication {
	Bus* head = NULL;
public:
	void insertNewBus(int busNumber) {
		Bus* newBus = new Bus(busNumber);
		if (head == NULL) {
			head = newBus;
		}
		else {
			Bus* ptr = head;
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = newBus;
		}
	}
	void deleteBus(int busNumber) {
		if (head == NULL) {
			cout << "There are no Buses in the Application\n";
		}
		else if (head->numberOfBus==busNumber) {
			Bus* temp = head;
			head = head->next;
			delete temp;
		}
		else {
			Bus* temp = head;
			Bus* ptr = head;
			while (temp->numberOfBus != busNumber && temp->next!=NULL) {
				ptr = temp;
				temp = temp->next;
			}
			if (temp->numberOfBus != busNumber) {
				cout << "There is no such bus in the application\n";
			}
			else {
				ptr->next = temp->next;
				delete temp;
			}
		}
	}
	void identifyQuantity(int busNumber) {
		int peopleLimit = 40;
		Bus* ptr = head;
		while (ptr->numberOfBus != busNumber) {
			ptr = ptr->next;
		}
		if (ptr->numberOfBus != busNumber) {
			cout << "There is no such bus in the application\n";
		}
		else {
			if (ptr->quantityOfPeople >= peopleLimit) {
				cout << "Bus is full. There is no place to enter the bus\n";
			}
			else {
				double percentageOfPeople = (double)((ptr->quantityOfPeople * 100) / peopleLimit);
				int availableSpace = peopleLimit - ptr->quantityOfPeople;
				cout << "The bus is " << percentageOfPeople << "% full. There is " << availableSpace << " empty sits\n";
			}
		}
	}
	void showAllBuses() {
		if (head == NULL) {
			cout << "There is no buses in the application\n";
		}
		else {
			Bus* ptr = head;
			int countOfBuses = 1;
			while (ptr != NULL) {
				cout << countOfBuses << " bus: " << ptr->numberOfBus << endl;
				ptr = ptr->next;
				countOfBuses++;
			}
		}
		cout << endl;
	}
	void increaseQuantity(int busNumber) {
		cout << "How many people entered the bus: "; int quantity; cin >> quantity;
		Bus* ptr = head;
		while (ptr->numberOfBus != busNumber && ptr->next!=NULL) {
			ptr = ptr->next;
		}
		if (ptr->numberOfBus != busNumber) {
			cout << "There is no such bus in the application. ERROR\n";
		}
		else {
			ptr->quantityOfPeople += quantity;
		}
	}
	void decreaseQuantity(int busNumber) {
		cout << "How many people quit the bus: "; int quantity; cin >> quantity;
		Bus* ptr = head;
		while (ptr->numberOfBus != busNumber && ptr->next != NULL) {
			ptr = ptr->next;
		}
		if (ptr->numberOfBus != busNumber) {
			cout << "There is no such bus in the application. ERROR\n";
		}
		else {
			ptr->quantityOfPeople -= quantity;
			if (ptr->quantityOfPeople < 0) {
				ptr->quantityOfPeople = 0;
			}

		}
	}
};

int main() {
	BusApplication application;
	application.insertNewBus(50);
	application.insertNewBus(12);
	application.insertNewBus(41);
	application.insertNewBus(31);
	application.insertNewBus(56);
	application.showAllBuses();
	application.increaseQuantity(12);
	application.increaseQuantity(41);
	application.identifyQuantity(12);
	application.decreaseQuantity(41);
	application.identifyQuantity(41);
	application.deleteBus(56);
	application.showAllBuses();

}