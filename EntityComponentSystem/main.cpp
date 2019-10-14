#include "HealthComponent.h"
#include "PositionComponent.h"
#include "ControlSystem.h"
#include "RenderSystem.h"

int main() {
	Entity player;
	HealthComponent healthComponent; 
	PositionComponent positionComponent;
	player.addComponent(healthComponent);
	player.addComponent(positionComponent);

	ControlSystem controlSystem;
	RenderSystem renderSystem;
	controlSystem.addEntity(player);
	renderSystem.addEntity(player);

	while (true) {
		controlSystem.update();
		renderSystem.update();
	}

	return 0;
}