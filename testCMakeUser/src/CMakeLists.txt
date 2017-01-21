find_package(testlib 1.0 CONFIG REQUIRED testComp testComp3dep2)
add_executable(testUser testUser.cpp)
target_link_libraries(testUser testlib::testComp testlib::testComp3dep2)
