set( MODULE_NAME 07_signals)
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BIN_DIR}/${MODULE_NAME})

add_executable(termdemo termdemo.c)
add_executable(simple-handler simple-handler.c)