Flappy Bird Clone
This project is a clone of the popular Flappy Bird game, implemented in C using the SDL2 library.
Project Structure
Copy
```bash
├── Makefile
├── assets
│   ├── flappy-bird.png
│   └── pipe.png
├── build
│   ├── bin
│   │   └── flappy_bird_main
│   └── obj
│       ├── display
│       │   └── display.o
│       ├── game
│       │   ├── bird
│       │   │   └── bird.o
│       │   ├── game.o
│       │   └── pipe
│       │       └── pipe.o
│       ├── main
│       │   └── main.o
│       └── renderer
│           └── renderer.o
├── doc
├── include
│   ├── SDL2 -> /opt/homebrew/Cellar/sdl2/2.30.6/include/SDL2
│   └── SDL_image -> /opt/homebrew/Cellar/sdl2_image/2.8.2_1/include/SDL2
├── lib
│   └── SDL2_image -> /opt/homebrew/Cellar/sdl2_image/2.8.2_1/lib
├── src
│   ├── display
│   │   ├── display.c
│   │   └── display.h
│   ├── game
│   │   ├── bird
│   │   │   ├── bird.c
│   │   │   └── bird.h
│   │   ├── game.c
│   │   ├── game.h
│   │   └── pipe
│   │       ├── pipe.c
│   │       └── pipe.h
│   ├── main
│   │   └── main.c
│   └── renderer
│       ├── renderer.c
│       └── renderer.h
└── tools
```

## Prerequisites

- SDL2 library
- SDL2_image library

## Building the Project

To build the project, simply run:
make
Copy
This will compile the source files and create the executable in the `build/bin` directory.

## Running the Game

After building, you can run the game with:
./build/bin/flappy_bird_main
Copy
## Project Components

- `display`: Handles the game display
- `game`: Contains the main game logic
  - `bird`: Implements the bird's behavior
  - `pipe`: Implements the pipe obstacles
- `renderer`: Handles rendering of game objects
- `main`: Contains the main entry point of the application

## Assets

The game uses two image assets:
- `flappy-bird.png`: The sprite for the bird
- `pipe.png`: The sprite for the pipes

These are located in the `assets` directory.

## Development

To add new features or modify the game:

1. Add or modify source files in the appropriate directories under `src/`
2. Update the Makefile if you've added new source files
3. Rebuild the project using `make`

## License

None

## Contributing

Me

## Acknowledgements

This project uses the SDL2 library, which can be found at https://www.libsdl.org/
