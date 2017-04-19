#List测试
add_executable(List_Test list_test.c)
target_link_libraries(List_Test DS_LIB_LIST)

#Stack测试
add_executable(Stack_Test list_stack_test.c)
target_link_libraries(Stack_Test DS_LIB_STACK)