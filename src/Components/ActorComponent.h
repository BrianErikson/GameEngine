#ifndef COMPONENTS_ACTORCOMPONENT_H_
#define COMPONENTS_ACTORCOMPONENT_H_

enum EActorComponent {
	MESH,
	MOVEMENT
};

class ActorComponent {
	protected:
		EActorComponent type;
		ActorComponent();
	public:
		virtual EActorComponent getComponentType();
		virtual void tick(const double &deltaTime);
		virtual void render(const double &deltaTime);
};

#endif //COMPONENTS_ACTORCOMPONENT_H_