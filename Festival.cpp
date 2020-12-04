#include "Festival.h"
#include "Util.h"

using namespace std;

Festival::Festival() {
	this->disponibil = 0;
	this->ocupat = 0;
}

Festival::Festival(string loc, string data, int disponibil, int ocupat){
	this->loc = loc;
	this->data = data;
	this->disponibil = disponibil;
	this->ocupat = ocupat;
}

Festival::Festival(const Festival& f){
	this->loc = f.loc;
	this->data = f.data;
	this->disponibil = f.disponibil;
	this->ocupat = f.ocupat;
}

Festival::~Festival() {
	this->disponibil = 0;
	this->ocupat = 0;
}

Festival* Festival::clona()
{
	return new Festival(this->loc, this->data, this->disponibil, this->ocupat);
}

string Festival::getLoc() {
	return this->loc;
}

string Festival::getData() {
	return this->data;
}

int Festival::getDisponibil() {
	return this->disponibil;
}

int Festival::getOcupat() {
	return this->ocupat;
}

void Festival::setLoc(string loc) {
	this->loc = loc;
}

void Festival::setData(string data) {
	this->data = data;
}

void Festival::setDisponibil(int disponibil) {
	this->disponibil = disponibil;
}

void Festival::setOcupat(int ocupat) {
	this->ocupat = ocupat;
}

Festival& Festival::operator=(const Festival& f) {
	this->loc = f.loc;
	this->data = f.data;
	this->disponibil = f.disponibil;
	this->ocupat = f.ocupat;
	return*this;
}
bool Festival::operator==(const Festival& f) {
	return (this->loc == f.loc && this->data == f.data && this->disponibil == f.disponibil && this->ocupat == f.ocupat);
}

string Festival::toString(string delim)
{
	return this->loc + delim + this->data + delim + convertIntToString(this->disponibil) + delim + convertIntToString(this->ocupat);
}
