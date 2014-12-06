#ifndef COMPONENTS_ACTORCOMPONENT_H_
#define COMPONENTS_ACTORCOMPONENT_H_

class ActorComponent {
	protected:
		ActorComponent();
	public:
		virtual void Tick() = 0;
};

#endif //COMPONENTS_ACTORCOMPONENT_H_