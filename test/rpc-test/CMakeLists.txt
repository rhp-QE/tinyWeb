set(
        muduo_lib
        muduo_protorpc
        muduo_protobuf_codec
        muduo_protorpc_wire
        muduo_net muduo_base
        protobuf
)

add_executable(serve serve.cc test.pb.cc)
target_link_libraries(serve  ${muduo_lib})



add_executable(client client.cc test.pb.cc)
target_link_libraries(client  ${muduo_lib})
