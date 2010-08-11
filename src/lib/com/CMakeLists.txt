remake_find_library(
  tulibs-config config.h
  PACKAGE tulibs
)
remake_find_library(
  can-cpc can.h
  PACKAGE libcan
)
remake_include(../exceptions ../serialization ../serialization/types)
remake_add_library(com LINK exceptions serialization ${CAN_CPC_LIBRARY} ${TULIBS_CONFIG_LIBRARY})
remake_add_headers()
