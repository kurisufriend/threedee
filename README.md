# threedee
concept for an ininformed 3d render/engine

i was thinking one day and had an idea for making 3D. this might not be in a usable, or even recognizable, state at the time of reading, but i want to get this working at least a bit.

the idea is that you create a 3D cartesian coodinate space, create an "object/box" class that has accessible bounds and can be registered, then step set intervals in a direction for "raycasts" and inform each pixle of the screen by checking collision with the object registry.

you could alter the rendering so that the rays with longer distance are closer to the horizon (?), or change the pixle's color based on distance.
