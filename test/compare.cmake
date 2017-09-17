separate_arguments( args )

file(REMOVE ${output})

execute_process(
   COMMAND ${command} ${args}
   COMMAND ${CMAKE_COMMAND} -E compare_files ${output} ${result}
   RESULT_VARIABLE test_not_successful
)

if( test_not_successful )
   message( SEND_ERROR "${output} does not match ${result}!" )
endif( test_not_successful )
