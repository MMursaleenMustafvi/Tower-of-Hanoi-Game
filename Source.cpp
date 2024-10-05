#include<iostream>
#include<string>

using namespace std;

struct node {
	char data;
	node* next;
	node() {
		next = nullptr;
	}
};

class stack {
public:
	node* top;

	stack() {
		top = nullptr;
	}

	bool is_empty() {
		return top == nullptr;
	}

	void push(char c) {
		node* newnode = new node();
		newnode->data = c;
		if (is_empty()) {
			top = newnode;
			return;
		}
		newnode->next = top;
		top = newnode;
	}

	char peak() {
		if (is_empty()) {
			return ' ';
		}
		return top->data;
	}

	void pop() {
		if (is_empty()) {
			return;
		}
		node* temp = top;
		top = top->next;
		delete temp;
	}
};

void print(stack t1, stack t2, stack t3) {
	cout << "-------------------------" << endl;
	cout << "|   TOWER OF HANOI      |" << endl;
	cout << "-------------------------" << endl;

	stack obj1 = t1;
	stack obj2 = t2;
	stack obj3 = t3;
	int c = 0;
	int n = 3;

	while (c < n) {
		cout << "| " << obj1.peak() << " | " << obj2.peak() << " | " << obj3.peak() << " |" << endl;
		cout << "-------------------------" << endl;
		obj1.pop();
		obj2.pop();
		obj3.pop();
		c++;
	}

	cout << "| 1 | 2 | 3 |" << endl;
	cout << "-------------------------" << endl;
}

bool win(stack obj) {
	if (obj.peak() == 'A') {
		obj.pop();
		if (obj.peak() == 'B') {
			obj.pop();
			if (obj.peak() == 'C') {
				obj.pop();
				return true;
			}
		}
	}
	return false;
}

int main() {
	stack tower1, tower2, tower3;

	tower1.push('C');
	tower1.push('B');
	tower1.push('A');

	char c, d;
	bool wincheck;
	int count = 0;
	char choice = 'a';

	do {
		cout << "YOUR RECORD IS: " << count << endl;
		print(tower1, tower2, tower3);

		cout << "-------------------------" << endl;
		cout << "|         MOVES          |" << endl;
		cout << "-------------------------" << endl;
		cout << "|1. TOP DISK FROM 1 TO 2 |" << endl;
		cout << "|2. TOP DISK FROM 1 TO 3 |" << endl;
		cout << "|3. TOP DISK FROM 2 TO 1 |" << endl;
		cout << "|4. TOP DISK FROM 2 TO 3 |" << endl;
		cout << "|5. TOP DISK FROM 3 TO 1 |" << endl;
		cout << "|6. TOP DISK FROM 3 TO 2 |" << endl;
		cout << "|7.EXIT FROM GAME        |" << endl;
		cout << "-------------------------" << endl;

		cin >> choice;

		if (choice == '1') {
			c = tower1.peak();
			d = tower2.peak();
			if (!tower2.is_empty() && c > d) {
				cout << "YOU CANNOT MOVE A LARGER DISK ONTO A SMALLER ONE" << endl;
				count--;
			}
			else {
				tower1.pop();
				tower2.push(c);
			}
		}
		else if (choice == '2') {
			c = tower1.peak();
			d = tower3.peak();
			if (!tower3.is_empty() && c > d) {
				cout << "YOU CANNOT MOVE A LARGER DISK ONTO A SMALLER ONE" << endl;
				count--;
			}
			else {
				tower1.pop();
				tower3.push(c);
			}
		}
		else if (choice == '3') {
			c = tower2.peak();
			d = tower1.peak();
			if (!tower1.is_empty() && c > d) {
				cout << "YOU CANNOT MOVE A LARGER DISK ONTO A SMALLER ONE" << endl;
				count--;
			}
			else {
				tower2.pop();
				tower1.push(c);
			}
		}
		else if (choice == '4') {
			c = tower2.peak();
			d = tower3.peak();
			if (!tower3.is_empty() && c > d) {
				cout << "YOU CANNOT MOVE A LARGER DISK ONTO A SMALLER ONE" << endl;
				count--;
			}
			else {
				tower2.pop();
				tower3.push(c);
			}
		}
		else if (choice == '5') {
			c = tower3.peak();
			d = tower1.peak();
			if (!tower1.is_empty() && c > d) {
				cout << "YOU CANNOT MOVE A LARGER DISK ONTO A SMALLER ONE" << endl;
				count--;
			}
			else {
				tower3.pop();
				tower1.push(c);
			}
		}
		else if (choice == '6') {
			c = tower3.peak();
			d = tower2.peak();
			if (!tower2.is_empty() && c > d) {
				cout << "YOU CANNOT MOVE A LARGER DISK ONTO A SMALLER ONE" << endl;
				count--;
			}
			else {
				tower3.pop();
				tower2.push(c);
			}
		}
		else if (choice == '7')
		{
			cout << "YOU LOSE THE GAME!" << endl;
			break;
		}
		count++;
		wincheck = win(tower3);
	} while (!wincheck);

	cout << "CONGRATULATIONS, YOU DID IT IN " << count << " TURNS!" << endl;

	return 0;
}
