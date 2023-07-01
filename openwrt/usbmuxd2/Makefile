#
# Copyright (C) 2012-2014 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=usbmuxd2
PKG_VERSION:=1.0.0
PKG_RELEASE:=1
PKG_LIBC:=musl

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)

PKG_MAINTAINER:=tihmstar <tihmstar@gmail.com>
PKG_LICENSE:=GPL-3.0-or-later

PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1

PKG_BUILD_DEPENDS:=libgeneral

include $(INCLUDE_DIR)/package.mk

define Package/usbmuxd2
	SECTION:=util
	CATEGORY:=Utilities
	TITLE:=USB multiplexing daemon
	DEPENDS:=+librt +libusb-1.0 +libusbmuxd +libopenssl +libimobiledevice +libavahi-client +libgeneral
endef

define Package/usbmuxd2/description
	This daemon is in charge of multiplexing connections over USB to an iPhone or
	iPod touch. To users, it means you can sync your music, contacts, photos, etc.
	over USB. To developers, it means you can connect to any listening localhost
	socket on the device. usbmuxd is not used for tethering data transfer, which
	uses a dedicated USB interface as a virtual network device.
endef

CONFIGURE_ARGS += --with-systemd

define Build/Prepare
	rm -rf $(PKG_BUILD_DIR)
	$(CP) ./src $(PKG_BUILD_DIR)
endef

define Build/Configure
	( cd $(PKG_BUILD_DIR); ./autogen.sh );
	$(call Build/Configure/Default)
endef

define Package/usbmuxd2/install
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) ./files/usbmuxd2.init $(1)/etc/init.d/usbmuxd
	$(INSTALL_DIR) $(1)/usr/sbin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/sbin/usbmuxd $(1)/usr/sbin/usbmuxd
endef

$(eval $(call BuildPackage,usbmuxd2,+libgeneral))