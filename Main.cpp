#include <iostream>
#include <vector>
#include <string>

class Person {
public:
	Person(unsigned int age, std::string name) {
		_age = age;
		_name = name;
	}
	
	std::string SetName(std::string name) {
		_name = name;
	}

	unsigned int SetAge(unsigned int age) {
		_age = age;
	}

	std::string GetName() {
		return _name;
	}

	unsigned int GetAge() {
		return _age;
	}

	void showAll() {
		std::cout << "Name: " << _name << std::endl;
		std::cout << "Age: " << _age << "\n\n";
	}

private:
	std::string _name;
	unsigned int _age;
};

class Pupil {
public:
	Pupil(unsigned int age, std::string name) {
		_age = age;
		_name = name;
	}

	std::string SetName(std::string name) {
		_name = name;
	}

	unsigned int SetAge(unsigned int age) {
		_age = age;
	}

	void SetMarks() {
		std::cout << "Enter marks quantity -> ";
		int qty;
		std::cin >> qty;
		std::cout << "Enter marks: \n";
		for (int i = 0; i < qty; i++) {
			int mark = 0;
			std::cout << "-> ";
			std::cin >> mark;
			_marks.push_back(mark);
		}
	}

	std::string GetName() {
		return _name;
	}

	unsigned int GetAge() {
		return _age;
	}

	void GetMarks(std::vector <int> marks) {
		for (int i = 0; i < marks.size(); i++)
			std::cout << marks[i] << ", ";
		std::cout << "\b\b.\n";
	}

	void showAll() {
		std::cout << "Name: " << _name << std::endl;
		std::cout << "Age: " << _age << std::endl;
		for (int i = 0; i < _marks.size(); i++)
			std::cout << _marks[i] << ", ";
		std::cout << "\b\b.\n\n";
	}

private:
	std::string _name;
	unsigned int _age;
	std::vector <int> _marks;
	};

class Professor {
public:
	Professor(std::string name, std::string degree) {
		_name = name;
		_degree = degree;
	}

	std::string SetName(std::string name) {
		_name = name;
	}

	std::string SetDegree(std::string degree) {
		_degree = degree;
	}
	
	std::string GetName() {
		return _name;
	}

	std::string GetDegree() {
		return _degree;
	}

	void showAll() {
		std::cout << "Name: " << _name << std::endl;
		std::cout << "Degree: " << _degree << "\n\n";
	}

private:
	std::string _name;
	std::string _degree;
};

class Client {
private:
	std::string _name;
	int _age;
	long long _bill;
public:
	Client(std::string name, int age, long long bill) {
		_name = name;
		_age = age;
		_bill = bill;
	}

	void ShowData() {
		std::cout << "Client's name: " << _name << '\n';
		std::cout << "Client's agee: " << _age << '\n';
		std::cout << "Client's bill: " << _bill << "\n\n";
	}

	~Client() {	// Деструктор - вызывается при удалении объекта
		std::cout << _name << " deleted\n";
	}
};

class Bank {
private:
	std::vector <Client*> _clients;

public:
	void AddClient(Client* client) {
		_clients.push_back(client);
	}

	void ShowClients() {
		/*std::vector <Client*>::iterator it;
		for (it = _clients.begin(); it != _clients.end(); it++)	// Альтернативная запись
			(*it)->ShowData();*/
		for (const auto& it : _clients) // Этот вариант работает быстрее
			it->ShowData();
	}

	void ShowClient(int index) {
		if (index > _clients.size())
			return;
		_clients.at(index - 1)->ShowData();
	}
};

int main() {
	// Task 1
	/*Person person1(30, "John Doe");
	person1.showAll();

	Pupil pupil1(18, "David Backham");
	pupil1.SetMarks();
	pupil1.showAll();

	Professor professor1("Albert Einstein", "PhD");
	professor1.showAll();*/

	// Task 2
	Bank* bank = new Bank(); 
	Client* client1 = new Client("Bob", 20, 324353544);
	Client* client2 = new Client("Alex",25, 324345544);
	Client* client3 = new Client("Monika", 40, 56567544);

	bank->AddClient(client1);
	bank->AddClient(client2);
	bank->AddClient(client3);

	bank->ShowClients();
	bank->ShowClient(2);

	return 0;
}