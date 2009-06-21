/*==========================================================
 Copyright (c) Peter Vasil, 2008
 ==========================================================*/

#include "MyJuceApp_Headers.h"
#include "XmlParser.h"

//using namespace juce;
static const String& configFile(T("../data/MyJuceAppConfig.xml"));

XmlParser* XmlParser::m_instance = 0;

XmlParser::XmlParser()
{
	readConfig();
}

XmlParser::~XmlParser()
{
}

void XmlParser::readConfig()
{
	XmlDocument* xmlConfigDoc = new XmlDocument(File(File::getCurrentWorkingDirectory().getChildFile(configFile)));
	XmlElement* xmlConfigElem = xmlConfigDoc->getDocumentElement();
	if (xmlConfigElem != NULL) 
	{
		XmlElement* pictures = xmlConfigElem->getChildByName(T("pictures"));
		if (pictures != NULL) 
		{
			if (pictures->hasAttribute(T("path"))) 
			{
				m_picturePath = pictures->getStringAttribute(T("path"));
			}
			else 
			{
				LOG_ERROR(T("Element \"pictures\" is incomplete"));
			}

		}
		else 
		{
			LOG_ERROR(T("Element \"pictures\" not found"));
		}
		delete xmlConfigElem;

	}
	else
	{
		LOG_ERROR((T("XML load failed: %ls"), (const juce_wchar*)xmlConfigDoc->getLastParseError()));
	}
	delete xmlConfigDoc;
}
