LINUX_VERSION = "5.16"

SRCREV = "72a99af79ec9df296356f4b0ee95328cb10befb2"

include linux-socfpga.inc

LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

FILESEXTRAPATHS:prepend := "${THISDIR}/config:"

SRC_URI:append:cyclone5 = " file://lbdaf.scc "
SRC_URI:append:arria5 = " file://lbdaf.scc "
SRC_URI:append:arria10 = " file://lbdaf.scc "
