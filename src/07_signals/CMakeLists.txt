set( MODULE_NAME 07_signals)
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BIN_DIR}/${MODULE_NAME})

add_executable(termdemo termdemo.c)
add_executable(simple-handler simple-handler.c)
add_executable(sigactiondemo sigactiondemo.c)
add_executable(timeout timeout.c)
add_executable(periodic periodic.c)