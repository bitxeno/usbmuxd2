# cat package/libgeneral/Makefile
#
# Copyright (C) 2012-2014 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=libgeneral
PKG_VERSION:=1.0.0
PKG_RELEASE:=1
PKG_LIBC:=musl

PKG_MAINTAINER:=tihmstar <tihmstar@gmail.com>
PKG_LICENSE:=GPL-2.1

PKG_BUILD_PARALLEL:=1
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/libgeneral
	SECTION:=lib
  	CATEGORY:=Libraries
	TITLE:=libgeneral
	DEPENDS:=+libstdcpp
endef

define Package/libgeneral/description
  Libgeneral is (in its core) a collection of macros, which aid in employing a certain coding style used throughout my projects
endef

define Build/Prepare
	rm -rf $(PKG_BUILD_DIR)
	git clone https://github.com/tihmstar/libgeneral.git -b 64 $(PKG_BUILD_DIR)
endef

define Build/Configure
	( cd $(PKG_BUILD_DIR); ./autogen.sh);
	$(call Build/Configure/Default)
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DIR) $(1)/usr/lib/pkgconfig
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libgeneral.* $(1)/usr/lib/
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/pkgconfig/libgeneral*.pc $(1)/usr/lib/pkgconfig/
	$(CP) $(PKG_INSTALL_DIR)/usr/include/libgeneral $(1)/usr/include/libgeneral
endef

define Package/libgeneral/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libgeneral.so.* $(1)/usr/lib/
endef


$(eval $(call BuildPackage,libgeneral))
