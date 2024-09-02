# Flappy Bird Clone

This project is a clone of the popular Flappy Bird game, implemented in C using the SDL2 library. It aims to recreate the addictive gameplay of the original while serving as a learning resource for game development with SDL2.

## Table of Contents

- [Project Structure](#project-structure)
- [Prerequisites](#prerequisites)
- [Building the Project](#building-the-project)
- [Running the Game](#running-the-game)
- [Project Components](#project-components)
- [Assets](#assets)
- [Development](#development)
- [License](#license)
- [Contributing](#contributing)
- [Acknowledgements](#acknowledgements)

## Project Structure

```
├── Makefile
├── assets
│   ├── flappy-bird.png
│   └── pipe.png
├── build
│   ├── bin
│   │   └── flappy_bird_main
│   └── obj
│       ├── display
│       ├── game
│       │   ├── bird
│       │   └── pipe
│       ├── main
│       └── renderer
├── doc
├── include
│   ├── SDL2 -> /opt/homebrew/Cellar/sdl2/2.30.6/include/SDL2
│   └── SDL_image -> /opt/homebrew/Cellar/sdl2_image/2.8.2_1/include/SDL2
├── lib
│   └── SDL2_image -> /opt/homebrew/Cellar/sdl2_image/2.8.2_1/lib
├── src
│   ├── display
│   ├── game
│   │   ├── bird
│   │   └── pipe
│   ├── main
│   └── renderer
└── tools
```

## Prerequisites

Before building and running the game, ensure you have the following libraries installed:

- **SDL2 library**
- **SDL2_image library**

You can install these libraries using your system's package manager or by following the instructions on the [SDL website](https://www.libsdl.org/).

## Building the Project

To build the project, follow these steps:

1. Open a terminal and navigate to the project root directory.
2. Run the following command:

```bash
make
```

This will compile the source files and create the executable in the `build/bin` directory.

## Running the Game

After successfully building the project, you can run the game using:

```bash
./build/bin/flappy_bird_main
```

## Project Components

The project is organized into several components:

- **`display`**: Handles the game display and window management.
- **`game`**: Contains the main game logic and state management.
  - **`bird`**: Implements the bird's behavior, physics, and collision detection.
  - **`pipe`**: Implements the pipe obstacles, including generation and movement.
- **`renderer`**: Handles rendering of game objects and the overall scene.
- **`main`**: Contains the main entry point of the application and game loop.

## Assets

The game uses two image assets:

- **`flappy-bird.png`**: The sprite for the bird character.
- **`pipe.png`**: The sprite for the pipe obstacles.

These assets are located in the `assets` directory.

## Development

To add new features or modify the game:

1. Add or modify source files in the appropriate directories under `src/`.
2. Update the `Makefile` if you've added new source files.
3. Rebuild the project using `make`.
4. Test your changes by running the game.

## License

This project is currently **not under any specific license**.

## Contributing

Contributions are welcome! If you'd like to contribute to this project, please follow these steps:

1. **Fork** the repository.
2. Create a **new branch** for your feature or bug fix.
3. Make your changes and commit them with **descriptive commit messages**.
4. **Push** your changes to your fork.
5. Submit a **pull request** with a clear description of your changes.

## Acknowledgements

This project uses the **SDL2 library**, which can be found at https://www.libsdl.org/. We are grateful to the SDL development team for providing this excellent library for game development.

