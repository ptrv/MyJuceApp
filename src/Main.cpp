/*==========================================================
 Copyright (c) Peter Vasil, 2008
 ==========================================================*/

#include "MyJuceApp_Headers.h"
#include "MainAppWindow.h" 

//============================================================================== 
class AppClass : public JUCEApplication 
	{ 
		/* Important! NEVER embed objects directly inside your JUCEApplication class! Use 
		 ONLY pointers to objects, which you should create during the initialise() method 
		 (NOT in the constructor!) and delete in the shutdown() method (NOT in the 
		 destructor!) 
		 
		 This is because the application object gets created before Juce has been properly 
		 initialised, so any embedded objects would also get constructed too soon. 
		 */ 
		MainAppWindow* theMainWindow;
		
		ApplicationCommandManager* m_commandManager;
		
	public: 
		//============================================================================== 
		AppClass() 
        : theMainWindow (0),
		  m_commandManager(0)
		{ 
			// This is where the application itself is created. It's a bit like a shell, which 
			// all your real app stuff gets born into. At this point (where the app pops into 
			// being), Juce doesn't really 'exist' yet, so we can't do anything with it here. 
			// Once this application shell has been established, Juce will be awake so we can 
			// create instances of its classes willy-nilly. 
			
			// [Jules says...] 
			// NEVER do anything in here that could involve any Juce function being called 
			// - leave all your startup tasks until the initialise() method. 
		} 
		
		~AppClass() 
		{ 
			// This is where the application body is destroyed, and making any Juce calls in 
			// here could be very dangerous. 
			
			// Just as Juce wasn't awake when the shell was created, by this stage it's been 
			// tidied away and put to sleep. This is the bit that happens AFTER your program 
			// code has ended (and hopefully put all its toys away). 
			
			// [Jules says...] 
			// Your shutdown() method should already have done all the things necessary to 
			// clean up this app object, so you should never need to put anything in 
			// the destructor. 
		} 
		
		//============================================================================== 
		void initialise (const String& commandLine) 
		{ 
			// This is called automatically when the application is ready to launch. 
			// So far, it just exists in memory as an empty pocket of potential waiting 
			// to burst into life as a program. Nothing yet exists to act or be displayed. 
			
			// All we want to do here is create the main window. This instantiates an object 
			// of 'MainAppWindow' - which we have defined in MainAppWindow(.h/.cpp). The app's 
			// behaviour comes from that, so all we need is to bring it to life... 

			m_commandManager = new ApplicationCommandManager();
			theMainWindow = new MainAppWindow(m_commandManager);
			m_commandManager->registerAllCommandsForTarget(JUCEApplication::getInstance());
			theMainWindow->centreWithSize (800, 400);   // [*] (see below for a tip on this) 
			theMainWindow->setVisible (true); 
			
		} 
		
		void shutdown() 
		{ 
			// This gets called when the application is ready to shut down. 
			// Anything that we created in the initialise() function should be destroyed, 
			// so that nothing is left hanging around when the app shell ceases to exist. 
			
			// All we need to do here is delete the MainAppWindow we created... 
			deleteAndZero (theMainWindow);
			deleteAndZero(m_commandManager);
		} 
		
		//============================================================================== 
		const String getApplicationName() 
		{ 
			// The name for the application 
			return T("Juce tutorial application"); 
		} 
		
		const String getApplicationVersion() 
		{ 
			// Here we can give a 'version' indicator, to distinguish one build from 
			// another. If you update your program, it's a good idea to also update 
			// the string returned here. 
			return T("0.0"); 
		} 
		
		bool moreThanOneInstanceAllowed() 
		{ 
			// We can prevent multiple instances of the application here by returning false. 
			return true; 
		} 
		
		void anotherInstanceStarted (const String& commandLine) 
		{ 
			// This will get called if the user launches another copy of the application. 
		} 
	}; 


//============================================================================== 
// This macro creates the application's main() function.. 
START_JUCE_APPLICATION(AppClass) 
