#include "Filme.h"

Filme::Filme() : Festival() {
}

Filme::Filme(string titlu, vector<string> actori, string loc, string data, int disponibil, int ocupat) : Festival(loc, data, disponibil, ocupat) {
	this->titlu = titlu;
	this->actori = actori;
}

Filme::Filme(const Filme& f) : Festival(f) {
	this->titlu = titlu;
	this->actori = f.actori;
}

Filme::~Filme() {
	this->actori.clear();
}

Festival* Filme::clona() {
	return new Filme(this->titlu, this->actori, this->loc, this->data, this->disponibil, this->ocupat);
}

string Filme::getTitlu() {
	return this->titlu;
}

vector<string> Filme::getActori() {
	return this->actori;
}

void Filme::setTitlu(string titlu) {
	this->titlu = titlu;
}

void Filme::setActori(vector<string> actori) {
	this->actori = actori;
}

Filme& Filme::operator=(const Filme& f) {
	Festival::operator=(f);
	this->titlu = f.titlu;
	this->actori = f.actori;
	return* this;
}

bool Filme::operator==(const Filme& f) {
	for (int i = 0; i < f.actori.size(); i++)
		if (this->actori[i] != f.actori[i])
			return false;
	return (Festival::operator==(f) && this->titlu == f.titlu);
}

string Filme::toString(string delim)
{
	string aux;
	for (int i = 0; i < this->actori.size(); i++)
	{
		aux.append(this->actori[i]);
		aux.append(";");
	}
	return "FI" + delim + Festival::toString(delim) + delim + this->titlu + delim + to_string(this->actori.size()) + delim + aux;
}
