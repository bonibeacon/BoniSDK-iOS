BoniSDK-iOS
===========

Boni Beacon SDK for iOS devices.

Overview
-------

BoniBeaconManager is main class of the library. It contains monitoring and ranging methods in the specified region.
BoniBeaconRegion is subclass of CLBeaconRegion class. This helps to create specified regions to range or monitor Boni Beacons.
BoniBeacon reflects Boni Beacon device that are in region. 

Installation
-------

1. Copy libBoniBeaconSDK.a file and BoniBeaconHeaders folder to your project.
2. Add libBoniBeaconSDK.a file to Link Library in Build Phases. Additonally, add following frameworks to your project:
    * CoreBluetooth.framework
    * CoreLocation.framework
