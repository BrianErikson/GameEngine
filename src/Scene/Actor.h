#ifndef SCENE_ACTOR_H_
#define SCENE_ACTOR_H_

#include "GL\glew.h"
#include <vector>
#include "../Components/ActorComponent.h"

class Actor {
	private:
		std::vector<ActorComponent*> components;
	protected:
		Actor();
	public:
		virtual void tick(const double &deltaTime);
		virtual void render(const double &deltaTime);

		virtual void addComponent(ActorComponent component);
		virtual bool removeComponentsOfType(EActorComponent type);

		virtual std::vector<ActorComponent*>& getComponents();
		virtual ActorComponent* getComponentByType(EActorComponent &type);
};

#endif // SCENE_ACTOR_H_