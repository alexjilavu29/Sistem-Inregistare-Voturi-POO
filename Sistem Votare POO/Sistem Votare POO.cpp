#include <iostream>
#include <istream>
#include <string>
#include <vector>
using namespace std;

//Programul dat are un Partid general de tip Clasa
//abstracta care mosteneste o clasa ce afiseaza si citeste de la consola prin incarcarea operatorului "SI"

//Poiectul utilizeaza concepte de OOP:

//-mostenire: pe baza clasei abstracte Partid se creaza diferite tipuri de Partide

//-abstractizare

//-toate clasele au constructori parametrizati si destructori

//- se folosesc metode virtuale ce sunt suprascrise

//- incarcarea operatorilor input si output

//------------------------------------------------------------------------------------------------

class Citire { //clasa de citire de la consola prin incarcarea operatorului ">>" prin care se citeste informatia
	friend istream& operator>>(istream& is, const Citire& obiect);
public:
	virtual void citire(istream& is) const = 0;
	virtual ~Citire() = default;
};
// reda de la consola a unui obiect instantiat din clasa Citire
istream& operator>>(istream& cit, const Citire& membru) {
	membru.citire(cit);
	return cit;
}
class Afisare {//clasa de afisare - este o clasa ce are metode virtuale si incarcarea operatorului "<<" prin care se printeaza informatii
	friend ostream& operator<<(ostream& afis, const Afisare& obiect);
public:
	virtual void afisare(ostream& afis) const = 0;
	virtual ~Afisare() = default;
};
//reda informatii despre obiectul instantiat cu clasa Afisare
ostream& operator<<(ostream& afis, const Afisare& membru) {
	afis.precision(2);
	afis << fixed;
	membru.afisare(afis);
	return afis;
}



class Partid : public Afisare {
private://grupare constante
	static constexpr const char* nume_partid = "Partid nedefinit";
	static constexpr int numar_voturi_initial = 0;
protected:
	int numar_voturi;
public:
	Partid() = default; //constructor fara parametrii
	Partid(string nume = nume_partid, int numar_voturi = numar_voturi_initial); //constructor parametrizat
	//Metode virtuale pentru a utiliza polimorfismul
	virtual bool adaugare_voturi(int voturi) = 0; //functie virtuala
	virtual void citire(istream& cit) const; //functie virtuala
	virtual void afisare(ostream& afis) const override;
	virtual ~Partid() = default; //destructor virtual
	string nume;
};
//Implementarea constructor Partid
Partid::Partid(string nume, int numar_voturi)
	:nume{ nume }, numar_voturi{ numar_voturi } {}
// metoda de adaugare a voturilor in Partid
bool Partid::adaugare_voturi(int voturi) {
	if (voturi < 0)
		return false;
	else {
		numar_voturi += voturi;
		return true;
	}
}

//supraîncarcarea operatorului adunare(test)

class Adunare {
private:
	int variabila;
public:
	void afiseaza() /// metodă pentru afișarea fractiei
	{
		cout << variabila << endl;
	}
	Adunare(int a = 0) /// constructor
	{
		variabila = a;
	}
	Adunare operator+ (Adunare nr)
	{
		Adunare R;
		R.variabila = variabila + nr.variabila;
		return R;
	}
	Adunare operator+ (int n)
	{
		Adunare R;
		R.variabila = variabila + n;
		return R;
	}
	friend Adunare operator + (int n, Adunare nr)
	{
		Adunare R;
		R.variabila = nr.variabila + n;
		return R;
	}
};
//Metoda de afisare Partid: nume, numar_voturi
void Partid::afisare(ostream& afis) const {
	afis.precision(2);
	afis << fixed;
	afis << "[Partid " << nume << ": " << numar_voturi << " ]";
}
//Metoda de citire de la consola a denumirii Partidului
void Partid::citire(istream& cit) const {
	string nume_partid;
	cout << "Introduceti numele Partidului: " << endl;
	cit >> nume_partid;
}

