cmake_minimum_required(VERSION 2.8)
project(sorga_example)

# Specify the header folder
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Include the file_lib library
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/libraries/file_lib)

# Add cpp source files
file(GLOB SOURCES "src/*.cpp" "src/*/*.cpp")

# Adding executable
add_executable(sorga_example ${SOURCES})

# Adding linkling to the file_lib library
target_link_libraries(sorga_example file_lib)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/doc/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    # create command "make doc"
    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

enable_testing()

# Parameter check
add_test(help_check ${CMAKE_CURRENT_BINARY_DIR}/sorga_example -h)
set_tests_properties(help_check PROPERTIES PASS_REGULAR_EXPRESSION "Help")

# Testfile 1
add_test(test1 ${CMAKE_CURRENT_BINARY_DIR}/sorga_example ${CMAKE_CURRENT_SOURCE_DIR}/test/test1.test)
set_tests_properties(test1 PROPERTIES PASS_REGULAR_EXPRESSION "test1")

# Testfile 2
add_test(test2 ${CMAKE_CURRENT_BINARY_DIR}/sorga_example ${CMAKE_CURRENT_SOURCE_DIR}/test/test2.test)
set_tests_properties(test2 PROPERTIES PASS_REGULAR_EXPRESSION "testvalue")

# This is a loop through tests with the name *.testfile
# Compares output with reference (*.testfile.result) file
file (GLOB TESTS test/*.testfile)
foreach(fil ${TESTS})
  get_filename_component(nam ${fil} NAME_WE)
  set(args "-o ${fil}")
  add_test( ${nam}
     ${CMAKE_COMMAND}
     -D command=${CMAKE_CURRENT_BINARY_DIR}/sorga_example  
     -D args=${args}
     -D output=${fil}.out
     -D result=${fil}.result
     -P ${CMAKE_SOURCE_DIR}/test/compare.cmake
  )
endforeach()
