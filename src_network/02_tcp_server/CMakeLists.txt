set( MODULE_NAME 02_tcp_server)
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BIN_DIR}/network/${MODULE_NAME})

add_executable(rot13d rot13d.c)