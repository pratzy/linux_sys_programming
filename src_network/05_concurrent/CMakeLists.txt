set( MODULE_NAME 05_concurrent)
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BIN_DIR}/network/${MODULE_NAME})

add_executable(hangman_server hangman_server.c)