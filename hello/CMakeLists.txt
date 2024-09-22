project(hello)
aux_source_directory(. HAS_CXX)
add_executable(hello ${HAS_CXX})
