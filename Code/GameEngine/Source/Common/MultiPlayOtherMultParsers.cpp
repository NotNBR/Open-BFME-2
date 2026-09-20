// cl: /O1 /DNDEBUG /MD /EHsc
// BFME1 MultiPlayMultParseCallbacks.cpp donor, adapted to PC GlobalData.
// Named PC FieldParse rows VA 0xBE9C20..0xBE9C50 all pass GlobalData+0xEC4.
// INI colon separators are +0x420; scanReal is thiscall here.
// The four array setters are out of line in PC, unlike the money parser.
// Xbox schemas corroborate roles only; PC bytes and complete ranges are proof.
// MultiPlayMults is a descriptive donor facade, not a recovered type spelling.
typedef int Int;
typedef float Real;

extern "C" __declspec(dllimport) int __cdecl _strcmpi( const char *, const char * );

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/Common/INI.h
class INI
{
public:
	const char *getNextToken( const char *seps );
	const char *getNextTokenOrNull( const char *seps );
	const char *getSepsColon( void ) const { return m_sepsColon; }
	Real scanReal( const char *token );

	char m_unreconstructed_000[ 0x420 ];
	const char *m_sepsColon;
};

class MultiPlayMults
{
public:
	void setMoneyMult( Int slot, Real value );

	void setUnitXPMult( Int slot, Real value );

	void setBuildingXPMult( Int slot, Real value );

	void setUnitSpeedMult( Int slot, Real value );

	void setBuildingSpeedMult( Int slot, Real value );

	// PC twenty-slot arrays: +0, +0x50, +0xA0, +0xF0, +0x140.
	Real m_money[ 20 ];
	Real m_unitXP[ 20 ];
	Real m_buildingXP[ 20 ];
	Real m_unitSpeed[ 20 ];
	Real m_buildingSpeed[ 20 ];
};

void parseMultiPlayUnitXPMult( INI *ini, void *, void *store, const void * )
{
	MultiPlayMults *mults = (MultiPlayMults *)store;
	const char *token = ini->getNextTokenOrNull( ini->getSepsColon() );
	while ( token )
	{
		const char *valueToken = ini->getNextToken( ini->getSepsColon() );
		if ( valueToken )
		{
			Real value = ini->scanReal( valueToken );
			if ( !_strcmpi( token, "MP1" ) )
				mults->setUnitXPMult( 1, value );
			else if ( !_strcmpi( token, "MP2" ) )
				mults->setUnitXPMult( 2, value );
			else if ( !_strcmpi( token, "MP3" ) )
				mults->setUnitXPMult( 3, value );
			else if ( !_strcmpi( token, "MP4" ) )
				mults->setUnitXPMult( 4, value );
			else if ( !_strcmpi( token, "MP5" ) )
				mults->setUnitXPMult( 5, value );
			else if ( !_strcmpi( token, "MP6" ) )
				mults->setUnitXPMult( 6, value );
			else if ( !_strcmpi( token, "MP7" ) )
				mults->setUnitXPMult( 7, value );
			else if ( !_strcmpi( token, "MP8" ) )
				mults->setUnitXPMult( 8, value );

			token = ini->getNextTokenOrNull( ini->getSepsColon() );
		}
	}
}

void parseMultiPlayBuildingXPMult( INI *ini, void *, void *store, const void * )
{
	MultiPlayMults *mults = (MultiPlayMults *)store;
	const char *token = ini->getNextTokenOrNull( ini->getSepsColon() );
	while ( token )
	{
		const char *valueToken = ini->getNextToken( ini->getSepsColon() );
		if ( valueToken )
		{
			Real value = ini->scanReal( valueToken );
			if ( !_strcmpi( token, "MP1" ) )
				mults->setBuildingXPMult( 1, value );
			else if ( !_strcmpi( token, "MP2" ) )
				mults->setBuildingXPMult( 2, value );
			else if ( !_strcmpi( token, "MP3" ) )
				mults->setBuildingXPMult( 3, value );
			else if ( !_strcmpi( token, "MP4" ) )
				mults->setBuildingXPMult( 4, value );
			else if ( !_strcmpi( token, "MP5" ) )
				mults->setBuildingXPMult( 5, value );
			else if ( !_strcmpi( token, "MP6" ) )
				mults->setBuildingXPMult( 6, value );
			else if ( !_strcmpi( token, "MP7" ) )
				mults->setBuildingXPMult( 7, value );
			else if ( !_strcmpi( token, "MP8" ) )
				mults->setBuildingXPMult( 8, value );

			token = ini->getNextTokenOrNull( ini->getSepsColon() );
		}
	}
}

void parseMultiPlayUnitSpeedMult( INI *ini, void *, void *store, const void * )
{
	MultiPlayMults *mults = (MultiPlayMults *)store;
	const char *token = ini->getNextTokenOrNull( ini->getSepsColon() );
	while ( token )
	{
		const char *valueToken = ini->getNextToken( ini->getSepsColon() );
		if ( valueToken )
		{
			Real value = ini->scanReal( valueToken );
			if ( !_strcmpi( token, "MP1" ) )
				mults->setUnitSpeedMult( 1, value );
			else if ( !_strcmpi( token, "MP2" ) )
				mults->setUnitSpeedMult( 2, value );
			else if ( !_strcmpi( token, "MP3" ) )
				mults->setUnitSpeedMult( 3, value );
			else if ( !_strcmpi( token, "MP4" ) )
				mults->setUnitSpeedMult( 4, value );
			else if ( !_strcmpi( token, "MP5" ) )
				mults->setUnitSpeedMult( 5, value );
			else if ( !_strcmpi( token, "MP6" ) )
				mults->setUnitSpeedMult( 6, value );
			else if ( !_strcmpi( token, "MP7" ) )
				mults->setUnitSpeedMult( 7, value );
			else if ( !_strcmpi( token, "MP8" ) )
				mults->setUnitSpeedMult( 8, value );

			token = ini->getNextTokenOrNull( ini->getSepsColon() );
		}
	}
}
