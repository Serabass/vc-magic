#include "Gang.h"

ViceGang::ViceGang(int id) {
	this->id = id;
}

ViceGang* ViceGang::Get(int id) {
	return new ViceGang(id);
}
