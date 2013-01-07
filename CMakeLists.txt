cmake_minimum_required(VERSION 2.6)

include(ReMake)

remake_set(CMAKE_CXX_FLAGS -std=c++0x CACHE FORCE INIT)

remake_project(
  libcan-prius
  VERSION 1.0
  RELEASE beta
  SUMMARY "A C++ based Toyota PRIUS CAN interfacing library"
  AUTHOR "Jerome Maye"
  CONTACT "jerome.maye@mavt.ethz.ch"
  HOME "http://aslforge.ethz.ch/projects/libcan-prius"
  LICENSE "GNU Lesser General Public License (LGPL)"
  PREFIX can-prius-
  INSTALL /usr/
)

remake_doc(
  html
  latex
)

remake_pack_deb(
  DESCRIPTION "Main library"
)

remake_pack_deb(
  COMPONENT dev
  DESCRIPTION "Development headers"
  libcan-prius
)

remake_pack_deb(
  COMPONENT console-tools
  DESCRIPTION "Console tools"
  libcan-prius
)

remake_pack_deb(
  COMPONENT gui-tools
  DESCRIPTION "GUI tools"
  libcan-prius
  libqtgui4
)

remake_pack_deb(
  COMPONENT doc
  DESCRIPTION "Documentation"
  libcan-prius
)