class Partid_definit1 : public Partid {  // Se mosteneste clasa Partid definita mai sus
private:    // Se introduc variabilele private
	static constexpr const char* nume_partid = "Partid 1 nedefinit";    // Se ofera o valoare de inceput pentru numele partidului
	static constexpr int numar_voturi_initial = 0;    // Se ofera o valoare de inceput pentru numarul de voturi din partid
public:     // Se introduc variabilele publice
	Partid_definit1(string nume = nume_partid, int numar_voturi = numar_voturi_initial);    // Constructor
	virtual bool adaugare_voturi(int voturi) override;  // Se va folosi functia de adaugare_voturi
	virtual void citire(istream& cit) const override;   // Se va folosi functia de citire
	virtual void afisare(ostream& afis) const override; // Se va folosi functia de scriere
	virtual ~Partid_definit1() = default; // destructor virtual
};

//Metoda de implementare a constructorului
Partid_definit1::Partid_definit1(string nume, int numar_voturi) // Se apeleaza constructorul clasei Partid
	:Partid{ nume,numar_voturi } {
}

//Metoda de adaugare a voturilor in Partid
bool Partid_definit1::adaugare_voturi(int voturi) {
	return Partid::adaugare_voturi(double(voturi));
}
//Metoda de afisare date Partid curent: nume si numar_voturi
void Partid_definit1::afisare(ostream& afis) const {
	afis.precision(2);
	afis << fixed;
	float nr_max = 35000;
	float nr = (int)(numar_voturi);
	float procentaj;
	procentaj = (nr * 100) / nr_max;
	afis << "Partid 1- " << nume << ": " << numar_voturi << " voturi" << " - Procentaj 1 = ";
	cout << procentaj << "%";
}
//Metoda de citire de la consola
void Partid_definit1::citire(istream& cit) const {
	string nume_partid;
	cout << "Introduceti nume Partid: " << endl;
	cit >> nume_partid;
}


class Partid_definit2 : public Partid {  // Se mosteneste clasa Partid definita mai sus
private:    // Se introduc variabilele private
	static constexpr const char* nume_partid = "Partid 2 nedefinit";    // Se ofera o valoare de inceput pentru numele partidului
	static constexpr int numar_voturi_initial = 0;    // Se ofera o valoare de inceput pentru numarul de voturi din partid
public: // Se introduc variabilele publice
	Partid_definit2(string nume = nume_partid, int numar_voturi = numar_voturi_initial);    // Constructor
	virtual bool adaugare_voturi(int voturi) override;  // Se va folosi functia de adaugare_voturi
	virtual void citire(istream& cit) const override;   // Se va folosi functia de citire
	virtual void afisare(ostream& afis) const override; // Se va folosi functia de scriere
	virtual ~Partid_definit2() = default; // destructor virtual
};

//Metoda de implementare a constructorului
Partid_definit2::Partid_definit2(string nume, int numar_voturi) // Se apeleaza constructorul clasei Partid
	:Partid{ nume,numar_voturi } {
}

//Metoda de adaugare a voturilor in Partid
bool Partid_definit2::adaugare_voturi(int voturi) {
	return Partid::adaugare_voturi(double(voturi));
}
//Metoda de afisare date Partid curent: nume si numar_voturi
void Partid_definit2::afisare(ostream& afis) const {
	afis.precision(2);
	afis << fixed;
	float nr_max = 35000;
	float nr = (int)(numar_voturi);
	float procentaj;
	procentaj = (nr * 100) / nr_max;
	afis << "Partid 2- " << nume << ": " << numar_voturi << " voturi" << " - Procentaj 2 = ";
	cout << procentaj << "%";
}
//Metoda de citire de la consola
void Partid_definit2::citire(istream& cit) const {
	string nume_partid;
	cout << "Introduceti nume Partid: " << endl;
	cit >> nume_partid;
}



