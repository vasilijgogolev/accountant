#include "appController.h"

void appController::update() {

}

bool appController::isTerminated() {
	return terminated;
}

void appController::terminate() {
	terminated = true;
}