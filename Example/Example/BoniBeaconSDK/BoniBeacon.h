//
//  BoniBeacon.h
//  BoniBeaconSDK
//
//  Created by Boni on 24.04.2014.
//  Copyright (c) 2014 Boni. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface BoniBeacon : NSObject

/**
 *  accuracy
 *
 *    Measured distance in meters from the boni beacon.
 *
 */
@property (nonatomic) CLLocationAccuracy accuracy;

/**
 *  major
 *
 *    The most significant value in the boni beacon.
 *
 */
@property (nonatomic, strong) NSNumber *major;

/**
 *  minor
 *
 *    The least significant value in the boni beacon.
 *
 */
@property (nonatomic, strong) NSNumber *minor;

/**
 *  proximity
 *
 *    The relative distance to the boni beacon.
 *
 */
@property (nonatomic) CLProximity proximity;

/**
 *  proximityUUID
 *
 *    The proximity ID of the boni beacon.
 *
 */
@property (nonatomic, strong) NSUUID *proximityUUID;

/**
 *  rssi
 *
 *    The received signal strength of the boni beacon, measured in decibels.
 *
 */
@property (nonatomic) NSInteger rssi;

@end
