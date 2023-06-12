# 0. Subject & Guide Link
-> put link to subject file here
-> put giode link here

# 1. What is minishell?
-> put description of an assigment here

# 2. How to compile and execute the program?
-> compiation guide here

# 3. Which are the allowed external functions?
`open(<filename>, <flags>, <mode>)` - Opens a file or creates a new one and returns its file descriptor.
`close(<file descriptor>)` - Closes a file.
`read(<file descriptor>, <buffer>, <count>)` - Reads data from a file.
`write(<file descriptor>, <buffer>, <count>)` - Writes data to a file.
`unlink(<filename>)` - Deletes a file

`fork()` - Creates a new process.
`wait(<status>)` - Waits for any child process to exit.
`wait3(<status>, <options>, <rusage>)` - Waits for child processes to exit.
`wait4(<pid>, <status>, <options>, <rusage>)` - Waits for a specific child process to exit.
`waitpid(<pid>, <status>, <options>)` - Waits for a specific child process to exit.

`dup(<file descriptor>)` - Duplicates a file descriptor.
`dup2(<file descriptor>, <new file descriptor number>)` - Duplicates a file descriptor to a specific number.
`pipe(<file descriptors array>)` - Creates a pipe for interprocess communication.
`execve(<filename>, <arguments>, <environment>)` - Executes a program.

`opendir(<directory>)` - Opens a directory for reading.
`closedir(<directory>)` - Closes a directory.
`readdir(<directory>)` - Reads the next entry from a directory.
`getcwd(<buffer>, <size>)` - Gets the current working directory.
`chdir(<path>)` - Changes the current working directory.
`isatty(<file descriptor>)` - Checks if a file descriptor refers to a terminal.
`ttyname(<file descriptor>)` - Gets the name of the terminal associated with a file descriptor.
`ttyslot()` - Gets the slot number of the current terminal.
`ioctl(<file descriptor>, <request>, <arguments>)` - Performs various control operations on a file descriptor.
`fstat(<file descriptor>, <stat structure>)` - Gets file information for a specific file descriptor.

`stat(<path>, <stat structure>)` - Gets file information.
`lstat(<path>, <stat structure>)` - Gets file information (does not follow symbolic links).

`errno` - Returns the error number.
`perror(<error message>)` - Prints an error message to stderr based on the error number.
`strerror(<error number>)` - Returns a string describing the error number.
`exit(<status>)` - Exits the program with a status code.

`printf(<format>, <arguments>)` - Prints formatted output to stdout.

`malloc(<size>)` - Allocates memory dynamically.
`free(<pointer>)` - Frees dynamically allocated memory.

`getenv(<variable name>)` - Gets the value of an environment variable.

`kill(<pid>, <signal>)` - Sends a signal to a process.
`signal(<signal>, <handler>)` - Sets a signal handler for a specific signal.
`sigaction(<signal>, <action>, <old action>)` - Sets the action to be associated with a specific signal.
`sigemptyset(<signal set>)` - Initializes an empty signal set.
`sigaddset(<signal set>, <signal>)` - Adds a specific signal to a signal set.

`tcgetattr(<file descriptor>, <termios>)` - Gets the terminal attributes.
`tcsetattr(<file descriptor>, <optional actions>, <termios>)` - Sets the terminal attributes.
`tgetent(<buffer>, <terminal>)` - Initializes the terminal capabilities database.
`tgetflag(<capability>)` - Checks if a terminal capability is supported.
`tgetnum(<capability>)` - Gets the numeric value of a terminal capability.
`tgetstr(<capability>, <buffer>)` - Gets the string value of a terminal capability.

`tgoto(<capability>, <col>, <row>)` - Generates a cursor movement string for a terminal capability.
`tputs(<string>, <lines>, <output function>)` - Outputs a string to the terminal.

`readline(<prompt>)` - Reads a line of input from the user.
`rl_on_new_line()` - Notifies the readline library that a new line has been displayed.
`rl_replace_line(<line>)` - Replaces the current input line with a new line.
`rl_redisplay()` - Redraws the current input line.
`add_history(<line>)` - Adds a line to the readline history.

# 4. Features
-> put features here