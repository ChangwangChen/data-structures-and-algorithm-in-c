#List测试
add_executable(List_Test list_test.c)
target_link_libraries(List_Test DS_LIB_LIST)

#Stack测试
add_executable(List_Stack_Test list_stack_test.c)
target_link_libraries(List_Stack_Test DS_LIB_LIST_STACK)

#Stack测试
add_executable(Array_Stack_Test array_stack_test.c)
target_link_libraries(Array_Stack_Test DS_LIB_ARRAY_STACK)

#Queue测试
add_executable(Array_Queue_Test array_queue_test.c)
target_link_libraries(Array_Queue_Test DS_LIB_ARRAY_QUEUE)

#Queue测试
add_executable(List_Queue_Test list_queue_test.c)
target_link_libraries(List_Queue_Test DS_LIB_LIST_QUEUE)

#Queue测试
add_executable(Big_Number_Sum big_number_sum_test.c)
target_link_libraries(Big_Number_Sum DS_LIB_LIST_STACK DS_LIB_LIST_QUEUE)