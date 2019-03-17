project(polish_calc_test)

add_executable(tests main.cpp)
target_link_libraries(tests cppunit)

add_test(NAME "cppunit" COMMAND "tests")

add_test(NAME "test1" COMMAND "bash" "test1.sh")
add_test(NAME "test2" COMMAND "bash" "test2.sh")