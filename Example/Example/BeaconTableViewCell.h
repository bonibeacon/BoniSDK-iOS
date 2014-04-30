//
//  BeaconTableViewCell.h
//  Example
//
//  Created by Boni on 29.04.2014.
//  Copyright (c) 2014 Boni. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BeaconTableViewCell : UITableViewCell

@property (weak, nonatomic) IBOutlet UILabel *labelMajor;
@property (weak, nonatomic) IBOutlet UILabel *labelMinor;
@property (weak, nonatomic) IBOutlet UILabel *labelRssi;

@end
