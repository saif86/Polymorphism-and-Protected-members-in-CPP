/**
* @file Source.cpp
*
* @brief C++ Program to demostrate protected data members.
*
* @author Saif Ullah Ijaz
*
*/

// SYSTEM INCLUDES
#include <iostream> 
#include <string>
using namespace std;

// Painting class definition
class Painting {
public:
// LIFECYCLE
	/** Default + Overloaded constructor.
	*/
	Painting(const string& = "", const string& = "", int = 0);

	// Use compiler-generated copy constructor, assignment, and destructor.
	// Painting(const Painting&);
	// Painting& operator=(const Painting&);
	// ~Painting();

// OPERATIONS
	/** function that displays the Painting.
	*
	* @param void
	*
	* @return void
	*/
	void DisplayPainting()const;

// ACCESS
	// setters
	void SetTitle(const string& = "");
	void SetArtist(const string& = "");
	virtual void SetValue(int = 0);
	virtual void SetPainting(const string& = "", const string& = "", int = 0);
	/**
	# @overload void SetPainting(const Painting& aPainting);
	*/
	void SetPainting(const Painting& aPainting);

	// getters
	const string& GetTitle() const;
	const string& GetArtist() const;
	int GetValue() const;
	const Painting& GetPainting()const;

// DATA MEMBERS
protected:
	int mValue;
private:
	string mTitle;
	string mArtist;
};
// end class Painting

// FamousPainting class definition
class FamousPainting : public Painting{
public:
	// LIFECYCLE
	/** Default + Overloaded constructor.
	*/
	FamousPainting(const string& = "", const string& = "", int = 25000);

	// Use compiler-generated copy constructor, assignment, and destructor.
	// FamousPainting(const FamousPainting&);
	// FamousPainting& operator=(const FamousPainting&);
	// ~FamousPainting();

// ACCESS
	// setters
	void SetValue(int = 25000);
	void SetPainting(const string& = "", const string& = "", int = 25000);
	void SetFamousPainting(const string& = "", const string& = "", int = 25000);
	/**
	# @overload void SetFamousPainting(const FamousPainting& aFamousPainting);
	*/
	void SetFamousPainting(const FamousPainting& aFamousPainting);

	// getters
	const FamousPainting& GetFamousPainting()const;
};
// end class FamousPainting

// File scope starts here 

/////////////////////////////// PUBLIC ///////////////////////////////////////

//============================= LIFECYCLE ====================================

// Painting Default+Overloaded Constructor
Painting::Painting(const string& aTitle, const string& aArtist, int aValue) : mTitle(aTitle), mArtist(aArtist), mValue(aValue) {
	this->SetPainting(aTitle, aArtist, aValue);
}
// end Painting constructor 

// FamousPainting Default+Overloaded Constructor
FamousPainting::FamousPainting(const string& aTitle, const string& aArtist, int aValue) : Painting(aTitle, aArtist, aValue) {
	this->SetFamousPainting(aTitle, aArtist, aValue);
}
// end FamousPainting constructor 

//============================= OPERATIONS ===================================

// that displays the Painting.
void Painting::DisplayPainting() const {
	cout << "Painting Title: " << this->GetTitle()
		<< "\t Artist Name: " << this->GetArtist()
		<< "\t Value: $" << this->GetValue() << endl;
}
// end function DisplayPainting

//============================= ACESS      ===================================

// function that sets title of Painting
void Painting::SetTitle(const string& aTitle) {
	this->mTitle = aTitle;
}
// end function SetTitle

// function that sets artist of Painting
void Painting::SetArtist(const string& aArtist) {
	this->mArtist = aArtist;
}
// end function SetArtist

// function that sets value of Painting
void Painting::SetValue(int aValue) {
	if (aValue < 0)
		cout << "Value cannot be negative.";
	else
		this->mValue = aValue;
}
// end function SetValue

// function that sets the Painting
void Painting::SetPainting(const string& aTitle, const string& aArtist, int aValue) {
	this->SetTitle(aTitle);
	this->SetArtist(aArtist);
	this->SetValue(aValue);
}
// end function SetPainting

// overloaded function that sets the Painting
void Painting::SetPainting(const Painting &obj) {
	this->SetPainting(obj.GetTitle(), obj.GetArtist(), obj.GetValue());
}
// end function SetPainting

// function that gets the title of Painting
const string& Painting::GetTitle() const {
	return this->mTitle;
}
// end function GetTitle

// function that gets the artist of Painting
const string& Painting::GetArtist() const {
	return this->mArtist;
}
// end function GetArtist

// function that gets the value of Painting
int Painting::GetValue() const {
	return this->mValue;
}
// end function GetValue

// function that gets the Painting
const Painting& Painting::GetPainting()const {
	return *this;
}
// end function GetPainting

// function that sets value of FamousPainting
void FamousPainting::SetValue(int aValue) {
	if (aValue < 25000)
		cout << "Value cannot be set.";
	else
		Painting::SetValue(aValue);
}
// end function SetValue

// function that sets the Painting
void FamousPainting::SetPainting(const string& aTitle, const string& aArtist, int aValue) {
	if (aValue == 0)
		aValue = 25000;
	this->SetTitle(aTitle);
	this->SetArtist(aArtist);
	this->SetValue(aValue);
}
// end function SetPainting

// function that sets the FamousPainting
void FamousPainting::SetFamousPainting(const string& aTitle, const string& aArtist, int aValue) {
	this->SetTitle(aTitle);
	this->SetArtist(aArtist);
	this->SetValue(aValue);
}
// end function SetFamousPainting

// overloaded function that sets the Painting
void FamousPainting::SetFamousPainting(const FamousPainting &obj) {
	this->SetFamousPainting(obj.GetTitle(), obj.GetArtist(), obj.GetValue());
}
// end function SetFamousPainting

// function that gets the FamousPainting
const FamousPainting& FamousPainting::GetFamousPainting()const {
	return *this;
}
// end function FamousPainting

/////////////////////////////// MAIN   ///////////////////////////////////////

// function main begins program execution
void main() {
	string title;
	string name;
	Painting *obj[10];
	for (int i = 0; i<10; i++) {
		cout << "Enter Title Of Painting: ";
		getline(cin, title);

		cout << "Enter Name Of Artist: ";
		getline(cin, name);

		if (name == "degas" || name == "monet" || name == "picasso" || name == "rembrandt" || name == "Degas" || name == "Monet" || name == "Picasso" || name == "Rembrandt") 
			obj[i] = new FamousPainting;
		else 
			obj[i] = new Painting;
		obj[i]->SetPainting(title, name);
	}

	for (int i = 0; i<10; i++) 
		obj[i]->DisplayPainting();

	system("pause");
}
// end main
