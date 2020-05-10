set( MODULE_NAME 05_processes)
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BIN_DIR}/${MODULE_NAME})

add_executable(forkdemo forkdemo.c)
add_executable(exitstatusdemo exit_status_demo.c)
add_executable(tinyshell tinyshell.c)
add_executable(pipedemo pipedemo.c)
add_executable(pipedemo2 pipedemo2.c)