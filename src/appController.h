#pragma once

class appController {
public:
	appController() = default;
	~appController() = default;

	void update();
	bool isTerminated();
	void terminate();
private:
	bool terminated = false;
};