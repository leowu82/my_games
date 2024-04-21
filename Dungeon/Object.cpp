#include "Object.h"

Object::Object() {}

Object::Object(string nameVal, string tagVal): name(nameVal), tag(tagVal) {}

Object::~Object() {}

//setter
void Object::setName(string nameVal) {
    name = nameVal;
}

void Object::setTag(string tagVal) {
    tag = tagVal;
}

//getter
string Object::getName() {
    return name;
}

string Object::getTag() {
    return tag;
}
