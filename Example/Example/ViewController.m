//
//  ViewController.m
//  Example
//
//  Created by Boni on 30.04.2014.
//  Copyright (c) 2014 Boni. All rights reserved.
//

#import "ViewController.h"
#import "BoniBeaconSDK/BoniBeaconManager.h"
#import "BeaconTableViewCell.h"

#warning define your own uuid!
#define BONI_UUID @"YOUR-BONI-BEACON_UUID"

@interface ViewController ()

@property (nonatomic, strong) BoniBeaconManager *boniBeaconManager;
@property (nonatomic, strong) BoniBeaconRegion *region;
@property (nonatomic, strong) NSMutableArray *beacons;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.tableView.dataSource = self;
    self.tableView.delegate = self;
    
    self.beacons = [[NSMutableArray alloc]init];
    self.boniBeaconManager = [[BoniBeaconManager alloc]init];
    self.boniBeaconManager.delegate = self;
    
    self.region = [[BoniBeaconRegion alloc]initWithProximityUUID:[[NSUUID alloc]initWithUUIDString:BONI_UUID] identifier:@"region"];
    
    [self.boniBeaconManager startRangingBeaconsInRegion:self.region];
    [self.boniBeaconManager requestAlwaysAuthorization];
}

- (void)boniBeaconManager:(BoniBeaconManager *)beaconManager didRangeBeacons:(NSArray *)beacons inRegion:(BoniBeaconRegion *)region{
    [self.beacons removeAllObjects];
    [self.beacons addObjectsFromArray:beacons];
    [self.tableView reloadData];
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [self.beacons count];
}


- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    BeaconTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"beaconcell" forIndexPath:indexPath];
    
    BoniBeacon *beacon = [self.beacons objectAtIndex:indexPath.row];
    
    [cell.labelMajor setText:[NSString stringWithFormat:@"%d",[beacon.major integerValue]]];
    [cell.labelMinor setText:[NSString stringWithFormat:@"%d",[beacon.minor integerValue]]];
    [cell.labelRssi setText:[NSString stringWithFormat:@"%d",beacon.rssi]];
    
    return cell;
}


@end
