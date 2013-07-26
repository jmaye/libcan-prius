remake_find_package(tulibs CONFIG)
remake_find_package(libcan CONFIG)

remake_include(${TULIBS_INCLUDE_DIRS})
remake_include(${LIBCAN_INCLUDE_DIRS})

remake_add_library(com LINK base ${TULIBS_LIBRARIES} ${LIBCAN_LIBRARIES})
remake_add_headers(INSTALL com)
