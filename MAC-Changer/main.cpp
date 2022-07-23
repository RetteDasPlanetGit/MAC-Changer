/*
* Copyright (C) 2016 SaEeD
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*
* Description:  Generate Random MAC address for Network Adapters.
*/

#include <iostream>
#include <limits>
#include "MyMACAddr.h"



//-----------------------------------------------
//Main Menu
void Menu() {

	cout << "Bitte w�hlen Sie eine der folgenden Optionen:\n" <<
		"\t1)Nur zuf�llige MAC-Adresse generieren.\n" <<
		"\t2)Details zu Netzwerkadaptern anzeigen.\n" <<
		"\t3)Zuweisung einer zuf�lligen MAC-Adresse zur Netzwerkschnittstelle.\n" <<
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