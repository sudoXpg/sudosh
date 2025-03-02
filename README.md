# sudosh - A Simple Unix Shell

sudosh is a minimal Unix shell written in C. It supports basic command execution, built-in commands, and an interactive prompt.

## Features

### Basic Features
- Command Execution: Run external commands using `execvp`.
- Built-in Commands: Supports `cd`, `help`, and `exit`.
- Interactive Prompt: Displays a `>` prompt for user input.

### Planned Features
- Command History: Store executed commands for easy recall.
- Autocompletion: Use `readline` for tab-based autocompletion.
- Piping (`|`): Support command chaining like `ls | grep .c`.
- I/O Redirection (`<`, `>`): Redirect input and output streams.
- Background Execution (`&`): Allow running processes in the background.
- Signal Handling: Handle `Ctrl+C` (SIGINT) and `Ctrl+Z` (SIGTSTP).

## Installation

```sh
git clone https://github.com/sudoXpg/sudosh.git
cd sudosh
make
```

## Usage

Compile and Run the shell:
```sh
gcc sudosh.c -o sudosh
./sudosh
```

Available built-in commands:
- `cd <dir>`: Change directory
- `help`: Display available commands
- `exit`: Exit the shell

## Code Structure

- `sudosh.h` - Header file containing function prototypes
- `sudosh.c` - Core shell implementation

## Contributing
Contributions are welcome! Feel free to submit a pull request or suggest new features.

## License
This project is licensed under the [MIT License](LICENSE).
