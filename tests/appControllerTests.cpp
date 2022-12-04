#include "gtest/gtest.h"
#include "../src/appController.h"

TEST(appControllerTests, terminate) {
	appController controller;
	EXPECT_FALSE(controller.isTerminated());
	controller.terminate();
	EXPECT_TRUE(controller.isTerminated());
}