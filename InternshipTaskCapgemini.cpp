// InternshipTaskCapgemini.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include<map>
#include <vector>
#include <algorithm>
#pragma comment(lib, "windowscodecs.lib")
using namespace std;
bool comp(const pair<float, int>& a, const pair<float, int>& b) {
	return a.second < b.second;
}

class Phone
{
public:
	string brand_name;
	string model_name;
	string form_factor;
	int year_of_issue;
	float screen_size;
	float price;
	Phone();
	Phone(string brand_name, std::string model_name, std::string form_factor, int year_of_issue, float screen_size, float price)
		 {
		this->brand_name = brand_name;
		this->model_name = model_name;
		this->form_factor = form_factor;
		this->year_of_issue = year_of_issue;
		this->screen_size = screen_size;
		this->price = price;
	}
	void get_info() {
		cout << "Brand: " << this->brand_name << endl;
		cout << "Model: " << this->model_name << endl;
		cout << "Year of issue: " << this->year_of_issue<< endl;
		cout << "Screen size: " << this->screen_size << endl;
		cout << "Price: " << this->price << endl;
	}
	~Phone() {};



};

class Phone_shop {
public:
	Phone_shop() {
		map<int, Phone> ph;
		phones = ph;
	}
	void add_phone(const Phone& ph ) {
		
		//this->phones[this->phones.size() + 1] =  ph;
		phones.insert(pair<int, Phone>(phones.size()+1, ph));
		
	}
	void add_phone(string brand_name, std::string model_name, std::string form_factor, int year_of_issue, float screen_size, float price) {
		Phone p(brand_name, model_name, form_factor, year_of_issue, screen_size, price);
		phones[phones.size() + 1] = p;
	}
	void delete_phone(int id) {
		phones.erase(id);
	}
	void get_all_phones() {
		for (auto item : phones) {
			cout << "Id: " << item.first << endl;
			item.second.get_info();
		}
	}
	void get_by_brand(string brand) {
		for (auto item : phones) {
			if (item.second.brand_name == brand) {
				item.second.get_info();
			}
		}
	}
	void get_by_form_and_screen(string form , float size) {
		for (auto item : phones) {
			if (item.second.form_factor == form && item.second.screen_size == size) {
				item.second.get_info();
			}
		}
	}
	void get_brand_by_quantity() {
		map<string, int> brands;
		int max_quantity = 0;
		string result;
		for (auto phone : phones) {
			++brands[phone.second.brand_name];
		}
		for (auto item : brands) {
			cout << "Brand " << item.first << " Quant: " << item.second << endl;
			if (item.second > max_quantity) {
				result = item.first;
				max_quantity = item.second;
			}
		}
		cout << "Most popular brand " << result<<endl;
	}
	void get_top_3_screensize() {
		map<float, int> screen_sizes;


		for (auto phone : phones) {
			++screen_sizes[phone.second.screen_size];
		}

		vector<std::pair<float, int>> sorted_ss(screen_sizes.begin(), screen_sizes.end());
		sort(sorted_ss.begin(), sorted_ss.end(),comp);
		int i = 1;
		for (auto const& element : sorted_ss) {
			if(i <=3)
			{
				cout << " Place " << i  << " Size: " << element.first << " Quantity " << element.second << endl;
				i++;
			}
			else { break; }

		}
		

	}
	~Phone_shop() {};
	map<int,Phone> phones;

};

int main()
{
	Phone_shop shop;
	Phone p1( "Apple", "iPhone 12", "Bar", 2020, 6.1, 999);
	Phone p3("Samsung", "Galaxy S21", "Bar", 2020, 6.2, 899);
	Phone p4("Xiaomi", "Mi 10", "Bar", 2020, 6.67, 499);

	string name = "Apple";
	string model = "Iphone";
	string form_factor = "Bar";
	int year_of_issue = 2020;
	float screen_size = 6.2;
	float price = 70.2;
	Phone p2(name, model, form_factor, year_of_issue, screen_size,price);
	shop.add_phone(p1);
	shop.add_phone(p2);
	shop.add_phone(p3);
	shop.add_phone(p4);
	shop.get_by_brand("Apple");
	cout << "--------------------------------------" << endl;
	shop.get_all_phones();
	cout << "--------------------------------------" << endl;
	shop.get_brand_by_quantity();
	cout << "--------------------------------------" << endl;
	shop.get_top_3_screensize();
	cout << "--------------------------------------" << endl;
	shop.get_by_form_and_screen("Bar", 6.2);
	cout << "--------------------------------------" << endl;
	shop.delete_phone(3);
	cout << "--------------------------------------" << endl;
	shop.get_all_phones();
	cout << "--------------------------------------" << endl;

	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
