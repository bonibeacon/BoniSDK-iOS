//
//  ViewController.h
//  Example
//
//  Created by Boni on 30.04.2014.
//  Copyright (c) 2014 Boni. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "BoniBeaconSDK/BoniBeaconManager.h"

@interface ViewController : UIViewController <UITableViewDataSource, UITableViewDelegate, BoniBeaconManagerDelegate>
@property (weak, nonatomic) IBOutlet UITableView *tableView;

@end
