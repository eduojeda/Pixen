//
//  PXToolPaletteController.h
//  Pixen
//

#import <Foundation/NSObject.h>
#import <AppKit/NSNibDeclarations.h>
@class PXToolSwitcher, PXCanvasController;
@class NSButton, NSEvent, NSPanel;

@interface PXToolPaletteRightToolGradientView : NSImageView { }
@end

@interface PXToolPaletteController: NSWindowController
{
  @private
	IBOutlet PXToolSwitcher *leftSwitcher;
	IBOutlet PXToolSwitcher *rightSwitcher;
	IBOutlet id minimalView;
	IBOutlet NSBox *rightSwitchView;
	IBOutlet NSButton *triangle;
	IBOutlet NSImageView *rightToolGradient;
	
	BOOL _locked;
	BOOL usingRightToolBeforeLock;
	BOOL controlKeyDown;
	BOOL rightMouseDown;
	unsigned int keyMask;
}

//singleton
+(id) sharedToolPaletteController;

- (void)clearBeziers;

	//Action method
- (IBAction)disclosureClicked:(id)sender;

	//Events methods
- (void)keyDown:(NSEvent *)event fromCanvasController:(PXCanvasController *)cc;
- (BOOL)keyWasDown:(unsigned int)mask;
- (BOOL)isMask:(unsigned int)newMask upEventForModifierMask:(unsigned int)mask;
- (BOOL)isMask:(NSUInteger)newMask downEventForModifierMask:(unsigned int)mask;
- (void)flagsChanged:(NSEvent *)theEvent;

- (void)rightMouseDown;
- (void)rightMouseUp;
- (BOOL)usingRightTool;

	//Accessor methods
-(id) leftTool;
-(id) rightTool;
-(id) currentTool;
-(PXToolSwitcher *) leftSwitcher;
-(PXToolSwitcher *) rightSwitcher;
-(NSPanel *) toolPanel;

@end
