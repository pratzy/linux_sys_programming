set( MODULE_NAME 03_managing_files)
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BIN_DIR}/${MODULE_NAME})

add_executable(statdemo statdemo.c)
add_executable(monitor monitor.c)