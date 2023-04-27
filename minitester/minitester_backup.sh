print_h2 "BASIC EXECUTION TESTS"
#################################### BASIC EXEC
test_exec_basic
#################################### PIPES
test_pipes

print_h2 "PARSING & SYNTAX TESTS"
#################################### SPACES
test_spaces
#################################### QUOTES
test_syntax_quotes
#################################### SYNTAX ERRORS
test_syntax_errors

print_h2 "BUILTIN TESTS"
#################################### ECHO
test_builtin_echo
#################################### ENV
test_builtin_env
#################################### EXPORT
test_builtin_export
#################################### UNSET
test_builtin_unset
#################################### PWD
test_builtin_pwd
#################################### CD
test_builtin_cd
#################################### EXIT
test_builtin_exit

print_h2 "VARIABLE EXPANSION TESTS"
#################################### VARIABLE EXPANSION
test_variable_expansion


print_h2 "REDIRECTION TESTS"
#################################### INFILES
test_redir_infile
#################################### OUTFILES TRUNC
test_redir_outfile_trunc
#################################### OUTFILES APPEND
test_redir_outfile_append
#################################### FILES
test_redir_all


print_h2 "EXIT STATUS TESTS"
#################################### EXIT STATUS
test_exit_status