# Capping Frame Rate
Suppose I want to set a fixed frame rate of 30 frames per second. This means that in 1 second, 30 frames should pass. We want to *cap* the frame rate to 30. In other words we want to have it such that 1 frame takes 1/30 seconds to complete.

So we can set the constant frame rate to be **FPS = 30**, and then set the **FRAME_TARGET_TIME = 1/FPS** as done in constants.h. So the idea is that the update function (which gets called every iteration of the game loop) should 'waste time' until the **FRAME_TARGET_TIME** has passed, before executing the main body of the update.

# Delta Time
I dont want to think about speed in the units of **pixels per frame**. We would rather think about pixels per second. That is how the player/user will think. So for example, we might want a ball to move 30 pixels in one second.

We need a **delta_time** factor to allow us to move away from pixels per frame to pixels per second.
We can define this factor as:
    delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f

This translates the difference between current time and last recorded time; we divide by 1000 to convert from milliseconds to seconds. 

If I wanted to move a ball 20 pixels every frame, every update call I would do:
`ball.x += 20`
However if I wanted a ball to move 20 pixels every *second*, every update call I would do:
`ball.x += 20 * delta_time`

The delta time factor scales the value of 20 down to the appropriate value so that when a second does pass, the the ball would have moved by 20 pixels.

If we think of the general formula distance = speed x time, we can let speed = 20 px / second and delta_time be the amount of time that has passed since our last update. Therefore, the  product is the appropriate distance that the ball should travel given the speed and the amount of time passed.

By using delta_time, the "wasting time" procedure outlined in the **Capping Frame Rate** section does not seem necessary.

