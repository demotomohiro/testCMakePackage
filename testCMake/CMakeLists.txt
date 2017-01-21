cmake_minimum_required(VERSION 3.0)

project(testlib VERSION 1.1)

include(GenerateExportHeader)
function(export_library target)
    set_property(TARGET ${target} PROPERTY CXX_VISIBILITY_PRESET hidden)
    set_property(TARGET ${target} PROPERTY VISIBILITY_INLINES_HIDDEN 1)
    generate_export_header(${target})
    target_include_directories(
        ${target} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
    )
    install(TARGETS ${target} EXPORT ${PROJECT_NAME}Config
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
        )
    install(FILES
        ${target}.hpp ${CMAKE_CURRENT_BINARY_DIR}/$<LOWER_CASE:${target}>_export.h
        DESTINATION include)
endfunction()

add_subdirectory(src)
add_subdirectory(tests)
