#List测试
add_executable(List_Test list_test.c)
target_link_libraries(List_Test DS_LIB_LIST)

#Stack测试
add_executable(List_Stack_Test list_stack_test.c)
target_link_libraries(List_Stack_Test DS_LIB_LIST_STACK)

#Stack测试
add_executable(Array_Stack_Test array_stack_test.c)
target_link_libraries(Array_Stack_Test DS_LIB_ARRAY_STACK)