//
//  WIFIDeviceManager.cpp
//  usbmuxd2
//
//  Created by tihmstar on 15.01.22.
//

#include "WIFIDeviceManager.hpp"
#include <libgeneral/macros.h>
#   ifdef HAVE_WIFI_AVAHI
#       include "WIFIDeviceManager-avahi.hpp"
#   elif HAVE_WIFI_MDNS
#       include "WIFIDeviceManager-mDNS.hpp"
#   endif //HAVE_AVAHI

gref_WIFIDeviceManager::gref_WIFIDeviceManager(WIFIDeviceManager *mgr)
: _mgr(mgr)
{
    //
}

gref_WIFIDeviceManager::~gref_WIFIDeviceManager(){
#if defined(HAVE_WIFI_AVAHI) || defined(HAVE_WIFI_MDNS)
    _mgr->_finalUnrefEvent.notifyAll();
#endif
}

WIFIDeviceManager *gref_WIFIDeviceManager::operator->(){
    return _mgr;
}
