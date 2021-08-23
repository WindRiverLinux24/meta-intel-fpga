LINUX_VERSION = "5.10.50"
LINUX_VERSION_SUFFIX = "-lts"

LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"

SRCREV = "9f6a15dd04cc89f780b2935cb8c44133d66527f0"

include linux-socfpga.inc

FILESEXTRAPATHS_prepend := "${THISDIR}/config:"

SRC_URI_append_n5x = " file://jffs2.scc file://gpio_sys.scc "
SRC_URI_append_agilex = " file://jffs2.scc file://gpio_sys.scc "
SRC_URI_append_stratix10 = " file://jffs2.scc file://gpio_sys.scc "
SRC_URI_append_arria10 = " file://lbdaf.scc "
SRC_URI_append_cyclone5 = " file://lbdaf.scc "
SRC_URI_append_arria5 = " file://lbdaf.scc "
