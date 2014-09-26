//
//  BoniBeaconManager.h
//  BoniBeaconSDK
//
//  Created by Boni on 24.04.2014.
//  Copyright (c) 2014 Boni. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "BoniBeacon.h"
#import "BoniBeaconRegion.h"

#define BoniBeaconSDKVersion "v0.2"

@class BoniBeaconManager;

@protocol BoniBeaconManagerDelegate <NSObject>

@optional

/**
 * Tells the delegate that one or more boni beacons are in range.
 *
 * @param beaconManager boni beacon manager object reporting the event
 * @param beacons an array of BoniBeacon objects that currently in range
 * @param region boni beacon region object
 *
 * @return void
 */
- (void)boniBeaconManager:(BoniBeaconManager *)beaconManager
          didRangeBeacons:(NSArray *)beacons
                 inRegion:(BoniBeaconRegion *)region;

/**
 * Tells the delegate that nearest boni beacon in region.
 *
 * @param beaconManager boni beacon manager object reporting the event
 * @param beacon nearest BoniBeacon object in region
 * @param region boni beacon region object
 *
 * @return void
 */
- (void)boniBeaconManager:(BoniBeaconManager *)beaconManager
            nearestBeacon:(BoniBeacon *)beacon
                 inRegion:(BoniBeaconRegion *)region;

/**
 * Tells the delegate about the state of the specified region.
 *
 * @param beaconManager boni beacon manager object reporting the event
 * @param state state of the region
 * @param region boni beacon region object
 *
 * @return void
 */
- (void)boniBeaconManager:(BoniBeaconManager *)beaconManager
        didDetermineState:(CLRegionState)state
                forRegion:(BoniBeaconRegion *)region;

/**
 * Tells the delegate that an error occureed while ranging in region.
 *
 * @param beaconManager boni beacon manager object reporting the event
 * @param region boni beacon region object
 * @param error an error object
 *
 * @return void
 */
- (void)boniBeaconManager:(BoniBeaconManager *)beaconManager
rangingBeaconsDidFailForRegion:(BoniBeaconRegion *)region
                withError:(NSError *)error;


/**
 * Tells the delegate that an error occureed while monitoring in region.
 *
 * @param beaconManager boni beacon manager object reporting the event
 * @param region boni beacon region object
 * @param error an error object
 *
 * @return void
 */
- (void)boniBeaconManager:(BoniBeaconManager *)beaconManager
monitoringDidFailForRegion:(BoniBeaconRegion *)region
                withError:(NSError *)error;

/**
 * Tells the delegate that the user entered the specified region.
 *
 * @param beaconManager boni beacon manager object reporting the event
 * @param region boni beacon region object
 *
 * @return void
 */
- (void)boniBeaconManager:(BoniBeaconManager *)beaconManager
           didEnterRegion:(BoniBeaconRegion *)region;

/**
 * Tells the delegate that the user left the specified region.
 *
 * @param beaconManager boni beacon manager object reporting the event
 * @param region boni beacon region object
 *
 * @return void
 */
- (void)boniBeaconManager:(BoniBeaconManager *)beaconManager
            didExitRegion:(BoniBeaconRegion *)region;


/**
 * Tells the delegate that the authorization status.
 *
 * @param beaconManager boni beacon manager object reporting the event
 * @param status authorization status
 *
 * @return void
 */
- (void)boniBeaconManager:(BoniBeaconManager *)beaconManager
            didChangeAuthorizationStatus:(CLAuthorizationStatus)status;

@end

@interface BoniBeaconManager : NSObject <CLLocationManagerDelegate>

@property (nonatomic) id<BoniBeaconManagerDelegate> delegate;

/**
 * Starts the ranging boni beacons in the specified region.
 *
 * @param region boni beacon region object
 *
 * @return void
 */
- (void)startRangingBeaconsInRegion:(BoniBeaconRegion *)region;

/**
 * Stops the ranging boni beacons in the specified region.
 *
 * @param region boni beacon region object
 *
 * @return void
 */
- (void)stopRanginBeaconsInRegion:(BoniBeaconRegion *)region;

/**
 * Starts the monitoring boni beacons in the specified region.
 *
 * @param region boni beacon region object
 *
 * @return void
 */
- (void)startMonitoringBeaconsInRegion:(BoniBeaconRegion *)region;

/**
 * Stops the ranging boni beacons in the specified region.
 *
 * @param region boni beacon region object
 *
 * @return void
 */
- (void)stopMonitoringBeaconsInRegion:(BoniBeaconRegion *)region;

/**
 * Retrieves the state of a region asynchronously.
 *
 * @param region boni beacon region object
 *
 * @return void
 */
- (void)requestStateForRegion:(BoniBeaconRegion *)region;

/**
 * Start location updates. Continue ranged beacons if Background Mode is open.
 *
 */
- (void)startUpdatingLocation;

/**
 * Stop location updates.
 *
 */
- (void)stopUpdatingLocation;

/**
 *
 * When the current authorization status is kCLAuthorizationStatusNotDetermined, this method runs asynchronously
 * and prompts the user to grant permission to the app to use location services. The user prompt contains the text from the
 * NSLocationWhenInUseUsageDescription key in your app’s Info.plist file, and the presence of that key is required when
 * calling this method.
 */
- (void)requestWhenInUseAuthorization;

/**
 *
 * When the current authorization status is kCLAuthorizationStatusNotDetermined, this method runs asynchronously
 * and prompts the user to grant permission to the app to use location services. The user prompt contains the text from the
 * NSLocationAlwaysUsageDescription key in your app’s Info.plist file, and the presence of that key is required when
 * calling this method.
 */
- (void)requestAlwaysAuthorization;

/**
 *
 * The authorization status of a given app is managed by the system and determined by several factors.
 *
 * return A value indicating whether the app is authorized to use location services.
 */
+ (CLAuthorizationStatus)authorizationStatus;
@end
