/*==========================================================
 Copyright (c) Peter Vasil, 2008
 ==========================================================*/

#include "MyJuceApp_Headers.h"
#include "MainComponent.h"
#include "XmlParser.h"


MainComponent::MainComponent(DocumentWindow* mainWindow, ApplicationCommandManager* commandManager)
:
m_mainWindow(mainWindow),
m_commandManager(commandManager)
{
	//DBG_SCOPE();
	LOG_SCOPE();
	m_commandManager->registerAllCommandsForTarget(this);
	setApplicationCommandManagerToWatch(m_commandManager);
#if !defined(LINUX)
	setMacMainMenu(this);
#endif
	button1 = new TextButton(T("Button 1"));
	button1->addButtonListener(this);
	m_schalter = true;
	m_timerOn = false;
	m_text = T("Test");
	m_text2 = T("Test2");
	m_text2 = Time::getCurrentTime().toString(true, true, true, true);
	m_text2 = XmlParser::getInstance().getPicturePath();

	DBG_VAL(m_text2);
	m_zaehler = 0;
	hochZaehler();
//	m_zaehler;

}

MainComponent::~MainComponent()
{
#if !defined(LINUX)
	setMacMainMenu(0);
#endif
	deleteAllChildren();
}

void MainComponent::resized()
{
	button1->setBounds(getWidth() / 2 - 40, getHeight() - 100, 80, 30);
}

void MainComponent::paint(Graphics& g)
{
	//DBG_SCOPE();
	LOG_SCOPE();
	addAndMakeVisible(button1);
	g.fillAll(Colours::dimgrey);
	g.setFont(30);
	g.drawText(m_text, getWidth()/2 - 100, getHeight()/2 - 40, 200, 80, 4, false);
	g.setFont(20);
	g.drawText(m_text2, getWidth()/2 - 100, getHeight()/2 , 200, 80, 4, false);
	m_image = ImageCache::getFromFile(File(File::getCurrentWorkingDirectory().getChildFile(XmlParser::getInstance().getPicturePath())));
    m_image = ImageCache::getFromFile(File(XmlParser::getInstance().getPicturePath()));
	m_image = ImageCache::getFromFile(XmlParser::getInstance().getPicturePath());
	g.drawImageAt(m_image, 0, 0, false);
	ImageCache::release(m_image);
	DBG_VAL(m_text2);
	DBG_VAL(m_text);
}

void MainComponent::buttonClicked(Button* button)
{
	//DBG_SCOPE();
	LOG_SCOPE();
	if ( button == button1 )
	{
		if (m_timerOn)
		{
			stopTimer();
			m_text =String::empty;
			repaint();
			m_timerOn = false;
		}
		else
		{
			startTimer(500);
			m_timerOn = true;
		}

	}

	//LOG_VAL(button1->getName());
}

void MainComponent::timerCallback()
{
	LOG_SCOPE();
	//DBG_SCOPE();
	if (m_schalter)
	{
		m_text = T("Test");
		repaint();
		m_schalter = false;
	}
	else {
		m_text = String::empty;
		repaint();
		m_schalter = true;
	}
	//DBG_VAL(m_schalter);
	LOG_VAL(m_schalter);

}

void MainComponent::hochZaehler()
{
	for (int i = 0; i < 10; ++i)
	{
		m_zaehler += 3;
	}
}
