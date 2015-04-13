
#include "MeshComponent.h"

MeshComponent::MeshComponent() {
	this->type = EActorComponent::MESH;
	this->transform = Eigen::Transform<float, 3, Eigen::Affine>();
}

MeshComponent::MeshComponent(Mesh* mesh, float scale) {
	this->mesh = mesh;
	this->transform = Eigen::Transform<float, 3, Eigen::Affine>();
	this->transform.scale(1);
}

void MeshComponent::render(const double &deltaTime) {
	this->mesh->render(deltaTime);
}