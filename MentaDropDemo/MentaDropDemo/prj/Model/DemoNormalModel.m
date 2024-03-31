//
//  DemoNormalModel.m
//  MentaSDKExample
//
//  Created by iMacMe on 2024/1/8.
//

#import "DemoNormalModel.h"
#import <UIKit/UIKit.h>

@implementation DemoNormalModel
- (instancetype)initWithDict:(NSDictionary *)dict {
    self = [super init];
    if (self) {
        self.type = [dict valueForKey:@"type"];
        self.title = [dict valueForKey:@"title"];
        self.source = [dict valueForKey:@"source"];
        self.incon = [dict valueForKey:@"incon"];
        self.imgs = [dict valueForKey:@"imgs"];
        
        if ([self.type isEqualToString: @"title"]) {
            self.cellHeight = 100;
        }else if ([self.type isEqualToString: @"titleImg"]){
            self.cellHeight = 130;
        }else if ([self.type isEqualToString: @"bigImg"]){
            self.cellHeight = 100+[UIScreen mainScreen].bounds.size.width*0.6;
        }else if ([self.type isEqualToString: @"threeImgs"]){
            self.cellHeight = 196;
        }else{
            self.cellHeight = 0;
        }
        
    }
    return self;
}

@end
