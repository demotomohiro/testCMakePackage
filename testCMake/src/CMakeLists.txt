add_library(testComp SHARED testComp.cpp)
add_library(testComp2 SHARED testComp2.cpp)
add_library(testComp3dep2 SHARED testComp3dep2.cpp)

target_link_libraries(testComp3dep2 PUBLIC testComp2)

export_library(testComp)
export_library(testComp2)
export_library(testComp3dep2)

set(version_config
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake)
set(config_dest lib/cmake/${PROJECT_NAME})

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${version_config}
    COMPATIBILITY SameMajorVersion)
install(FILES ${version_config} DESTINATION ${config_dest})

install(EXPORT ${PROJECT_NAME}Config DESTINATION ${config_dest}
    NAMESPACE ${PROJECT_NAME}::
    )

