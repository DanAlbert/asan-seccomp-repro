cmake_minimum_required(VERSION 3.4.1)

find_library(LIB_LOG log)

add_library(app SHARED app.cpp)
target_compile_options(app PUBLIC -fsanitize=address)
set_target_properties(app PROPERTIES LINK_FLAGS -fsanitize=address)
target_link_libraries(app ${LIB_LOG})