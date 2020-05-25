set( MODULE_NAME 03_tcp_client)
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BIN_DIR}/network/${MODULE_NAME})

add_executable(rot13client1 rot13client1.c)