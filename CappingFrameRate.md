# Capping Frame Rate
Suppose I want to set a fixed frame rate of 30 frames per second. This means that in 1 second, 30 frames should pass. We want to _cap_ the frame rate to 30. In other words we want to have it such that 1 frame takes 1/30 seconds to complete.

So we can set the constant frame rate to be **FPS = 30**, and then set the **FRAME_TARGET_TIME = 1/FPS** as done in constants.h. So the idea is that the update function (which gets called every iteration of the game loop) should 'waste time' until the **FRAME_TARGET_TIME** has passed, before executing the main body of the update.


