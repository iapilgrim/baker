//
//  RootViewController.h
//  Baker
//
//  Created by Xmas on 10/22/07.
//  Copyright 2010 Xmas. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TapHandler;

@interface RootViewController : UIViewController < UIWebViewDelegate > {
		
	CGRect frameLeft;
	CGRect frameCenter;
	CGRect frameRight;
	
	UIWebView *prevPage;
	UIWebView *currPage;
	UIWebView *nextPage;
	
	UISwipeGestureRecognizer *swipeLeft;
	UISwipeGestureRecognizer *swipeRight;
	
	TapHandler *rightTapHandler;
	TapHandler *leftTapHandler;
	TapHandler *downTapHandler;
	TapHandler *upTapHandler;

	int currentPageNumber;
	BOOL currentPageIsLast;
	BOOL currentPageFirstLoading;
	BOOL currentPageIsAnimating;	
}

@property (nonatomic, retain) UIWebView *prevPage;
@property (nonatomic, retain) UIWebView *currPage;
@property (nonatomic, retain) UIWebView *nextPage;

@property (nonatomic, retain) UISwipeGestureRecognizer *swipeLeft;
@property (nonatomic, retain) UISwipeGestureRecognizer *swipeRight;

@property int currentPageNumber;

- (BOOL)loadNewPage:(UIWebView *)target
		   filename:(NSString *)filename
			   type:(NSString *)type
				dir:(NSString *)dir;

- (void)handleSingleTap:(NSNotification *)notification;

- (void)goUpInPage:(NSString *)offset animating:(BOOL)animating;
- (void)goDownInPage:(NSString *)offset animating:(BOOL)animating;
- (void)scrollPage:(NSString *)offset animating:(BOOL)animating;

- (void)swipePage:(UISwipeGestureRecognizer *)sender;
- (void)goToPrevPage;
- (void)goToNextPage;
- (void)animateHorizontalSlide:(NSString *)name
							dx:(int) dx
					 firstView:(UIWebView *)firstView
					secondView:(UIWebView *)secondView;
- (void)animationDidStop:(NSString *)animationID
					 finished:(BOOL)flag;

@end