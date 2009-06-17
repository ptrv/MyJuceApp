/*=======================================================
 Copyright (c) Peter Vasil, 2008
=======================================================*/

#ifndef _MAINCOMPONENT_H_ 
#define _MAINCOMPONENT_H_ 
//test7

class MainComponent  : public Component,
					   public MenuBarModel,
					   public ApplicationCommandTarget,
					   public ButtonListener,
					   public Timer
{ 
	enum CommandIDs
	{
		about     = 0x2000,  ///< Show about dialog.
	};
	
public: 
		//============================================================================== 
	MainComponent (DocumentWindow* mainWindow, ApplicationCommandManager* commandManager);
		
	~MainComponent ();
		//============================================================================== 
	juce_UseDebuggingNewOperator
	
	void resized ();
		
	void paint (Graphics& g);
	
	void buttonClicked (Button* button);
	
	void timerCallback();
	
	void hochZaehler();
	
	const StringArray getMenuBarNames()
	{
		const tchar* names[] = { T("Help"), 0 };
		
		return StringArray(names);
		
	}
	const PopupMenu getMenuForIndex (int menuIndex, const String& menuName)
	{
		DBG_SCOPE();
		DBG_VAL(menuIndex);
		DBG_VAL(menuName);
		
		PopupMenu menu;
		
		switch (menuIndex)
		{
			case 0:
				menu.addCommandItem(m_commandManager, about);
				break;
			default:
				break;
		}
		return menu;
		
	}
	void menuItemSelected (int menuItemID, int topLevelMenuIndex)
	{
	}
	ApplicationCommandTarget* getNextCommandTarget()
	{
		// this will return the next parent component that is an ApplicationCommandTarget (in this
		// case, there probably isn't one, but it's best to use this method in your own apps).
		return findFirstTargetParentComponent();
	}
	void getAllCommands (Array <CommandID>& commands)
	{
		// this returns the set of all commands that this target can perform..
		const CommandID ids[] = {
			about
		};
		
		commands.addArray(ids, numElementsInArray(ids));
	}
	void getCommandInfo (const CommandID commandID, ApplicationCommandInfo& result)
	{
		DBG_SCOPE();
		DBG_VAL(commandID);
		
		switch (commandID)
		{
			case about:
				result.setInfo(T("About MyJuceApp"), T("Displays information about MyJuceApp application"), T("Help"), 0);
				result.addDefaultKeypress(T('?'), ModifierKeys::commandModifier );
				break;
			default:
				break;
		}
		
	}
	bool perform (const InvocationInfo& info)
	{
		bool result = true;
		DBG_SCOPERET(bool, result);
		DBG_INFO((T("Received Command %04x, flags=%d, method=%d"), info.commandID, info.commandFlags, info.invocationMethod));
		
		switch(info.commandID)
		{
			case about:
			{
				String title = T("MyJuceApp");
				title += T(" Version ");
				title += T("1.0.0");
				String message = T("Peter Vasil");
				message += T(". All rights reserved.");
				AlertWindow::showMessageBox(AlertWindow::InfoIcon, title, message, T("OK"));
			}
				break;
			default:
				result = false;
				break;
		}
		return result;
		
	}
		
	//============================================================================== 
private: 
	//============================================================================== 
	DocumentWindow* m_mainWindow;
	ApplicationCommandManager* m_commandManager;
	TooltipWindow tooltipWindow;
	TextButton* button1;
	bool m_schalter;
	String m_text;
	bool m_timerOn;
	String m_text2;
	int m_zaehler;
	Image* m_image;
	
	//==============================================================================
	/// Prevent copy constructor being generated.
	MainComponent(const MainComponent&);
	/// Prevent operator= being generated.
	const MainComponent& operator=(const MainComponent&);
	
	
}; 

#endif//_MAINCOMPONENT_H_