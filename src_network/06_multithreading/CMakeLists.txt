set( MODULE_NAME 06_multithreading)
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BIN_DIR}/network/${MODULE_NAME})

find_package(Threads)

add_executable(thread_demo thread_demo.c)
target_link_libraries (thread_demo ${CMAKE_THREAD_LIBS_INIT})

add_executable(no_mutex_demo no_mutex_demo.c)
target_link_libraries(no_mutex_demo ${CMAKE_THREAD_LIBS_INIT})

add_executable(mutex_demo mutex_demo.c)
target_link_libraries(mutex_demo ${CMAKE_THREAD_LIBS_INIT})