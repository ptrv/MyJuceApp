/*==========================================================
 Copyright (c) Peter Vasil, 2008
 ==========================================================*/


#ifndef _MainAppWindow_H__
#define _MainAppWindow_H__

//#include "juce.h"

//==============================================================================
class MainAppWindow  : public DocumentWindow
	{
	public:
		//==============================================================================
		MainAppWindow(ApplicationCommandManager* commandManager);
		~MainAppWindow();

		//==============================================================================
		/// called when the close button is pressed or esc is pushed
		void closeButtonPressed();

		// It is most likely that your program will be happy thinking of the window's
		// content component as the 'base' level of the application; it can be responsible
		// for storing and maintaining anything considered crucial to the running of the
		// program.

		// However, if you want to have anything live above even that, you may
		// want to put it here. You may even wish to step further outside of things and keep
		// some higher management system within the JUCEApplication class that drives the
		// whole shebang, but that's probably not necessary, and can be tricky to maintain!
	};


#endif
