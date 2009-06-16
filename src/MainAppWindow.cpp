/*==========================================================
 Copyright (c) Peter Vasil, 2008
 ==========================================================*/

#include "MyJuceApp_Headers.h"
#include "MainAppWindow.h" 
#include "MainComponent.h" 

//============================================================================== 
MainAppWindow::MainAppWindow(ApplicationCommandManager* commandManager) 
:    
// Initialise the base 'DocumentWindow'... 
DocumentWindow ( T("MyJuceApp"),
				Colours::lightgrey, 
				DocumentWindow::allButtons,
				true
				) 
{ 
    setResizable (true, false); // resizability is a property of ResizableWindow, which is 
	
	setTitleBarHeight (25);      // Set the height of the titlebar on our window. 
	
	MainComponent* contentComponent = new MainComponent (this, commandManager);
	
	
    setContentComponent (contentComponent);
	//setMenuBar(contentComponent);
	//setMenuBar(setMacMainMenu(contentComponent));
	
} 

MainAppWindow::~MainAppWindow() 
{ 
    setMenuBar(0);
	
	setContentComponent(0, true);
} 

void MainAppWindow::closeButtonPressed() 
{ 
	JUCEApplication::getInstance()->systemRequestedQuit(); 
} 