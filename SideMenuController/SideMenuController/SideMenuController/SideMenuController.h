//
//  SideMenuController.h
//  SideMenuController
//
//  Created by Vols on 14-9-2.
//  Copyright (c) 2014年 vols. All rights reserved.
//

#import <UIKit/UIKit.h>


typedef NS_ENUM(NSUInteger, MenuPanDirection) {
    MenuPanDirectionLeft = 0,
    MenuPanDirectionRight,
};

typedef NS_ENUM(NSUInteger, MenuSideDirection) {
    MenuDirectionLeft = 1 << 1,
    MenuDirectionRight = 1 << 2,
    MenuDirectionTop = 1 << 3,
    MenuDirectionBottom = 1 << 4,

    MenuDirectionNone = 0,
};

typedef NS_ENUM(NSUInteger, MenuPanCompletion) {
    MenuPanCompletionLeft = 0,
    MenuPanCompletionRight,
    MenuPanCompletionRoot,
};



@protocol SideMenuControllerDelegate;
@interface SideMenuController : UIViewController{
    
    CGFloat _panOriginX;
    CGPoint _panVelocity;
    MenuPanDirection _panDirection;
    
    struct {
        unsigned int respondsToWillShowViewController:1;
        unsigned int showingLeftView:1;
        unsigned int showingRightView:1;
        unsigned int canShowRight:1;
        unsigned int canShowLeft:1;
    } _menuFlags;
}

@property(nonatomic,strong) UIViewController *leftViewController;
@property(nonatomic,strong) UIViewController *rightViewController;
@property(nonatomic,strong) UIViewController *rootViewController;

@property(nonatomic,assign) id <SideMenuControllerDelegate> delegate;

@property(nonatomic,readonly) UITapGestureRecognizer *tap;
@property(nonatomic,readonly) UIPanGestureRecognizer *pan;

@property(nonatomic,assign) Class barButtonItemClass;


@property (nonatomic, assign) MenuSideDirection directionsToShowBounce;


- (id)initWithRootViewController:(UIViewController*)controller;

- (void)setRootController:(UIViewController *)controller animated:(BOOL)animated; // used to push a new controller on the stack
- (void)showRootController:(BOOL)animated; // reset to "home" view controller
- (void)showRightController:(BOOL)animated;     // show right
- (void)showLeftController:(BOOL)animated;      // show left

@end

@protocol SideMenuControllerDelegate

- (void)menuController:(SideMenuController *)controller willShowViewController:(UIViewController*)controller;

@end