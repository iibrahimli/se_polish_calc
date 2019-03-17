project(polish_calc_test)

add_executable(tests main.cpp)
target_link_libraries(tests cppunit)

add_test(NAME "all" COMMAND "tests")