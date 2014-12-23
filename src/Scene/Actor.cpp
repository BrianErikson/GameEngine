
#include "Actor.h"

Actor::Actor() {

}

void Actor::tick(const double &deltaTime) {
	std::vector<ActorComponent*> components = this->getComponents();
	for (int i = 0; i < components.size(); i++) {
		ActorComponent* component = components[i];
		component->tick(deltaTime);
	}
}

void Actor::render(const double &deltaTime) {
	std::vector<ActorComponent*> components = this->getComponents();
	for (int i = 0; i < components.size(); i++) {
		ActorComponent* component = components[i];
		component->render(deltaTime);
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

std::vector<ActorComponent*>& Actor::getComponents() {
	return this->components;
}

ActorComponent* Actor::getComponentByType(EActorComponent &type) {
	for (int i = 0; i < this->components.size(); i++) {
		ActorComponent* component = this->components[i];
		if (type == component->getComponentType()) {
			return component;
		}
	}
	return nullptr;
}