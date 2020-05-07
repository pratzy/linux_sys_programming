set( MODULE_NAME 02_files_io)
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BIN_DIR}/${MODULE_NAME})

add_executable(copy copy.c)
add_executable(seekdemo seekdemo.c)