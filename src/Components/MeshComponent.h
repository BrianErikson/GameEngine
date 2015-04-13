#ifndef COMPONENTS_MESHCOMPONENT_H_
#define COMPONENTS_MESHCOMPONENT_H_

#include "ActorComponent.h"
#include "../Utilities/Mesh.h"
#include <Eigen>

using Eigen::Transform;

class MeshComponent : public ActorComponent {
	private:
		Mesh* mesh;
		Transform<float, 3, Eigen::Affine> transform;
	public:
		MeshComponent();
		MeshComponent(Mesh* mesh, float scale);
		virtual void render(const double &deltaTime) override;
};

#endif // COMPONENTS_MESHCOMPONENT_H_