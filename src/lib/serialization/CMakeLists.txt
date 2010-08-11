remake_include(../exceptions ../com types)
remake_add_library(serialization types/*.cpp *.cpp LINK exceptions)
remake_add_headers(types/*.h *.h INSTALL .)
