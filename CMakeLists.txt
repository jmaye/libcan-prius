cmake_minimum_required(VERSION 2.6)

include(ReMake)

remake_project(
  libcan-prius
  VERSION 0.1
  RELEASE alpha
  SUMMARY "Toyota PRIUS CAN Driver"
  AUTHOR "Jerome Maye"
  CONTACT "jerome.maye@mavt.ethz.ch"
  HOME "http://aslforge.ethz.ch/projects/libcan-prius"
  LICENSE "GNU Lesser General Public License (LGPL)"
  PREFIX can-prius-
  INSTALL /usr/
)

remake_doc(
  html
)

remake_pack_deb(
  DESCRIPTION "Main library"
  libcan
  tulibs
)

remake_pack_deb(
  COMPONENT dev
  DESCRIPTION "Development headers"
)

remake_pack_deb(
  COMPONENT test
  DESCRIPTION "Test programs"
  libcan-prius
)

remake_pack_deb(
  COMPONENT doc
  DESCRIPTION "Documentation"
)
