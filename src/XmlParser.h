/*=======================================================
 Copyright (c) Peter Vasil, 2008
=======================================================*/


#ifndef _XMLPARSER_H_
#define _XMLPARSER_H_


class XmlParser : private DeletedAtShutdown
{
private:
	XmlParser();
	~XmlParser();
	
	void readConfig();
public:
	static const XmlParser& getInstance()
	{
		if ( m_instance == NULL )
		{
			m_instance = new XmlParser();
		}
		return *m_instance;
	}
	
	const String& getPicturePath() const
	{
		return m_picturePath;
	}
	
private:
	static XmlParser* m_instance;
	String m_picturePath;
};

#endif // _XMLPARSER_H_
