DESCRIPTION = "ARM Trusted Firmware"

LICENSE = "BSD-3-Clause"
LIC_FILES_CHKSUM ?= "file://docs/license.rst;md5=189505435dbcdcc8caa63c46fe93fa89"

PROVIDES = "arm-trusted-firmware"

DEPENDS = "u-boot-tools"

inherit deploy

PACKAGE_ARCH = "${MACHINE_ARCH}"

ATF_PROT ?= "https"
ATF_BRANCH ?= "socfpga_v2.3"
ATF_REPO ?= "git://github.com/altera-opensource/arm-trusted-firmware.git"

SRC_URI = "${ATF_REPO};protocol=${ATF_PROT};branch=${ATF_BRANCH}"

S = "${WORKDIR}/git"

COMPATIBLE_MACHINE = "(agilex5_dk_a5e065bb32aes1|agilex5_dk_a5e013bb32aesi0|agilex5_modular|agilex5_mudv_cvr|agilex5_mucv|agilex7_dk_si_agf014ea|agilex7_dk_si_agf014eb|agilex7_dk_si_agi027fb|agilex7_dk_si_agi027fa|agilex7_dk_si_agi027fc|agilex7_dk_dev_agf027f1es|agilex7_dk_dev_agm039fes|agilex5|stratix10|stratix10_htile|n5x)"
ATFPLAT = "${MACHINE}"
ATFPLAT:agilex5_dk_a5e065bb32aes1 = "agilex5"
ATFPLAT:agilex5_dk_a5e013bb32aesi0 = "agilex5"
ATFPLAT:agilex5_modular = "agilex5"
ATFPLAT:agilex5_mudv_cvr = "agilex5"
ATFPLAT:agilex5_mucv = "agilex5"
ATFPLAT:agilex7_dk_si_agf014ea = "agilex"
ATFPLAT:agilex7_dk_si_agf014eb = "agilex"
ATFPLAT:agilex7_dk_si_agi027fb = "agilex"
ATFPLAT:agilex7_dk_si_agi027fa = "agilex"
ATFPLAT:agilex7_dk_si_agi027fc = "agilex"
ATFPLAT:agilex7_dk_dev_agf027f1es = "agilex"
ATFPLAT:agilex7_dk_dev_agm039fes = "agilex"
ATFPLAT:stratix10_htile = "stratix10"

LDFLAGS="--no-warn-rwx-segments"
CFLAGS="-Wno-error=array-bounds"

# Let the Makefile handle setting up the CFLAGS and LDFLAGS as it is a standalone application
EXTRA_OEMAKE = 'CROSS_COMPILE="${TARGET_PREFIX}" PLAT="${ATFPLAT}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" DEPRECATED=1'
# CFLAGS[unexport] = "1"
# LDFLAGS[unexport] = "1"
AS[unexport] = "1"
LD[unexport] = "1"
PARALLEL_MAKE = ""

ALLOW_EMPTY:${PN} = "1"

do_configure[noexec] = "1"

do_compile() {
	oe_runmake -C ${S} bl31
}

do_deploy() {
	install -d ${DEPLOYDIR}
	install -m 0644 ${S}/build/${ATFPLAT}/release/bl31.bin ${DEPLOYDIR}/bl31.bin-${MACHINE}-${PV}-${PR}
	ln -sf bl31.bin-${MACHINE}-${PV}-${PR} ${DEPLOYDIR}/bl31.bin
}

addtask deploy after do_compile
