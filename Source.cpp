#include<iostream>
#include<string>

using namespace std;

class Painting{
	string title;
	string artist;
protected:
	int value;
public:

	Painting(int = 0);		// default + overloaded constructor 
	
	void set_data(string, string);
	void display();

};

Painting::Painting(int x) :value(400) { }

void Painting::set_data(string t, string a){
	title = t;
	artist = a;
}
void Painting::display(){
	cout << "Painting Title: " << title 
	<< "\t Artist Name: " << artist
	<< "\t Value: $" << value << endl;
}

class FamousPainting :public Painting{

public:
	FamousPainting() {
		value = 25000;
	}
};

int main(){
	string title;
	string name;
	Painting *obj[10];
	for (int i = 0; i<10; i++){
		cout << "Enter Title Of Painting: "; 
		getline(cin, title);

		cout << "Enter Name Of Artist: "; 
		getline(cin, name);

		if (name == "degas" || name == "monet" || name == "picasso" || name == "rembrandt" || name == "Degas" || name == "Monet" || name == "Picasso" || name == "Rembrandt"){
			obj[i] = new FamousPainting;
		}
		else{
			obj[i] = new Painting;
		}
		obj[i]->set_data(title, name);

	}

	for (int i = 0; i<10; i++){
		obj[i]->display();
	}
	system("pause");
}