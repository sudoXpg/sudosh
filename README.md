# SudoSH - A Simple Shell

SudoSH is a simple shell implementation in C, providing basic command execution, built-in commands, and command history tracking.

## Features
- Custom shell prompt (`>`)
- Command execution using `execvp`
- Built-in commands:
  - `cd` (Change directory)
  - `help` (List available built-in commands)
  - `clear` (Clear the terminal screen)
  - `exit` (Exit the shell)
- Command history logging to `sudosh_history.hist`
- Dynamic memory allocation for command parsing

## Compilation and Execution
### Prerequisites
Ensure you have a C compiler installed, such as `gcc`.

### Build
```sh
gcc -o sudosh sudosh.c
```

### Run
```sh
./sudosh
```

## Code Overview
### Main Functions
- `sudosh()` - The main loop of the shell
- `sudosh_read_line()` - Reads input from the user
- `sudosh_split_line()` - Splits input into tokens
- `sudosh_execute()` - Executes commands
- `sudosh_launch()` - Launches external programs
- `save_history()` - Saves command history to a file

### Built-in Commands
- `sudosh_cd()` - Changes the current directory
- `sudosh_help()` - Displays help information
- `sudosh_clear()` - Clears the screen
- `sudosh_exit()` - Exits the shell

## Future Improvements
- Add support for piping and redirection
- Implement job control (background processes)
- Improve history handling (persistent history, `history` command)
- Autocomplete support using `readline`

## License
This project is open-source and free to use under the MIT License.



## Contributing
Contributions are welcome! Feel free to submit a pull request or suggest new features.

## License
This project is licensed under the [MIT License](LICENSE).
