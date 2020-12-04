#include "Muzica.h"


Muzica::Muzica() : Festival() {
}
 
Muzica::Muzica(string artist, string loc, string data, int disponibil, int ocupat) : Festival(loc, data, disponibil, ocupat) {
	this->artist = artist;
}

Muzica::Muzica(const Muzica& m) : Festival(m) {
	this->artist = m.artist;
}

Festival* Muzica::clona() {
	return new Muzica(this->artist, this->loc, this->data, this->disponibil, this->ocupat);
}
string Muzica::getArtist() {
	return this->artist;
}
void Muzica::setArtist(string artist) {
	this->artist = artist;
}
Muzica& Muzica::operator=(const Muzica& m) {
	Festival::operator=(m);
	this->artist = m.artist;
	return* this;
}
bool Muzica::operator==(const Muzica& m){
	return this->artist == m.artist && Festival::operator==(m);
}
string Muzica::toString(string delim)
{
	return "MU" + delim + Festival::toString(delim) + delim + this->artist;
}