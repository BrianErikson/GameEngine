
#include "MeshComponent.h"

MeshComponent::MeshComponent() {
	this->type = EActorComponent::MESH;
	this->scale = Matrix();
}

MeshComponent::MeshComponent(Mesh* mesh, float scale) {
	this->mesh = mesh;
	this->scale = Matrix();
	this->scale *= scale;
}

void MeshComponent::render(const double &deltaTime) {
	this->mesh->render(deltaTime);
}