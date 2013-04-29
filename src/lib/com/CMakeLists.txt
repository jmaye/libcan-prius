remake_find_library(tulibs-config config.h PACKAGE tulibs)
remake_find_library(can can.h PACKAGE libcan)
remake_find_library(can-cpc can.h PACKAGE libcan)

remake_include(${CAN_CPC_HEADERS} ${TULIBS_CONFIG_HEADERS})

remake_add_library(com LINK base ${CAN_LIBRARY} ${CAN_CPC_LIBRARY}
  ${TULIBS_CONFIG_LIBRARY})
remake_add_headers(INSTALL com)
