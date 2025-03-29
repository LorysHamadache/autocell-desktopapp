# AutoCell — Cellular Automata Simulator

**AutoCell** is a C++ desktop application designed for creating, simulating, and visualizing various **cellular automata**. Built with **Qt 5.10.1**, it offers a customizable environment to explore and analyze different automaton behaviors.

---

## Features

- **Multiple Automata Support**: Implement and test various cellular automata, including classic models like Conway's Game of Life and custom-defined rules.
- **Interactive Grid Editor**: Design initial states using an intuitive grid interface, allowing precise configuration of cell patterns.
- **Simulation Control**: Run simulations step-by-step or continuously, with adjustable speed settings to observe automaton evolution.
- **Customizable Parameters**: Modify rules, grid sizes, and simulation parameters to experiment with different automaton dynamics.
- **Save and Load Configurations**: Preserve automata configurations and states for future analysis or sharing.

---

## Repository Structure

- `forms/`: Contains Qt Designer `.ui` files defining the graphical user interface components.
- `headers/`: Header files (`.h`) declaring classes, functions, and data structures used in the application.
- `sources/`: Source files (`.cpp`) implementing the core functionality and logic of the application.
- `AutoCell.pro`: Qt project file used to manage project settings and build configurations.
- `main.cpp`: Entry point of the application, initializing and launching the main interface.
- `README.md`: This documentation file providing an overview of the project.

---

## Getting Started

### Prerequisites

- **Qt 5.10.1**: Ensure you have Qt 5.10.1 installed. You can download it from the [Qt official website](https://www.qt.io/download).
- **C++ Compiler**: A C++17 compatible compiler is required.

### Building the Application

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/LorysHamadache/autocell-desktopapp.git
   cd autocell-desktopapp
   ```

2. **Open the Project in Qt Creator**:

   - Launch Qt Creator.
   - Open the `AutoCell.pro` file located in the cloned repository.

3. **Configure the Project**:

   - Set up the appropriate kit matching your development environment.
   - Configure build settings as needed.

4. **Build and Run**:

   - Click the build button to compile the project.
   - Run the application directly from Qt Creator.

---

## Usage

- **Designing Automata**: Use the interactive grid to set initial cell states.
- **Configuring Rules**: Access the settings panel to define or modify automaton rules.
- **Running Simulations**: Start, pause, or step through simulations using the control buttons.
- **Saving/Loading**: Utilize the file menu to save current configurations or load existing ones.

---

## Contributing

Contributions to enhance AutoCell are welcome. Please fork the repository and submit a pull request with your proposed changes.

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.

---

## Contact

For questions or suggestions, please open an issue in the repository or contact the maintainer at [LorysHamadache](https://github.com/LorysHamadache).

---

*Note: This project is provided "as-is" without warranty of any kind. Use at your own discretion.*
