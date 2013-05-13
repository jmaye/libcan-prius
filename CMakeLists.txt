cmake_minimum_required(VERSION 2.6)

include(ReMake)

remake_project(
  libcan-prius
  VERSION 1.0
  RELEASE beta
  SUMMARY "A C++ based Toyota PRIUS CAN interfacing library"
  AUTHOR "Jerome Maye"
  CONTACT "jerome.maye@mavt.ethz.ch"
  HOME "https://github.com/jmaye/libcan-prius"
  LICENSE "GNU Lesser General Public License (LGPL)"
  PREFIX can-prius-
  INSTALL /usr/
  EXTRA_CXX_FLAGS -std=c++0x
)

remake_doc(
  html
  latex
)

remake_pack_deb(
  DESCRIPTION "Main library"
  DEPENDS libcan
)

remake_pack_deb(
  COMPONENT dev
  DESCRIPTION "Development headers"
  DEPENDS libcan-prius
)

remake_pack_deb(
  COMPONENT console-tools
  DESCRIPTION "Console tools"
  DEPENDS libcan-prius
)

remake_pack_deb(
  COMPONENT gui-tools
  DESCRIPTION "GUI tools"
  DEPENDS libcan-prius libqtgui4
)

remake_pack_deb(
  COMPONENT gui-tools-dev
  DESCRIPTION "GUI tools development headers"
  DEPENDS libcan-prius-dev libcan-prius-gui-tools libqt4-dev
)

remake_pack_deb(
  COMPONENT doc
  DESCRIPTION "Documentation"
  DEPENDS libcan-prius
)

remake_distribute_deb(
  DISTRIBUTION lucid
  SECTION libs
  UPLOAD ppa:jmaye/ethz
  DEPENDS remake doxygen libcan-dev libqt4-dev pkg-config
  PASS CMAKE_BUILD_TYPE LIBVELODYNE_GIT_REVISION
)

remake_distribute_deb(
  DISTRIBUTION precise
  SECTION libs
  UPLOAD ppa:jmaye/ethz
  DEPENDS remake doxygen libcan-dev libqt4-dev pkg-config
  PASS CMAKE_BUILD_TYPE LIBVELODYNE_GIT_REVISION
)