class Partid_definit3 : public Partid {  // Se mosteneste clasa Partid definita mai sus
private:     // Se introduc variabilele private
	static constexpr const char* nume_partid = "Partid 3 nedefinit";    // Se ofera o valoare de inceput pentru numele partidului
	static constexpr int numar_voturi_initial = 0;    // Se ofera o valoare de inceput pentru numarul de voturi din partid
public: // Se introduc variabilele publice
	Partid_definit3(string nume = nume_partid, int numar_voturi = numar_voturi_initial);    // Constructor
	virtual bool adaugare_voturi(int voturi) override;  // Se va folosi functia de adaugare_voturi
	virtual void citire(istream& cit) const override;   // Se va folosi functia de citire
	virtual void afisare(ostream& afis) const override;  // Se va folosi functia de scriere
	virtual ~Partid_definit3() = default; // destructor virtual
};

//Metoda de implementare a constructorului
Partid_definit3::Partid_definit3(string nume, int numar_voturi) // Se apeleaza constructorul clasei Partid
	:Partid{ nume,numar_voturi } {
}

//Metoda de adaugare a voturilor in Partid
bool Partid_definit3::adaugare_voturi(int voturi) {
	return Partid::adaugare_voturi(double(voturi));
}
//Metoda de afisare date Partid curent: nume si numar_voturi
void Partid_definit3::afisare(ostream& afis) const {
	afis.precision(2);
	afis << fixed;
	float nr_max = 35000;
	float nr = (int)(numar_voturi);
	float procentaj;
	procentaj = (nr * 100) / nr_max;
	afis << "Partid 3- " << nume << ": " << numar_voturi << " voturi" << " - Procentaj 3 = ";
	cout << procentaj << "%";
}
//Metoda de citire de la consola
void Partid_definit3::citire(istream& cit) const {
	string nume_partid;
	cout << "Introduceti nume Partid: " << endl;
	cit >> nume_partid;
}


void afisare2(const vector<Partid*>& Partide); // Se defineste functia de afisare a vectorului de Partide
void adaugare_voturi(std::vector<Partid*>& Partide, int numar_voturi); // Se defineste functia de adaugare_voturi pentru vectorul de Partide


void afisare2(const vector<Partid*>& Partide) {
	cout << "\n ------------ Partide --------------" << endl;   // Header pentru afisare
	for (const auto* Partid : Partide) {
		cout << *Partid << endl; // Foloseste supraincarcarea operatorului de insertie
	}
	cout << "Introduceti nume de Partid: " << endl;
	string nume_partid;
	cin >> nume_partid;   // Se obtine numele partidului de la tastatura
	for (const auto Partid : Partide) {
		if (Partid->nume == nume_partid) {
			cout << Partid->nume << ":" << endl << "Detalii despre " << *Partid << endl;   // Se afiseaza detaliile despre fiecare dintre cei 3 termeni ai vectorului
		}
	}
}

void adaugare_voturi(vector<Partid*>& Partide, int voturi) {
	cout << "\n _________Numarul de voturi pentru fiecare partid (+2000)___________" << endl;   // Header pentru adaugare_voturi
	for (auto* Partid : Partide)
		if (Partid->adaugare_voturi(voturi))
			cout << "Numarul de voturi pentru " << *Partid << "." << endl;

}

int main()
{
	Adunare a(1), b(5);    // Se declara cei doi termeni ai adunarii
	Adunare R = a + b;  // Se apeleaza operatorul de adunare (testare pe doua variabile distince)
	R.afiseaza();   // Se afiseaza rezultatul
	R = a + 2;        // Se apeleaza operatorul de adunare (testare pe o variabila in partea stanga a operatorului)
	R.afiseaza();
	R = 2 + b;        // Se apeleaza operatorul de adunare (testare pe o variabila in partea dreapta a operatorului)
	R.afiseaza();
	Partid* p1 = new Partid_definit1("PSD", 10000);   // Se defineste primul partid
	Partid* p2 = new Partid_definit2("PNL", 20000);    // Se defineste al doilea partid
	Partid* p3 = new Partid_definit3("USR", 5000);     // Se defineste al treilea partid
	vector<Partid*> Partide{ p1,p2,p3 }; // Se introduc valorile definite intr-un vector cu trei elemente
	afisare2(Partide);  // Se afiseaza vectorul obtinut
	adaugare_voturi(Partide, 2000); // Se adauga 2000 de voturi la fiecare partid si se afiseaza din nou
	delete p1, p2, p3;    // Se sterg pointerii
	return 0;
}
