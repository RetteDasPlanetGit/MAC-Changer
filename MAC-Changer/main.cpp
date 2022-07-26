#include <iostream>
#include <limits>
#include "MyMACAddr.h"



//-----------------------------------------------
//Main Menu
void Menu() {

	cout << "Bitte wählen Sie eine der folgenden Optionen:\n" <<
		"\t1)Nur zufällige MAC-Adresse generieren.\n" <<
		"\t2)Details zu Netzwerkadaptern anzeigen.\n" <<
		"\t3)Zuweisung einer zufälligen MAC-Adresse zur Netzwerkschnittstelle.\n" <<
		"\t4)Netzwerkschnittstellen Zusammenfassung.\n"
		"\t5)Verlassen.\n\nAuswahl: ";

}
//-----------------------------------------------
// Short Summary of network interfaces
void AdaptersSummary(MyMACAddr &ptr)
{
	unordered_map<string, string> list = ptr.getAdapters();
	for (auto &itm : list)
	{
		cout << "Name: " << itm.first << "\t\tMAC Address: " << itm.second << endl;
	}
}


int main(int argc, char **argv)
{
	cout <<"\t===========================\n"
		<< "\t|   MAC Address Changer   |\n"
		<< "\t| coded by RettedasPlanet |\n"
		<< "\t===========================\n" << endl;

	//-----------------------------------------------
	//Initializing  the MAC address class
	MyMACAddr *ptr = new MyMACAddr();

	while (true)
	{
		Menu();

		//-----------------------------------------------
		// Input validation
		int selection = 0;
		cin >> selection;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cerr << "[!]Invalid Selection Input!" << endl;
			continue;
		}
		//-----------------------------------------------

		//-----------------------------------------------
		// Menu selection
		switch (selection)
		{
		case 1:
			cout << "\n[+]Generated Random MAC Address:\t" << ptr->GenRandMAC() << "\n" << endl;;
			break;
		case 2:
			cout << "----------- Details: -----------" << endl;
			ptr->showAdapterList();
			cout << "-------------  End  ------------\n" << endl;
			break;
		case 3:
			ptr->AssingRndMAC();
			break;
		case 4:
			cout << "----------- Details: -----------" << endl;
			AdaptersSummary(*ptr);
			cout << "-------------  End  ------------\n" << endl;
			break;
		case 5:
			return EXIT_SUCCESS;
		default:
			cout << "[!]Invalid Selection. Try again!" << endl;
			break;
		}
	}		

	return EXIT_SUCCESS;
}
