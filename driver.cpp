#include"bst.h"

int main() {

	bst tree;
	char command = 'n';
	do {
		cout << "Commands\tKey\ni\t\tinsert\ns\t\tsize\np\t\tprint\ne\t\terase\nc\t\tclear tree\nf\t\tfind\n1\t\tpre-order\n2\t\tpost-order\n3\t\tin-order\n";
		cout << "enter one of the commands: ";
		cin >> command;
		if (command == 'i') {
			int number;
			cout << "\nenter number: ";

			cin >> number;
			cout << endl << endl;
			tree.insert(number);
		}
		else if (command == 'e') {
			int number;
			cout << "\nenter number: ";

			cin >> number;
			cout << endl << endl;
			tree.erase(number);
		}
		else if (command == 'f') {
			int number;
			cout << "\nenter number: ";
			cout << endl << endl;
			cin >> number;
			bool found = tree.find(number);
			if (found) {
				cout << number << " is a node in the tree\n";
			}
			else {
				cout << number << " is not a node in the tree\n";
			}
		}
		else if (command == '1') {
			cout << endl << endl;
			tree.pre();
			cout << endl << endl;
			cout << endl;
		}
		else if (command == '2') {
			cout << endl << endl;
			tree.post();
			cout << endl << endl;
			cout << endl;
		}
		else if (command == '3') {
			cout << endl << endl;
			tree.in();
			cout << endl << endl;
			cout << endl;
		}
		else if (command == 'p') {
			cout << endl << endl;
			tree.print();
			cout << endl << endl;
			cout << endl;
		}
		else if (command == 'c') {
			cout << endl << endl;
			tree.clear();
			cout << endl << endl;
			cout << endl;
		}
		else if (command == 's') {
			cout << endl << endl;
			cout << "Tree has " << tree.size() <<" nodes.\n";
			cout << endl << endl;
		}
		else if (command == 'q') {
			cout << endl << endl;
			cout << "\nTerminating Avl Tree\n";
			cout << endl << endl;
		}
		else {
			cout << endl << endl;
			cout << endl << command << " is not valid try again\n\n";

		}
	} while (command != 'q');
}
