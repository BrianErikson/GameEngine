
#include "Actor.h"

Actor::Actor() {

}

Actor::~Actor() {
}

void Actor::tick(const double &deltaTime) {
	for (int i = 0; i < this->components.size(); i++) {
		this->components[i]->tick(deltaTime);
	}
}

void Actor::render(const double &deltaTime) {
	for (int i = 0; i < this->components.size(); i++) {
		this->components[i]->render(deltaTime);
	}
}

void Actor::addComponent(ActorComponent* component) {
	this->components.push_back(component);
}

/** Returns true if removal was successful
*/
bool Actor::removeComponentsOfType(EActorComponent type) {
	for (std::vector<ActorComponent*>::iterator iter = this->components.begin(); iter < this->components.end();) {
		if (type == (*iter)->getComponentType()) {
			this->components.erase(iter);
			return true;
		}
	}
	return false;
}

std::vector<ActorComponent*>* Actor::getComponents() {
	return &this->components;
}

ActorComponent* Actor::getComponentByType(EActorComponent type) {
	for (int i = 0; i < this->components.size(); i++) {
		if (type == this->components[i]->getComponentType()) {
			return this->components[i];
		}
	}
	return nullptr;
}