# minishell

> Thanks to Minishell, we were able to travel through time and come back to problems people faced when Windows didn’t exist.

Thanks [mvomiero](https://github.com/mvomiero) for the collaboration on this project!


[Screencast Demo minishell](https://github.com/flo-12/minishell/assets/119588327/59e5489c-9a3c-47ae-a1b3-5745d6375108)



## Learning goals
- Lexer / Parser / Executor
- structuring a project
- how is a shell set-up and how does it exactly work
- exit status and different concepts put to action
- And of course **how to collaborate** on a project and split workload in an efficient way!

Core features of our shell are:

- **_as simple as it is: the same as bash :-P_**
- search and launch executables (with relative and absolute path)
- working history
- handle quotes and $ (dollar sign)
- redirections (<, >, <<, >>)
- pipes
- environment variables
- `ctrl-C`, `ctrl-D` and `ctrl-\`
- builtins such as echo, cd, pwd, export, unset, env, exit
_Sure, it's not a full-grown shell, but pretty close. So please bare some abstractions in the implementation._

Allowed external functions / libraries:
- readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history, printf, malloc, free, write, access, open, read, close, fork, wait, waitpid, wait3, wait4, signal, sigaction, sigemptyset, sigaddset, kill, exit, getcwd, chdir, stat, lstat, fstat, unlink, execve, dup, dup2, pipe, opendir, readdir, closedir, strerror, perror, isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
- Libft - own library with basic functions such as calloc, strncpm, etc. (see submodule)

_As usual: All heap allocated memory space must be properly freed. No leaks
will be tolerated._

# Usage
*Note that the program is written with Linux. Other operating systems were not tested.*

## Installing and Compiling
1) Clone the repository and its submodule by ``` git clone --recursive <project SSH/URL> ```
2) direct to the cloned folder ```cd <folder_name>```
3) ```make``` (automatically compiles the Libft)

## Execution
_no arguments..._
* Example: `./minishell`




# Sources
Realizing this project requires a deeper understanding of the shell and the method of lexer/parser/executor. The following list is a recommendation of sources for anyone who wants to know more about the topic:
| Topic								| Link                                                        	|
|----------------------------------:|:--------------------------------------------------------------|
| Official Bash Reference Manual (!!!) | [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html) |
| Knowldge base and useful links | [LinkTree Minishell](https://haglobah.github.io/Mastering-42/holy_graph/minishell.html) |
| Writing Your Own Shell (extract from book) | [2014 Gustavo Rodriguez-Rivera and Justin Ennen,Introduction to Systems Programming: a Hands-on Approach](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf) |
| Shell Command Language | [IEEE Std 1003.1, 2004 Edition](https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html) |
| Overview from a 42 student | [MiniShell](https://minishell.simple.ink/) |
| detailed explenation of Unix-like OS | [MIT xv6: a simple, Unix-like teaching operating system](https://pdos.csail.mit.edu/6.S081/2020/xv6/book-riscv-rev1.pdf) |
| Tutorial: Write a Shell in C | [Stephen Brennan Blog](https://brennan.io/2015/01/16/write-a-shell-in-c/) |
| Tutorial on minishell | [zakaria oukaddour](https://medium.com/@peannut/minishell-65d9a7de5ba0) |
| List of possible Tests | [google.docs with tests](https://docs.google.com/spreadsheets/d/1TDwyd-S0WBAXehgkrKQtBJ6zquQ4p6k7JfE5g3jICNA/edit#gid=0) |

