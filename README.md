The Maze
Welcome to The Maze! This is a 3D Maze game that utilizes ray casting to render a 2D map into a 3D navigable world.

About The Maze
The Maze was written in C using the SDL2 library. Development was performed on Ubuntu 14.04 LTS with gcc (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4.

About SDL2
Simple DirectMedia Layer (SDL2) is a cross-platform development library designed to provide low-level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D.

![flowchart](https://github.com/FreeFelix/Portfolio-/assets/96358673/08bcd09c-920b-4460-97ad-318ab39a6e40)


Background Context
The goal of this project is to create a game in 3D using raycasting. The tasks involved in achieving this goal are outlined below. Have fun while working on this project!

Requirements
General
All files will be compiled on Ubuntu 14.04 LTS using gcc with flags -Wall -Werror -Wextra and -pedantic.
Use Betty style for coding standards.
Do not push object files, temporary files, or any unused source files.
Organize your repository clearly, separating sources and headers.
Utilize SDL2 functions for graphics and input handling.
Tasks
Walls!

Create a window with SDL2.
Use raycasting to draw walls on the window.
Allow for changing the camera angle.
Differentiate wall color from ground/ceiling.
Orientation
![Maze flowchart Preview](https://photos.app.goo.gl/RjQieqwzu6XfHy4q6)


Draw walls facing different directions in distinct colors.
Rotation

Implement camera rotation during execution (e.g., arrow keys or mouse movement).
Move

Enable camera movement during execution (e.g., WASD keys).
Ouch!

Handle player collisions with walls.
Parser
![Maze diagram](https://photos.app.goo.gl/Yj1mVnQLamTa98MJA)

Implement a parser to read the map from a file.
Draw the map

Draw the map on the window.
Include the player's line of sight in the map.
Textures

Add textures to walls.
Multi-task!

Handle multiple events simultaneously (e.g., moving and rotating).
Ground Textures

Add textures to the ground and/or ceiling.
Weapons

Incorporate weapon textures.
Enemies

Introduce enemies into the game.
Make it rain

Add rain effects with the option to start/stop with a key.
Extra Option

Implement additional features such as shadows or special lighting.
Tips and Links
SDL2 tutorials and documentation.
Utilize the provided raycasting tutorial.
Be careful with online tutorials; ensure they are for SDL2 and not SDL-1.2.
Installation
Ensure SDL2 is installed on your system. Follow the instructions in SDL2 - Get started.pdf to set up SDL2.

Usage
Compile the source files using gcc with the provided flags. Run the executable with the necessary parameters, such as the path to the map file.

Contributing
Feel free to contribute to The Maze by submitting pull requests.
